from cs50 import get_int

while True:
    n = get_int("Number: ")
    if n > 0:
        break

if n <= 10**12 or n >= 10**16:
    print("INVALID")

i = 1
j = 1
result = 0

for countodd in range(8):
    odd = (((n % (100 * i)) - (n % (10 * i))) / (10 * i))
    i *= 100
    odd *= 2
    if odd >= 10:
        odd = 1 + (odd % 10)
    result += odd

for counteven in range(8):
    even = (((n % (10 * j)) - (n % j)) / j)
    j *= 100
    result += even

k = 10**13
l = 10**14

if result % 10 == 0:
    # For AMEX
    if n > 10**14 and n < 10**15:
        a = (((n % (100 * k)) - (n % (10 * k))) / (10 * k))
        a = a * 10
        b = (((n % (10 * k)) - (n % k)) / k)
        index = a + b
        if index == 34 or index == 37:
            print("AMEX")
        else:
            print("INVALID")

    if n > 10**15 and n < 10**16:
        a = (((n % (100 * l)) - (n % (10 * l))) / (10 * l))
        a = a * 10
        b = (((n % (10 * l)) - (n % l)) / l)
        index = a + b

        # For MasterCard
        if index == 51 or index == 52 or index == 53 or index == 54 or index == 55:
            print("MASTERCARD")

        # For Visa
        if a == 40:
            print("VISA")
        else:
            print("INVALID")
