#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
	printf("Enter your full name: ");
	char* name = GetString(); 
	
	int is_first_letter = 1;
	char* initials = malloc(sizeof(int) * 3);
	for (int i = 0, j = 0; i < strlen(name); i++) 
	{
		if (is_first_letter == 1)
		{
			initials[j] = toupper(name[i]);
			j++;
			is_first_letter = 0;
		}
		else if (name[i] == ' ')
		{
			is_first_letter = 1;
		}
	}

	printf("%s\n", initials);

	return 0;
}
