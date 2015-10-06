#include <stdio.h>
#include <math.h>

/* Checks if a number is smaller than a power of 10 and if it is, infes the number of digits accordingly
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

int main(void) {

	/* Variables: Credit Card Number, Length of Credit Card Number */
	long cred_num; 
	int len_cred_num;

		/* Values */
		/* Note: Make cred_num user defined before final version */
		cred_num = 1234567890;

		len_cred_num = count_digl(cred_num);

	/* Variable: List of Digits of Credit Card Number as String */
	char charlst_cred_num[len_cred_num];

		/* Value */
		sprintf(charlst_cred_num, "%ld", cred_num);

	/* Variable: List of Digits of Credit Card Number as Int */
	int lst_cred_num[len_cred_num];

		/* Value */
		int i = 0;
		for (i = 0; i < len_cred_num; i++) {
			lst_cred_num[i] = charlst_cred_num[i] - '0';

		}

	/* Body */
	
		/* Print List of Digits */
		i = 0;
		for (i = 0; i < len_cred_num; i++) {
			printf("%d", lst_cred_num[i]);

		}
		
		printf("\n");
	return 0;
}
