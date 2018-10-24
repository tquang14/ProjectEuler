#define true 1

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int carry = 0, n = 0, temp = 0;
	int a[1000] = { 0 }, b[1000] = { 0 }, c[1000] = { 0 };
	a[0] = 1;
	b[0] = 1;
	int i = 2; //index begin with 2
	while (true)
	{	
		i++;
		for (int j = 0; j <= 999; j++)
		{
			c[j] += (a[j] + b[j]) % 10;
			if ((a[j] + b[j]) >= 10)
			{
				c[j + 1] = (a[j] + b[j]) / 10;
			}
			
		}
		//condition to break loop
		if (c[999] != 0) break;
		//replace Fn-2 by Fn-1 and Fn-1 by Fn and remove value of Fn(store in C[])
		for (int j = 0; j <= 999; j++)
		{
			a[j] = b[j];
			b[j] = c[j];
			c[j] = 0;
		}
	}
	/*for (int i = 3; i >= 0; i--)
		printf("%d ", c[i]);*/
	printf("\n%d\n", i);
	return 0;
}