#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int LLI;

int main(void)
{
	LLI *arr;
	int a, b, i = 0; // array to store the distinct terms
	arr = (LLI*)malloc(sizeof(LLI));
	for (a = 2; a <= 100; ++a)
		for (b = 2; b <= 100; ++b)
		{
			double c = pow(a, b);
			int j = -1, r = 0; // r = 0 mean there is no repeats
			while (1)
			{	
				if (j >= i)
					break;
				if (*(arr + (j + 1)) == c)
				{
					r = 1;
					break;
				}
				else 
					j++;
			}
			if (r == 0)
			{
				*(arr + i) = c;
				i++;
				arr = (LLI *)realloc(arr, sizeof(LLI)*(i + 1));
			}
		}
	free(arr);
	printf("%d\n", i);
	system("pause");
	return 0;
}