from cs50 import get_string
import sys

j = sys.argv[1]
x = len(sys.argv[1])


for y in j:
    if y.isalpha() == True:
        l = True
    else:
        l = False

if l:
    p = get_string("plaintext: ")
    print("ciphertext: ", end="")

    n = len(p)
    m = len(j)
    a = 0
    counter = 0

    for i in p:
        if a >= m:
            a = a - m

            if i.isupper():
                if j[a].isupper():

                    print(chr((((ord(i) - 65) + (ord(j[a]) - 65)) % 26) + 65), end="")
                    a += 1

                elif j[a].islower():

                    print(chr((((ord(i) - 65) + (ord(j[a]) - 97)) % 26) + 65), end="")
                    a += 1

            elif i.islower():
                if j[a].isupper():

                    print(chr((((ord(i) - 97) + (ord(j[a]) - 65)) % 26) + 97), end="")
                    a += 1

                elif j[a].islower():

                    print(chr((((ord(i) - 97) + (ord(j[a]) - 97)) % 26) + 97), end="")
                    a += 1

            else:

                print(i, end="")

        else:
            if i.isupper():
                if j[a].isupper():

                    print(chr((((ord(i) - 65) + (ord(j[a]) - 65)) % 26) + 65), end="")
                    a += 1

                elif j[a].islower():

                    print(chr((((ord(i) - 65) + (ord(j[a]) - 97)) % 26) + 65), end="")
                    a += 1

            elif i.islower():
                if j[a].isupper():

                    print(chr((((ord(i) - 97) + (ord(j[a]) - 65)) % 26) + 97), end="")
                    a += 1

                elif j[a].islower():

                    print(chr((((ord(i) - 97) + (ord(j[a]) - 97)) % 26) + 97), end="")
                    a += 1

            else:

                print(i, end="")

    print()
    sys.exit(0)

else:
    sys.exit(1)
