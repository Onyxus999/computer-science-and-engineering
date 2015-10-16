#include <stdio.h>
#include <stdlib.h>

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

	return 0;
}
