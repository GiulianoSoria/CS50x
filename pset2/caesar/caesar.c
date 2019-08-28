#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //Converts the key from a character to a integer
        int k = atoi(argv[1]);

        if (k > 0)
        {
            //Prompts the user for the input text
            string s = get_string ("plaintext: ");
            printf("ciphertext: ");

            for (int i = 0, n = strlen(s); i < n; i++)
            {
                //Checks if the character is an alphabet letter
                if (isalpha(s[i]))
                {
                    int j;

                    //Checks if the character is lowercase
                    if (islower(s[i]))
                    {
                        if (s[i] + k > 'z')
                        {
                            j = (s[i] - 97 + k) % 26;
                            printf("%c", j + 97);
                        }
                        else
                        {
                            printf("%c", (s[i] + k));
                        }
                    }

                    //Checks if the character is uppercase
                    else if (isupper(s[i]))
                    {
                        if (s[i] + k > 'Z')
                        {
                            j = (s[i] - 65 + k) % 26;
                            printf("%c", j + 65);
                        }
                        else
                        {
                            printf("%c", (s[i] + k));
                        }
                    }
                }
                //If it is another character, it prints the same
                else
                {
                    printf("%c", s[i]);
                }
                }
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }

    //Prints the error
    else
    {
        return 1;
    }
}