#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    {

        do
        {
            n = get_int("Height = ");
        }
        while ((n < 0) || (n > 23));

        for (int i = 0; i < n ; i++)
        {
            for (int s = 1; s < (n - i); s++)
            {
                printf(" ");
            }
            for (int h1 = 1; h1 <= (i + 1); h1++)
            {
                printf("#");
            }
            printf("  ");
            for (int h2 = 1; h2 <= (i + 1); h2++)
            {
                printf("#");
            }
            printf("\n");
        }
        return 0;
    }
}
