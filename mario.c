#include <cs50.h>
#include <stdio.h>

int main()
{
    int height;
    do
    {
        height = get_int("Enter height: ");
    } 
    while (height < 1 || height > 8);

    for(int i=1; i <= height; i++)
    {
        int k = i;
        int ctr=0;
        for(int j=1; j <= height - i; j++)
        {
            printf(" ");
        }
        while(k!=0)
        {
            printf("#");
            --k;
        }
        printf("  ");
        k=i;
        while(k!=0)
        {
            printf("#");
            --k;
        }
        printf("\n");
    }
}