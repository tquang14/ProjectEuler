#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkPrimes(int n)
{	
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt((float) n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	int a, b, aMax = 1, bMax = 1, nMax = 0;
	for (a = -999; a < 1000; a++)
		for (b = -1000; b <= 1000; b++)
		{
			int n = 0;
			while(checkPrimes(abs(n*n + a*n +b)))
				n++;
			if (n > nMax)
			{
				aMax = a;
				bMax = b;
				nMax = n;
			}
		}
	printf("%d\n",aMax*bMax );
	system("pause");
	return 0;
}