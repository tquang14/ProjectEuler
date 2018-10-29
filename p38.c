/*
918273645 is the concatenated product of 9 and (1,2,3,4,5)
=> the result must be begin with 9
the 2 digits number and (1,2,3,...,n) can't make a 9 digits number
since n = 3 make the 8 or less than 8 digits number, n = 4 make the 11 digits number
same for n = 3 make 7 or 11 digits number
n > 1 => the fixed number must contain less than 5 digits
=> the loop start at 9123 and end at 9876
91..*1 = 91...
9...*2 = 18... so non of the digits can be 1
91..*1 = 91...
95..*2 = 10...
if the second digit > 4 then we will get two 9's
=> loop do between 9234 and 9487
*/

#include <stdio.h>
#include <stdlib.h>

int check_pandigital(int a, int b);

int main(void) {

	int max = 0;
	for (int i = 9234; i <= 9487; i++) {
			// 4 digits => product of an integer with (1,2)
			if (check_pandigital(i*1, i*2))
				if (i > max)
					max = i;
	}
	printf("%d%d\n", max, max*2);
	return 0;
}

int check_pandigital(int a, int b) {
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

	for (int k = 0; k < 9; k++)
		if (arr[k] == 0)
			return 0;
	return 1;
}