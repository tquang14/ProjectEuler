#include <stdio.h>
#include <stdlib.h>

#define upperBound 354294
//5*9^5=295245 => with 5 digits we can make 6 degits number. 6*9^5 = 354294

int main(void)
{
	int result = 0;
	for (int i = 2; i <= upperBound; ++i)
	{	
		int number = i, sumOfPowers = 0;
		while(number > 0)
		{
			int d = number % 10;
			number /= 10;
			int temp = d;
			//loop to make the fifth powers
			for (int j = 1; j < 5; j++)
			{
				temp *= d;
			}
			sumOfPowers += temp;
		}
		if (sumOfPowers == i)
		{
			result += sumOfPowers;
		}
	}

	printf("%d\n", result);
	return 0;
}