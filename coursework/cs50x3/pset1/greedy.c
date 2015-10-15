#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
	int money = -1;
	int number_of_coins = 0;
    
    while (money < 0)
    {
        printf("Enter what you would like change for: ");
	    money = roundf(GetFloat()*100);
    }
	
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
