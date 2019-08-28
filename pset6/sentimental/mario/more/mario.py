from cs50 import get_int

# Prompt the user to input a non-negative integer no greater than 24
while True:
    n = get_int("Height = ")
    if n >= 0 and n <= 23:
        break
# We define 'i' as the height of the pyramid
for i in range(n):

    # We define 's1' as the amount of spaces printed on the left
    for s1 in range(n - i - 1):
        print(" ", end="")

    # We define 'h1' as the amount of hashes printed right after the spaces printed before
    for h1 in range(i + 1):
        print("#", end="")

    # We print two spaces between the left and right side of the pyramid
    print("  ", end="")

    # We define 'h2' as the amount of hashes printed right after the two spaces that separate the right and left side of the pyramid
    for h2 in range(i + 1):
        print("#", end="")

    # We create a new line each time we print both sides of the pyramid
    print()