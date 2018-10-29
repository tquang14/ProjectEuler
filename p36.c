#include <stdio.h>
#define upperBond  1000000


bool isPalindromic(int n, int b);

int main(void) {
	int sum = 0;
	for (int i = 1; i < upperBond; ++i) {
		if (isPalindromic(i, 10) == isPalindromic(i, 2))
			sum += i;
	}
	printf("%d\n", sum);
	return 0;
}

bool isPalindromic(int n, int b) {
	// n is the number and b is base 10 or 2
	int reversed = 0, k = n;
	while (k > 0) {
		reversed = b * reversed + k % b;
		k /= b;
	}
	(reversed == n) ? return true : return false ;
}