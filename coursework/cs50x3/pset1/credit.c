#include <stdio.h>
#include <math.h>

/*** This program tests the validity of a user specified credit card number ***
 *** Author: Onyxus999 (Jacob Rogers)                                       ***/

/* Function: Checks if a number is smaller than a power of 10 and if it is, infes the number of digits accordingly
 * i.e. if it's less than 10, it has 1 digits; if it's less than 100 it has 2 digits; etc */
int count_digl(long num) {

	long i = 10;
	long d = 1;
	while(1==1) {
		if(num < i){
			return d;
		}
		else {
		
			i *= 10;
			d++;
		}
	}
}

/* Function: Turn a long into an array of digits */
int * digitize(long num) {
	int len_num = count_digl(num);
	char charlst_num[len_num];
	static int lst_num[];

	
	sprintf(charlst_num, "%ld", num); // Scan num into the char array charlst_num
		
			/* For every element in charlst_num put the integer equivilant into lst_num */
	int i = 0;
	for (i = 0; i < len_num; i++) {
		lst_num[i] = charlst_num[i] - '0';

	}

	return lst_num;

}


int main(void) {

	/* Variables: Credit Card Number, Length of Credit Card Number, List of Digits of Credit Card Number as String,  List of Digits of Credit Card Number as Int */
	long cred_num;
	int len_cred_num;

	/* Body */
	
		/* Values */	
			printf("Please enter a credit card number: ");
			scanf("%ld", &cred_num);			

			int *lst_cred_num; 
			lst_cred_num = digitize(cred_num);			

		/* Print List of Digits */
		
		printf("The Card Number is: ");
		
		int i = 0;
		for (i = 0; i < len_cred_num; i++) {
			printf("%d", lst_cred_num[i]);

		}
		
		printf("\n");

		printf("The sumed product is: ");

		i = 0;
		int j = len_cred_num-2;
		int sum = 0;
		for (i = 0; i < len_cred_num; i += 2) {
			printf("The %d digit is %d\n", j, lst_cred_num[j]);
			sum += (lst_cred_num[j]*2);
			j -= 2;

		}
		
		printf("%d\n", sum);

	return 0;
}
