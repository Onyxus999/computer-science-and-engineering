#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
	int money = -1;
	int number_of_coins = 0;
    
    while (money < 0) // keeps inputs from being negitive
    {
        printf("Enter what you would like change for: ");
	
        // changes input into number of cents rounded to the nearest cent
        money = roundf(GetFloat()*100);
    }

    /*    This block of code checks if the input is larger than a given coin
     *    going from largest coin to smallest coin, and if it is, it 'uses'
     *    that coin to make change. Removing it from the change needed, and
     *    adding one coin to the pot
     */
    while (money >= 25)
	{
		money -= 25;
		number_of_coins++;
	}
	
    while (money >= 10)
	{
		money -= 10;
		number_of_coins++;
	}
	
    while (money >= 5)
	{
		money -= 5;
		number_of_coins++;
	}
	
    while (money >= 1)
	{
		money -= 1;
		number_of_coins++;
	}
    
    printf("%d\n", number_of_coins);
    return 0;

}
