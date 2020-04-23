#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int letters=0;
    int words = 1;
    int sentence = 0;
    float index;
    string str = get_string("Text: ");
    for(int i=0,n=strlen(str);i<=n;i++)
    {
        //checks whether entered character is a letter or not.
        if(isalpha(str[i]))
        {
            letters += 1;
        }
        //checks whether the word has ended or not.
        else if(isspace(str[i]))
        {
            words += 1;
        }
        //checks whether the sentence has ended or not.
        else if(str[i] == '.' || str[i] == '?' || str[i] == '!' || str[i] == '\n')
        {
            sentence += 1;
        }
    }
    if(sentence == 0)
        sentence = 1;
    index = 0.0588 * (100.0 * letters/words) - 0.296 * (100.0 * sentence/words) - 15.8;
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %0.0f\n", index);
    }
    return 0;
}