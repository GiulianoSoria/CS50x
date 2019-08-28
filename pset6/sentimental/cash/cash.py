from cs50 import get_float

# Prompt the user to input the amount of money that is owed
while True:
    # Convert the change into cents and round it up
    n = get_float("Change owed: ")
    n *= 100
    n = round(n)

    if n >= 0:
        break

# Declare a counter of the amount of coins that need to be returned
a = 0

# If the change if greater or equal to a quarter (25 cents)
while n >= 25:
    n -= 25
    a = a + 1

# If the change if greater or equal to a dime (10 cents)
while n >= 10:
    n -= 10
    a = a + 1

# If the change if greater or equal to a nickel (5 cents)
while n >= 5:
    n -= 5
    a = a + 1
# If the change if greater or equal to a penny (1 cent)
while n >= 1:
    n -= 1
    a = a + 1

print(a)