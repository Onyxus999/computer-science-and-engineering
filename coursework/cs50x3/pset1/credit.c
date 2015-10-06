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
	cred_num = 8507437083;

	len_cred_num = count_digl(cred_num);

	/* Variable: List of Digits of Credit Card Number */
	int lst_cred_num[len_cred_num];
	int i;
	for (i = 0; i < len_cred_num; i++) {
		printf("Got to the for loop");
		/* Takes the number and modulos it by each power of 10 to obtain each digit */
		lst_cred_num[i] = ((cred_num % (10 ^ (i + 1))) / (10 ^ i));

	}

	i = 0;
	for ( i = 0; i < len_cred_num; i++) {
		printf("%i\n", lst_cred_num[i]);

	}

	return 0;
}
