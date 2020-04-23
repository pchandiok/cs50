#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int key;

int main(int argc, char *argv[])
{
	//Checks no. of command line arguments
	if(argc != 2)
	{
		printf("USAGE: ./caesar key\n");
		exit(1);
	}
	
	//copied arugment string to char pointer
	char *a = argv[1];
	
	for(int i=0, n=strlen(a);i<n;i++)
	{
		//checking whether entered arguments are digits or not
		if(!isdigit(a[i]))
		{
			printf("USAGE: ./caesar key\n");
			exit(1);
		}
	}

	key = atoi(a);
	//checking if the argument is positive integet or not
	if(key < 1)
	{
		printf("USAGE: ./caesar key\n");
		exit(1);
	}

	string plaintext = get_string("plaintext: ");
	printf("ciphertext: ");
	for(int i=0, n = strlen(plaintext); i < n; i++)
	{
		//checks if character is alphabet or not
		if(isalpha(plaintext[i]))
		{
			if(islower(plaintext[i]))
			{
				printf("%c", (((plaintext[i]-97) + key) % 26) + 97);
			}
			else
			{
				printf("%c", (((plaintext[i]-65) + key) % 26) + 65);
			}
		}
		else
		{
			printf("%c", plaintext[i]);
		}
	}
	printf("\n");
	return 0;
}
