#include <stdio.h>
#include <stdlib.h>

void check_Cancelling(int a, int b);

int main() {
	
	for (int i = 10; i < 100; ++i) {
		for (int j = i+1; j < 100; ++j) {
			check_Cancelling(i, j);
			//printf("%d/%d\t", i, j);
		}
	}
	// if ( ((26/10)*1.0 / (65%10) == (26*1.0) / 65) && (26%10 == 65/10) )
	// 		printf("%d/%d\t", 26, 65);
	system("pause");
	return 0;
}

void check_Cancelling(int a, int b) {
	//double s = (a*1.0) / b;
	// printf("%f\n",s);
	// printf("%d/%d\n", a, b);
	// printf("%f\n", (a/10)*1.0 / (b%10));
	// if ( ((a/10)*1.0 / (b%10) == s) && (a%10 == b/10) )
	// 		printf("-----%d/%d\t", a, b);
	if ( (a%10 != 0) || (b%10 != 0) ) {
		// ax / bx = a/b
		if ( ((a/10)*1.0 / (b/10) == (a*1.0) / b) && (a%10 == b%10) )
			printf("%d/%d\t", a, b);
		// ax / xb = a/b
		if ( ((a/10)*1.0 / (b%10) == (a*1.0) / b) && (a%10 == b/10) )
			printf("%d/%d\t", a, b);
		// xa / bx == a/b
		if ( ((a%10)*1.0 / (b/10) == (a*1.0) / b) && (a/10 == b%10) )
			printf("%d/%d\t", a, b);
		// xa / xb == a/b
		if ( ((a%10)*1.0 / (b%10) == (a*1.0) / b) && (a/10 == b/10) )
			printf("%d/%d\t", a, b);
	}
}