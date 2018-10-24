#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//typedef long long int lli;

int check(int a, int b, long long int c) {
	int arr[9] = { '0' };
	int j = 0, temp;
	while (a > 0) {
		// take single digit of a to arr
		temp = a % 10;
		// check that if temp is already exist in arr if it's exist end function
		for (int k = 0; k < 9; k++)
			if (temp == arr[k])
				return 0;
		a /= 10;
		arr[j] = temp;
		j++;
	}

	while (b > 0) {
		temp = b % 10;
		for (int k = 0; k < 9; k++)
			if (temp == arr[k])
				return 0;
		b /= 10;
		arr[j] = temp;
		j++;
	}

	while (c > 0) {
		temp = c % 10;
		for (int k = 0; k < 9; k++)
			if (temp == arr[k])
				return 0;
		arr[j] = temp;
		j++;
		c /= 10;
	}
	for (int k = 0; k < 9; k++)
		if (arr[k] == 0)
			return 0;
	return 1;
}

int isPandigital_1_9(int a) {
	for (int i = 1; i < sqrt(a); i++)
		for (int j = i + 1; j < a; j++)
			if (i * j == a)
				if (check(i, j, a))
					return 1;
	return 0;
}

int main() {
	int sum = 0;
	//may take a while for computer to process this
	for (int i = 2; i < 10000; ++i) {
		if (isPandigital_1_9(i))
			sum += i;
	}

	printf("%d\n", sum);
	system("pause");
	return 0;
}