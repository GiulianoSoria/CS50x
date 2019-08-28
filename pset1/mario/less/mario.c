#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    {
    do
    {
    do
    {
        n = get_int("Height = ");
    }
    while (n < 0);
    }
    while (n > 23);

    for (int i = 0; i < n ; i++)
    {
        for (int s = 1; s < (n - i); s++)
        {
            printf(" ");
        }
        for (int h = 1; h <= (i + 2); h++)
        {
            printf("#");
        }
        printf("\n");
    }
    }
}