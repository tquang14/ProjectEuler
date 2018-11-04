#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

long int size_of_file(FILE *file);
float findNumValue(int t); // n^2 + n = 2t

int main(void) {
	const char *filePath = "C:/Users/Quang/AppData/Roaming/Sublime Text 3/Packages/User/ProjectEuler/p42.txt";
	FILE *file;
	char *arr;
	int wordValue = 0, result = 0;;

	file = fopen(filePath, "r");
	arr = (char*)calloc(size_of_file(file), sizeof(char));
	fgets(arr, size_of_file(file), file); // store the file p42.txt to arr
	//printf("%d \n", *(arr + 40));

	for (int i = 0; i < size_of_file(file); i++) {
		//printf("%d \n", wordValue);
		if (*(arr + i) == 44) {	// 44 <=> ','
			if (findNumValue(wordValue) == (int)findNumValue(wordValue))
				result++;
			wordValue = 0;
			continue;
		}
		else if (*(arr + i) != 34) // 34 <=> '"'
			wordValue += *(arr + i) - 64;// alphabetical position
	}
	
	
	printf("%d \n", result);
	fclose(file);
	system("pause");
	return 0;
}

long int size_of_file(FILE *file) {
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	return size;
}

float findNumValue(int t) {
	if (t <= 0)
		return 0;
	return (sqrt(1 + 8 * t) - 1) / 2;
	
}
