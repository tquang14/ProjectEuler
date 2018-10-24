// the main idea can be found at https://www.mathblog.dk/project-euler-28-sum-diagonals-spiral/
// for n is the ring number, the sum of the diagonals can be written as f(n) = 4(2n+1)^2 – 12n + f(n-1)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int result = 1;// 1 is the center
	for (int i = 500; i >= 1; i--) // square 1001x1001 have 500 ring
	{
		result += 4*(2*i + 1)*(2*i + 1) -12*i;
	}
	printf("%d\n",result);
	return 0;
}