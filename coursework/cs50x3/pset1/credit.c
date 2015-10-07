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
		int len_sum;

		if ((len_cred_num % 2) == 0) {
			len_sum = (len_cred_num/2)+1;

		}
		else {
			len_sum = (len_cred_num/2);

		}

		int lst_sum[len_sum];

		for (i = 0; i < len_cred_num; i += 2) {
			//printf("The %d digit is %d\n", j, lst_cred_num[j]);
			lst_sum[k] = (lst_cred_num[j]*2);
			j -= 2;
			k++;

		}
		
		i = 0;
		for (i = 0; i < len_sum; i++) {
			printf("[%d] ", lst_sum[i]);

		}

		printf("\n");

		printf("The digits to sum are: ");

		int lst_len_sum[len_sum+1];

		i = len_sum+1;
		j = 0;
		for (i = len_sum+1; i > 0; i--) {
			lst_len_sum[i] = count_digl(lst_sum[i-1]);
			j += count_digl(lst_sum[i-1]);

		}

		lst_len_sum[0] = j;

		i = 0;
		j = 0;
		k = 0;
		int lst_sum_dig[lst_len_sum[0]];

		printf("[");

		for (i = 0; i < len_sum; i++) {
			for (j = 0; j < lst_len_sum[i+1]; j++) {
				lst_sum_dig[k] = digital(lst_sum[i], j);
				if (i == len_sum-1) {
					printf("%d]", lst_sum_dig[k]);
				
				}
				else {
					printf("%d ", lst_sum_dig[k]);

				}
				k++;

			}

		}

		printf("\n");

		printf("The sum of the digits is: ");

		i = 0;
		int sum = 0;

		for (i = 0; i < lst_len_sum[0]-1; i++) {
			//printf("\nSummed Digit: %d\n", lst_sum_dig[i]);
			sum += lst_sum_dig[i];
			//printf("Sum: %d\n", sum);

		}		
		
		printf("%d\n", sum);

		printf("The list of other numbers to be summed: ");
	
		i = 0;
		j = len_cred_num-1;
		k = 0;
		int lst_other_dig[len_cred_num-len_sum];

		for (i = 0; i < len_cred_num; i += 2) {
			//printf("The %d digit is %d\n", j, lst_cred_num[j]);
			lst_other_dig[k] = lst_cred_num[j];
			sum += lst_cred_num[j];
			j -= 2;
			k++;

		}
		
		i = 0;
		for (i = 0; i < len_sum; i++) {
			printf("[%d] ", lst_other_dig[i]);

		}

		printf("\n");
		
		printf("The total sum is: %d\n", sum);

		if (digital(sum, count_digl(sum)-1) == 0) {
			if (lst_cred_num[0] == 4) {
				printf("VISA\n");

			}
			if (lst_cred_num[0] == 5) {
				printf("MASTERCARD\n");

			}
			if (len_cred_num == 15) {
				printf("AMEX\n");

			}
			else {
				printf("INVALID\n");
			
			}

		}
		else {
			printf("Not Valid!\n");

		}

	return 0;
}
