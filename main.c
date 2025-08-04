#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <basetsd.h>

#include "define.h"
#include "functions.h"
#include "big_numbers.h"


int main() {
	clock_t start_time = clock();

	DWORD processID = GetCurrentProcessId();
	printf("ProcessID :%lu\n", processID);
	DWORD random_num = rand_num_gen(processID);
	printf("Random num :%lu\n", random_num);

	//prime number near the random number
	/*
	DWORD prime_num = prime_near_random_num(random_num);
	printf("Prime Number Found: %lu\n", prime_num);
	*/

	//random number's prime factorization 
	/*
	char* factorized = factorization(random_num);
	printf("random number's factorization :%s\n", factorized);
	free(factorized);
	*/

	/*
	//dword to string
	char* dw_string = dword_to_string(random_num);
	printf("random number to string : %s\n", dw_string);
	free(dw_string);
	*/

	//multiply string to string
	/*
	char* string_1 = "3333333";
	char* string_2 = "21212121";
	char* multiplied = multiply(string_1, string_2);
	printf("%s * %s = %s\n",string_1,string_2, multiplied);
	free(multiplied);
	*/


	size_t file_size = 0;
	char* number_in_file = get_number_from_file("digits1k.txt", &file_size);
	size_t array_len = 0;
	//int* digits_from_file = string_to_digit_array(number_in_file, &array_len);
	const int B = 1000000;
	int* A = parse_into_chunks(number_in_file, B, &array_len);

	for (size_t i = 0;i < array_len;i++) {
		printf("A[%zu] = %d\n", i, A[i]);
	}
	printf("number of chunks is : %zu\n", array_len);

	free(number_in_file);
	

	/*
	unsigned long long base = 2;
	int pow = 64;
	unsigned long long* result =power(&base, pow);
	*result *= 1.8;
	if (result) {
		printf("%llu power %d = %llu\n", base, pow, *result);
		free(result);
	}
	*/

	/*
	char* a = "1234";
	char* b = "5678";
	size_t* len = 0;
	int* result = convolution(a, b,&len);
	for (int i = 0; i < len; i++) {
		printf("[%d]", result[i]);
	}
	printf("\n");
	free(result);
	*/

	/*
	size_t n = 159;
	size_t r = next_power_of_two(n);
	printf("%lu\n", r);
	*/






	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f seconds\n", elapsed_time);


	return 0;
}
