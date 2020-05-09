#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

int main(void)
{
    float amount = get_float("Change owed: ");
    int change = round(amount * 100);
    int coins, q, r;
    
    while(change != 0)
    {
        if(change > QUARTERS)
        {
            q = change/QUARTERS;
            r = change%QUARTERS;
            coins = q + r;
        }
    }

    printf("%i, %i\n", q, r);
}