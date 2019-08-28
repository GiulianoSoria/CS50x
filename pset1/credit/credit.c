#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned long long n;

    do
    {
        n = get_long_long ("Number: ");
    }
    while (n <= 0);

    if ((n < 1000000000000) || (n > 10000000000000000))
    {
        printf("INVALID\n");
    }

    int m;
    int result = 0;

    unsigned long long int  i = 1, j = 1, odd, even;
    // n2, n3, n4, n5, n6, n7, n8, n9,
    // n10, n11, n12, n13, n14, n15;
    for (int countodd = 0; countodd < 8; countodd++)
    {
        odd = (((n % (100 * i)) - (n % (10 * i))) / (10 * i));

        i = i * 100;

        odd = odd * 2;

        if (odd >= 10)
        {
            odd = 1 + (odd % 10);
        }
        result += odd;
    }

    for (int counteven = 0; counteven < 8; counteven++)
    {
        even = (((n % (10 * j)) - (n % j)) / j);

        j = j * 100;

        result += even;
    }

    unsigned long long int k = 10000000000000, l = 100000000000000;
    int index = 0, a = 0, b = 0;

    if (result % 10 == 0)
    {
        // For AMEX
        if ((n > 100000000000000) && (n < 999999999999999))
        {
            a = (((n % (100 * k)) - (n % (10 * k))) / (10 * k));
            a = a * 10;
            b = (((n % (10 * k)) - (n % k)) / k);
            index = a + b;
            if (index == 34 || index == 37)
            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        if ((n > 1000000000000000) && (n < 9999999999999999))
        {
            a = (((n % (100 * l)) - (n % (10 * l))) / (10 * l));
            a = a * 10;
            b = (((n % (10 * l)) - (n % l)) / l);
            index = a + b;
            //For MasterCard
            if (index == 51 || index == 52 || index == 53 || index == 54 || index == 55)
            {
                printf("MASTERCARD\n");
            }

            //For Visa
            if (a == 40)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    else
    {
        printf("INVALID\n");
    }
}