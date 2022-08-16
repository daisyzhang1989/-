#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int number;
    while (true)
    {
        number = get_int("Height: ");
        if (number > 0)
        {
            if (number < 9)
            {
                break;
            }
        }
    }

    int n = number;
    int i = 1;
    int right = 1;

    //left side
    while (i <= number)
    {
        //invisible bricks
        for (int j = 0; j < n - 1; j++)
        {
            printf(" ");
        }
        n--;
        //visible bricks
        for (int m = 0; m < i; m++)
        {
            printf("#");
        }
        printf("  ");
        //right side
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
        i++;
    }
}