#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int money;
	int number_of_coins = 0;

	printf("Enter what you would like change for: ");
	money = GetFloat()*100;

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
	printf("You'd need %d coins to make that change.\n", number_of_coins);	

	return 0;
}
