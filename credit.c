#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card = get_long("what's your card number?\n");
    long calculate_sum(long card, long x);
    long x = 15;
    long y = pow(10, x);

    //MASTER or VISA
    if ((card - card % y) / y > 0)
    {
        long sum = calculate_sum(card, x);
        if (sum % 10 == 0)
        {
            //VISA
            if ((card - card % y) / y == 4)
            {
                printf("VISA\n");
            }
            //MASTER
            else if ((card - card % y) / y == 5)
            {
                if (card % y / (y / 10) > 0 && card % y / (y / 10) < 6)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((card - card % (y / 10)) / (y / 10) > 0)
    {
        //AMERICAN EXPRESS
        x = 14;
        y = pow(10, x);
        long sum = calculate_sum(card, x);
        if (sum % 10 == 0)
        {
            if ((card - card % y) / y == 3)
            {
                if (card % y / (y / 10) == 4 || card % y / (y / 10) == 7)
                {
                    printf("AMEX\n");
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
    //VISA
    else if ((card - card % (y / 1000)) / (y / 1000) > 0)
    {
        x = 12;
        long sum = calculate_sum(card, x);
        if (sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}



long calculate_sum(long card, long x)
{
    // Get the value of each digit
    long s = 0;
    for (long exp = x; exp >= 0; exp--)
    {
        long length = pow(10, exp);
        long digit = (card - card % length) / length;
        card = card % length;
        if ((exp + 1) % 2 == 0)
        {
            digit *= 2;
            if (digit >= 10)
            {
                digit = 1 + digit % 10;
            }
        }
        s = s + digit;
    }
    return s;
}