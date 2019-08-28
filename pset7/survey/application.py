import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    if not request.form.get("name"):
        return render_template("error.html", message="You must provide your name!")
    elif not request.form.get("email"):
        return render_template("error.html", message="You must provide your email!")
    elif not request.form.get("team"):
        return render_template("error.html", message="You must select your favourite team!")
    elif not request.form.get("position"):
        return render_template("error.html", message="You must select your preferred position!")
    with open("survey.csv", "a") as file:
        writer = csv.DictWriter(file, fieldnames=["name", "email", "team", "position"])
        writer.writerow({"name": request.form.get("name"), "email": request.form.get("email"),
                         "team": request.form.get("team"), "position": request.form.get("position")})
    return render_template("sheet.html")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.DictReader(file, fieldnames=["name", "email", "team", "position"])
        applicants = list(reader)
    return render_template("sheet.html", applicants=applicants)
