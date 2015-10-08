/*
 *	This program takes a credit card number 
 *	and tests to see if it is valid.
 *
 *	Author: Onyxus999 (Jacob Rogers)
 */

#include <stdio.h>
#include <math.h>
#include <cs50.h> // Remember to link cs50 when compliling

/* returns the nth digit of a long
 * 
 */
int digital(long int num, int n) {
	return fmod(num, pow(10, n)) / pow(10, n-1);

}

// MAIN FUNCTION
int main(void) {
	
	long test_number = 1234567890;

	printf("%d", digital(test_number, 6));
	
	return 0;

}
