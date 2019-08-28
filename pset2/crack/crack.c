#include <cs50.h>
#include <crypt.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc == 2)      //Checks if the command-line has two arguments
    {

        char *k = argv[1];          //Define a variable that takes the hashed password
        int a = strlen(argv[1]);    //Define a variable that takes the length of the hashed password
        bool l;
        char salt[] = {k[0], k[1]}; //Define a variable that takes the "salt" from the hashed password

        printf("%s\n", salt);       //Prints the "salt"

        //Checks if all the characters of the hashed password is alphanumeric or '.' or '/'
        for (int i = 0; ((l = isalnum(k[i])) || (k[i] == '.') || (k[i] == '/')) && (i < (a - 1)); i++)
        {
            //printf(":)\n");
        }

        char *pass = crypt(salt, k);

       int result = strcmp(pass, k) == 0;

        printf("%i\n", result);

        return 0;
    }

    else
    {
        printf("hash\n");

        return 1;
    }
}