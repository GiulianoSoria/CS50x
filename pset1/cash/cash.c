#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;

    do
    {
        n = get_float("Change owed: ");
        n = n * 100;
        n = round(n);

    }
    while (n < 0);


    int a = 0;

    while (n >= 25)
    {
        n = n - 25;

        a = a + 1;
    }

    while (n >= 10)
    {
        n = n - 10;

        a = a + 1;
    }

    while (n >= 5)
    {
        n = n - 5;

        a = a + 1;
    }

    while (n >= 1)
    {
        n = n - 1;

        a = a + 1;
    }

    printf("%i\n", a);
}