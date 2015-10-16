#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UPALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOALPHA "abcdefghijklmnopqrstuvwxyz"

int isstring(char* test_str)
{
        int is_string = 1;
        for (int i = 0; i < strlen(test_str); i++)
        {
                if (!isalnum(test_str[i]))
                        is_string = 0;
                else if (isdigit(test_str[i]))
                        is_number = 0;
        }

        return is_string;
}

int main(int argc, char* argv[])
{
	if (argc == 1 || argc > 2)
	{
		printf("vigenere:: Error: Must have exactly one argument\n");
		return 1;	
	}
	else if (!isstring(argv[1]))
	{
		printf("vigenere:: Error: Key must be alphabetical\n");
		return 2;
	}
	else
	{
		char* key = argv[1];
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
				indexes[i] = 42
		}

		char* cyphertext = malloc(sizeof(char) * strlen(plaintext));

		return 0;
	}
}
