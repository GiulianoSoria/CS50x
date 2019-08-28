#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    //The program checks that command-line has two words written in it
    if (argc == 2)
    {

        string k = argv[1];
        int x = strlen(argv[1]);
        bool l;

        //It checks if each of the characters of the key is from the alphabet
        for (int y = 0; (l = isalpha(k[y])) && (y < (x - 1)); y++)
        {

        }

        //If the condition presented above is true, it continues running the program
        if (l == true)
        {

            string p = get_string("plaintext: ");                                   //Asks the user for the text to be ciphered
            printf("ciphertext: ");


            for (int i = 0, j = 0, n = strlen(p), m = strlen(k); i < n; i++)        //This is how it cycles from character to character of the plaintext
            {

                if (j >= m)
                {
                    j = j - m;                                                      //This is how the program goes back to the first character of the keyword

                    if (isupper(p[i]))                                              //Checks if the character in the ith position of the plaintext is uppercase
                    {
                        if (isupper(k[j]))                                          //Checks if the character in the jth position of the keyword is uppercase
                        {
                            printf("%c", (((p[i] - 65) + (k[j] - 65)) % 26) + 65);  //Prints out the ciphered character
                            j++;                                                    //This operation helps to work with the next character of the keyword
                        }

                        else if (islower(k[j]))
                        {
                            printf("%c", (((p[i] - 65) + (k[j] - 97)) % 26) + 65);
                            j++;
                        }
                    }

                    else if (islower(p[i]))
                    {
                        if (isupper(k[j]))
                        {
                            printf("%c", (((p[i] - 97) + (k[j] - 65)) % 26) + 97);
                            j++;
                        }

                        else if (islower(k[j]))
                        {
                            printf("%c", (((p[i] - 97) + (k[j] - 97)) % 26) + 97);
                            j++;
                        }
                    }

                    else
                    {
                        printf("%c", p[i]);
                    }

                }

                else
                {
                    if (isupper(p[i]))
                    {
                        if (isupper(k[j]))
                        {
                            printf("%c", (((p[i] - 65) + (k[j] - 65)) % 26) + 65);
                            j++;
                        }

                        else if (islower(k[j]))
                        {
                            printf("%c", (((p[i] - 65) + (k[j] - 97)) % 26) + 65);
                            j++;
                        }
                    }

                    else if (islower(p[i]))
                    {
                        if (isupper(k[j]))
                        {
                            printf("%c", (((p[i] - 97) + (k[j] - 65)) % 26) + 97);
                            j++;

                        }

                        else if (islower(k[j]))
                        {
                            printf("%c", (((p[i] - 97) + (k[j] - 97)) % 26) + 97);
                            j++;
                        }
                    }

                    else
                    {
                        printf("%c", p[i]);
                    }
                }
            }
            printf("\n");
        }

        else
        {
            return 1;
        }
    }

    else
    {
        return 1;
    }
}