import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    stocks = db.execute("SELECT * FROM portfolio WHERE id=:id", id=session['user_id'])

    money = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

    total = float(money[0]["cash"])

    grand_total = total

    if stocks != []:
        for stock in stocks:
            symbol = str(stock['symbol'])
            quote = lookup(symbol)
            name = str(stock['name'])
            share = int(stock['shares'])
            price = float(quote['price'])
            cost = float(stock['cost'])
            grand_total += cost

        return render_template("index.html", stocks=stocks, symbol=symbol, name=name, quote=quote, shares=share, price=price, cost=cost, total=total, grand_total=round(grand_total, 2))
    else:
        return render_template("index.html", total=total, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # symbol of stock user would like to buy
        quote = lookup(request.form.get("symbol"))

        # check if symbol is valid, aplogize of not or if blank
        if quote == None:
            return apology("must provide stocks' symbol", 400)

        # keep track of cash current user has
        cash = db.execute("SELECT cash FROM users WHERE id=:id", id=session['user_id'])

        # confirm shares were entered
        shares = request.form.get("shares")
        if not shares:
            return apology("must provide number of shares", 400)

        # check that number of shares user entered is an integer
        if not shares.isdigit():
            return apology("shares should be a positive integer", 400)
        else:
            shares = float(request.form.get("shares"))

        # render an apology if the input is not a positive integer
        if shares <= 0:
            return apology("shares must be a posative integer", 400)

        # cost of once unit of stock
        price = quote["price"]

        name = quote["name"]

        # cost of total transaction
        cost = shares * price

        # amount of cash user will have left after transaction
        cash_updated = round(cash[0]['cash'] - cost, 2)

        # check if user has enough cash for transaction
        if cash_updated < 0:
            return apology("You don't have enough cash", 400)

        # log transaction into purchases table
        portfolio = db.execute("INSERT INTO portfolio (id, symbol, name, shares, price, cost) VALUES (:id, :symbol, :name, :shares, :price, :cost)",
                               id=session['user_id'], symbol=quote["symbol"], name=name, shares=shares, price=price, cost=cost)

        history = db.execute("INSERT INTO history (id, symbol, name, shares, price, cost) VALUES (:id, :symbol, :name, :shares, :price, :cost)",
                             id=session['user_id'], symbol=quote["symbol"], name=name, shares=shares, price=price, cost=cost)

        # update cash for user
        update_cash = db.execute("UPDATE users SET cash = :cash_updated WHERE id=:id",
                                 cash_updated=cash_updated, id=session['user_id'])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/wallet", methods=["GET", "POST"])
@login_required
def wallet():
    """Add cash to wallet"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        money = request.form.get("money")
        if not money.isdigit():
            return apology("must enter a number!", 400)

        money = float(money)

        if money < 0:
            return apology("must enter positive integer", 400)

        cash = db.execute("SELECT cash FROM users WHERE id = :id",
                          id=session["user_id"])

        update_wallet = db.execute("UPDATE users SET cash = :cash WHERE id = :id",
                                   id=session["user_id"], cash=cash[0]["cash"] + money)

        return redirect("/")
    else:
        return render_template("wallet.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""

    if request.method == "GET":

        username = request.args.get("username")

        rows = db.execute("SELECT username FROM users")

        if len(username) < 1:
            return jsonify(False)
        for row in rows:
            if row["username"] == username:
                return jsonify(False)
        else:
            return jsonify(True)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    stocks = db.execute("SELECT * FROM history WHERE id=:id", id=session['user_id'])

    money = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

    total = float(money[0]["cash"])

    for stock in stocks:
        symbol = str(stock['symbol'])
        quote = lookup(symbol)
        name = str(stock['name'])
        share = int(stock['shares'])
        price = float(stock['price'])
        cost = float(stock['cost'])
        date = stock["date"]

    return render_template("history.html", stocks=stocks, symbol=symbol, name=name, quote=quote, shares=share, price=price, cost=cost, total=total, date=date)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":

        return render_template("quote.html")

    if request.method == "POST":

        symbol = request.form.get("symbol")
        quote = lookup(request.form.get("symbol"))

        if not symbol:
            return apology("must provide stocks' symbol", 400)

        if quote == None:
            return apology("that stock doesn't exist!", 400)

        return render_template("quoted.html", company=quote['name'], symbol=quote['symbol'], value=usd(quote['price']))


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        user = request.form.get("username")
        rows = db.execute("SELECT username FROM users WHERE username=:user", user=user)
        # Ensure username does not exist
        for row in rows:
            if user == row["username"]:
                return apology("username already exists", 400)

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure both passwords match
        elif not request.form.get("confirmation"):
            return apology("must confirm password", 400)

        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        # Add user to database
        rows = db.execute("INSERT INTO users (username, hash) VALUES (:username, :password)", username=request.form.get("username"),
                          password=generate_password_hash(request.form.get("password")))

        # Remember which user has logged in
        session["user_id"] = session.get("user_id")

        # Redirect user to his home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    elif request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # symbol of stock user would like to buy
        quote = lookup(request.form.get("symbol"))

        # check if symbol is valid, aplogize of not or if blank
        if quote == None:
            return apology("must provide stocks' symbol", 400)

        # keep track of cash current user has
        cash = db.execute("SELECT cash FROM users WHERE id=:id", id=session['user_id'])
        original_shares = db.execute("SELECT shares FROM portfolio WHERE id= :id", id=session["user_id"])

        # confirm shares were entered
        shares = request.form.get("shares")
        if not shares:
            return apology("must provide number of shares", 400)

        # check that number of shares user entered is an integer
        if not shares.isdigit():
            return apology("shares should be a positive integer", 400)
        else:
            shares = float(request.form.get("shares"))

        # render an apology if the input is not a positive integer
        if shares <= 0:
            return apology("shares must be a posative integer", 400)

        if int(original_shares[0]["shares"]) < shares:
            return apology("cannot sell more than you have!", 400)

        # cost of once unit of stock
        price = quote["price"]

        # cost of total transaction
        cost = shares * price

        # amount of cash user will have left after transaction
        cash_updated = round(cash[0]['cash'] + cost, 2)

        # log transaction into portfolio table
        portfolio = db.execute("UPDATE portfolio SET shares = :shares AND cost = :cost WHERE id = :id AND symbol = :symbol",
                               id=session['user_id'], symbol=quote["symbol"], shares=original_shares[0]["shares"] - shares, cost=-cost)

        history = db.execute("INSERT INTO history (id, symbol, shares, price, cost) VALUES (:id, :symbol, :shares, :price, :cost)",
                             id=session['user_id'], symbol=quote["symbol"], shares=-shares, price=-price, cost=-cost)

        # update cash for user
        update_cash = db.execute("UPDATE users SET cash = :cash_updated WHERE id=:id",
                                 cash_updated=cash_updated, id=session['user_id'])

        # Redirect user to home page
        return redirect("/")

    if request.method == "GET":

        stocks = db.execute("SELECT symbol FROM portfolio WHERE id = :id", id=session["user_id"])

        for stock in stocks:
            symbol = str(stock['symbol'])

        return render_template("sell.html", stocks=stocks, symbol=symbol)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
