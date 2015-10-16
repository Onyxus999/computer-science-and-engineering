#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UPALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOALPHA "abcdefghijklmnopqrstuvwxyz"

/*	This function checks if a string is comprised only of
 *	letters.
 */
int isstring(char* test_str)
{
        int is_string = 1;
        for (int i = 0; i < strlen(test_str); i++)
        {
                if (!isalnum(test_str[i])) // if it has non-alphanumeric chars 
                        is_string = 0; // its not all letters
                else if (isdigit(test_str[i])) // if it has numbers
                        is_string = 0; // its not all letters
        }

        return is_string;
}

int main(int argc, char* argv[])
{
	if (argc == 1 || argc > 2) // if there is more than exactly one argument
	{
		printf("vigenere:: Error: Must have exactly one argument\n");
		return 1; // error
	}
	else if (!isstring(argv[1])) // if the argunent isn't only letters
	{
		printf("vigenere:: Error: Key must be alphabetical\n");
		return 1; // error
	}
	else
	{
		char* key = argv[1]; // get keyword from command-line
		//printf("Enter text to encrypt: ");
		char* plaintext = GetString(); // get plaintext from user

		// this array will store the indexes of the plaintext
		// i.e. if the plaintext is abc, this will hold 0, 1, 2
		int* plain_indexes = malloc(sizeof(int) * strlen(plaintext));
		for (int i = 0; i < strlen(plaintext); i++)
		{
			if (isalpha(plaintext[i]))
			{
				plain_indexes[i] = (plaintext[i] % 32) - 1;
			}
			else
				// if the element in the string is not a letter
				plain_indexes[i] = 42; // its index is 42 (>25)
		}

		// this array will store the indexes of the key
		// i.e. if the key is abc, this will hold 0, 1, 2
		int* key_indexes = malloc(sizeof(int) * strlen(key));
		for (int i = 0; i < strlen(key); i++)
			key_indexes[i] = (key[i] % 32) - 1; // key is always all letters, because, if it wasn't, there would be errors

		// this array will hold the chars of the cyphertext
		char* cyphertext = malloc(sizeof(char) * strlen(plaintext));
		for (int i = 0, j = 0; i < strlen(plaintext); i++)
		{
			if (plain_indexes[i] > 25) // if the index is > 25
				cyphertext[i] = plaintext[i]; // ignore it
			else
			{
				if (isupper(plaintext[i])) // if its uppercase
				{
					cyphertext[i] = UPALPHA[(plain_indexes[i] + key_indexes[j % strlen(key)]) % 26]; // add uppercase ((p_i + k_j) % 26) to the cyphertext
					j++; // add 1 to the key incrementor
				}
				else // if its lowercase
				{
					cyphertext[i] = LOALPHA[(plain_indexes[i] + key_indexes[j % strlen(key)]) % 26]; // add lowercase ((p_i + k_j) % 26) to the cyphertext
					j++; // add 1 to the key incrementor
				}
			}
		}
		
		printf("%s\n", cyphertext);		

		return 0;
	}
}
