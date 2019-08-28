from cs50 import get_string
import sys

# Converts into an integer the value entered as a key in the command-line
k = int(sys.argv[1])

# Checks if the key is greater than zero
if k > 0:

    # Prompts the user to enter the text that wants ciphered
    s = get_string("plaintext: ")
    print("ciphertext: ", end="")

    # Iterates over every character in the string
    for i in s:

        # Checks if the character is a character from the alphabet
        if i.isalpha():

            # Checks if the character is lowercase
            if i.islower():

                # Checks if when we add the character and the key, the value is greater than the one from the 'z', if it is, it wraps around back to 'a'
                if (ord(i) + k) > ord('z'):
                    j = (ord(i) - 97 + k) % 26
                    print(chr(j + 97), end="")

                # Prints the character plus the key
                else:
                    print(chr(ord(i) + k), end="")

            # Checks if the character is uppercase
            elif i.isupper():

                # Checks if when we add the character and the key, the value is greater than the one from the 'Z', if it is, it wraps around back to 'A'
                if (ord(i) + k) > ord('Z'):
                    j = (ord(i) - 65 + k) % 26
                    print(chr(j + 65), end="")

                # Prints the character plus the key
                else:
                    print(chr(ord(i) + k), end="")

        # If the character is not from the alphabet, it is printed just as is
        else:
            print(i, end="")
    print()

