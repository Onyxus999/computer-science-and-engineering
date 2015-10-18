/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <stdlib.h>
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int size)
{
	int cursor = 0;
	int start = 0;

	while (value != values[cursor])
	{
		cursor = (start + (size - 1)) / 2;

		if (values[cursor] < value)
		{
			size -= (cursor + 1);
			cursor--;
		}
		else if (value[cursor] > value)
		{
			start = (cursor + 1);
			cursor++;
		}

		if (size < 1 || start >= size)
			return false;
	}
	
	return true;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
	int swap_count = 1;
	while (swap_count > 0 && n > 1)
	{
		swap_count = 0;
		int temp;
	
		for (int i = 0; i < (n - 1); i++)
		{
			if (values[i] > values[i + 1])
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
				swap_count++;
			}
		}

		n--;
	}
	
	return;
}
