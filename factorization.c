#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

char* factorization(DWORD number) {
	char* array = malloc(128);
	if (!array) {
		return NULL;
	}
	array[0] = '\0';
	
	DWORD buffer = number;
	for (int i = 2;i <= buffer;i++) {
		int count = 0;
		while (buffer % i == 0) {
			buffer /= i;
			count++;
		}
		if (count > 0) {
			char buffer[32];
			sprintf_s(buffer,sizeof(buffer), "[%d][%d] ", i, count);
			strcat_s(array,sizeof(buffer), buffer);
		}
	}

	return array;
}

int main() {

	DWORD number = 156843;
	printf("number :%lu\n", number);
	char* factorized_array = factorization(number);
	int array_len = strlen(factorized_array);
	printf("Factor of %lu : %s ", number, factorized_array);
	free(factorized_array);
	return 0;
}