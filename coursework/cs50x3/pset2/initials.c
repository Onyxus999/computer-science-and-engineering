#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
	char* name = GetString(); // Get the name from the user 
	
	int is_first_letter = 1; // If its the first letter of a word, this should be 1
	char* initials = malloc(sizeof(int) * 3); // this will store at most 3 initials
	for (int i = 0, j = 0; i < strlen(name); i++) // iterate through the name
	{
		if (is_first_letter == 1) // if it is the first letter of a word
		{
			initials[j] = toupper(name[i]); // add the first letter to the initial
			j++;
			is_first_letter = 0;
		}
		else if (name[i] == ' ') // if the current char is ' '
		{
			is_first_letter = 1; // the next letter is the first
		}
        // ignore all other letters
	}

	printf("%s\n", initials);

	return 0;
}
