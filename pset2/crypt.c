#define _XOPEN_SOURCE
#include <cs50.h>
#include <crypt.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    
    const char *key =
    
    char *crypt(const char *key, const char *salt);
    {
        string key = get_string("key: ");
        string salt = get_string("salt: ");

        printf("%s\n", crypt);
    }

}
