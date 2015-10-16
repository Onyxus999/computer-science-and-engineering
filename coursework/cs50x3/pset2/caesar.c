#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UPALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOALPHA "abcdefghijklmnopqrstuvwxyz"

/*	This function tests to see if a string contains only digits
 *
 */
int isnum(char* test_str)
{
	int is_number = 1;
	for (int i = 0; i < strlen(test_str); i++)
	{
		if (!isalnum(test_str[i])) // if it contains a non-alphanumeric char
			is_number = 0; // its not a number
		else if (isalpha(test_str[i])) // if it contains a letter
			is_number = 0; // its not a number
	}
	
	return is_number;
}

int main(int argc, char* argv[])
{
	if (argc == 1 || argc > 2) // if there is none or more than 1 argument
	{
		printf("caesar:: Error: Must have exactly one argument\n");
		return 1; // return error
	}
	else if (!isnum(argv[1])) // if the argument isn't a number
	{
		printf("caesar:: Error: Please input an integer.\n");
		return 2; // return error 2
	}
	else
	{
		int key = atoi(argv[1]); // get integer from command line as key
		//printf("Enter text to encrypt: ");
		char* plaintext = GetString(); // get plaintext from user
		
		// this will be a list of indicies of the plaintext
		// i.e. if the plaintext is abc this will be 0, 1, 2
		int* indexes = malloc(sizeof(int) * strlen(plaintext)); 
		for (int i = 0; i < strlen(plaintext); i++)
		{
			if (isalpha(plaintext[i]))
			{
				indexes[i] = (plaintext[i] % 32) - 1;
			}
			else // if the plaintext has a non-alphanumeric char in it
				indexes[i] = 42; // the index is 42 (or anything > 25)
		}
	
		// this will be the string that holds the cyphertext
		char* cyphertext = malloc(sizeof(char) * strlen(plaintext));
		for (int i = 0; i < strlen(plaintext); i++)
		{
			if (indexes[i] > 25) // if the index is > 25
				// its non-alphanumeric
				cyphertext[i] = plaintext[i]; // so ignore it
			else
			{
				if (isupper(plaintext[i])) // if its uppercase
					cyphertext[i] = UPALPHA[(indexes[i] + key) % 26]; // put the ((p_i + k) % 26)th letter of the uppercase alphabet there
				else // if its lowercase
					cyphertext[i] = LOALPHA[(indexes[i] + key) % 26]; // put the ((p_i + k) % 26)th letter of the lowercase alphabet there
			}

		}		
		
		printf("%s\n", cyphertext);

		return 0;
	}

}
