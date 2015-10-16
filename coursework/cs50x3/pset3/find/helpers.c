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
bool search(int value, int values[], int n)
{
	int median = 0;
	for (int i = 0; i < n; i++)
		median += values[i];
	median /= n;

	int index = 0;
	while (values[index] < median)
	{
		index++;
	}

	int key = median;
	int new_values[n / 2];
	if (value < values[index] && n > 1)
	{
		for (int i = 0; i < (n / 2); i++)
			new_values[i] = values[i];
		
		search(value, new_values, (n / 2));

	}
	else if (value > values[index] && n > 1)
	{
		for (int i = 1; i < (n / 2); i++)
			new_values[i - 1] = values[index + i];

		search(value, new_values, (n / 2));
	}
	else
		return true;

	// if true was not returned, return false
	return false;
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
