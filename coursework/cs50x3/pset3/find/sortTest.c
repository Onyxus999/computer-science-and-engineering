#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "helpers.h"

int main(int argc, char* argv[])
{
	int* unsorted = malloc(sizeof(int) * (argc - 1));
	for (int i = 1; i < argc; i++)
		unsorted[i-1] = atoi(argv[i]);

	for (int i = 0; i < (argc - 1); i++)
		printf("%d ", unsorted[i]);

	printf("\n");
	
	sort(unsorted, (argc - 1));
	for (int i = 0; i < (argc - 1); i++)
		printf("%d ", unsorted[i]);	

	printf("\n");
	
	printf("Enter the number to find: ");
	int value = GetInt();

	if (search(value, unsorted, (argc - 1)))
		printf("It is in the list!\n");
	else
		printf("It is not in the list!\n");

	return 0;
}
