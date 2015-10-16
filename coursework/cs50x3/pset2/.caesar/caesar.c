#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UPALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOALPHA "abcdefghijklmnopqrstuvwxyz"

int isnum(char* test_str)
{
	int is_number = 1;
	for (int i = 0; i < strlen(test_str); i++)
	{
		if (!isalnum(test_str[i]))
			is_number = 0;
		else if (isalpha(test_str[i]))
			is_number = 0;
	}
	
	return is_number;
}

int main(int argc, char* argv[])
{
	if (argc == 1 || argc > 2)
	{
		printf("caesar:: Error: Must have exactly one argument\n");
		return 1;
	}
	else if (!isnum(argv[1]))
	{
		printf("caesar:: Error: Please input an integer\n");
		return 2;
	}
	else
	{
		int key = atoi(argv[1]);
		printf("Enter text to encrypt: ");
		char* plaintext = GetString();
		
		int* indexes = malloc(sizeof(int) * strlen(plaintext));
		for (int i = 0; i < strlen(plaintext); i++)
		{
			if (isalpha(plaintext[i]))
			{
				indexes[i] = (plaintext[i] % 32) - 1;
			}
			else
				indexes[i] = 42;
		}
	
		char* cyphertext = malloc(sizeof(char) * strlen(plaintext));
		for (int i = 0; i < strlen(plaintext); i++)
		{
			if (indexes[i] > 25)
				cyphertext[i] = plaintext[i];
			else
			{
				if (isupper(plaintext[i]))
					cyphertext[i] = UPALPHA[(indexes[i] + key) % 26];
				else
					cyphertext[i] = LOALPHA[(indexes[i] + key) % 26];
			}

		}		
		
		printf("%s\n", cyphertext);

		return 0;
	}

}
