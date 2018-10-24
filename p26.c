/* The idea and algorithm can be found at: https://www.mathblog.dk/project-euler
-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int CycleLength = 0;
	int d;
	for (d = 1000; d > 0; d--)
	{	
		// the maximum recurring cycle length of 1/d is d-1
		int *remainder = (int*)calloc(d, sizeof(int));
		int value = 1, NumOfCalculation = 0;
		while(*(remainder + value) == 0 && value != 0)
		{
			*(remainder + value) = NumOfCalculation;
			value = ( value*10 ) % d;
			NumOfCalculation++;
		}
		if (NumOfCalculation - *(remainder + value) > CycleLength)
			CycleLength = NumOfCalculation - *(remainder + value);
		if (CycleLength >= d-1)
			break;
	}
	printf("The number with the longest recurring cycle is %d\n",d);
	printf("The cycle length is %d \n",CycleLength);
	system("pause");
	return 0;
}