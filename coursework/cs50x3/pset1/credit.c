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
int digital(long num, int index) {
	int len_num = count_digl(num);
	char charlst_num[len_num];
	int lst_num[len_num];

	
	sprintf(charlst_num, "%ld", num); // Scan num into the char array charlst_num
		
			/* For every element in charlst_num put the integer equivilant into lst_num */
	int i = 0;
	for (i = 0; i < len_num; i++) {
		lst_num[i] = charlst_num[i] - '0';

	}

	return lst_num[index];

}


int main(void) {

	/* Variables: Credit Card Number, Length of Credit Card Number, List of Digits of Credit Card Number as String,  List of Digits of Credit Card Number as Int */
	long cred_num;
	int len_cred_num;

	/* Body */
	
		/* Values */	
			printf("Please enter a credit card number: ");
			scanf("%ld", &cred_num);
			len_cred_num = count_digl(cred_num);			

			int lst_cred_num[len_cred_num]; 
			int i = 0;
			for (i = 0; i < len_cred_num; i++) {
				lst_cred_num[i] = digital(cred_num, i);
				//printf("%d ", lst_cred_num[i]);

			
			}			
			//return 0;
		/* Print List of Digits */
		
		printf("The Card Number is: ");
		
		i = 0;
		for (i = 0; i < len_cred_num; i++) {
			printf("%d", lst_cred_num[i]);

		}
		
		printf("\n");

		printf("The product list is: ");

		i = 0;
		int j = len_cred_num-2;
		int k = 0;
		int len_sum = (len_cred_num/2)/*+1*/;
		int sum[len_sum];

		for (i = 0; i < len_cred_num; i += 2) {
			//printf("The %d digit is %d\n", j, lst_cred_num[j]);
			sum[k] += (lst_cred_num[j]*2);
			j -= 2;
			k++;

		}
		
		i = 0;
		for (i = 0; i < len_sum; i++) {
			printf("[%d] ", sum[i]);

		}

	return 0;
}
