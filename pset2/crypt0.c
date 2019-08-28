#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
	char salt[] = "50"; /* This should be random */

	/* Read in the user's password and encrypt it. */
	char *password = crypt(get_string("Password:"), salt);

	/* Print the results. */
	printf("%s\n", password);

	return 0;
}