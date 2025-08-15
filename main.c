#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <ctype.h>
#include <time.h>
#include <math.h>


#include "define.h"
#include "functions.h"
#include "rsa.h"

int main() {
	clock_t start_time = clock();
	DWORD processID = GetCurrentProcessId();


	size_t _size = 0;
	char* number_in_file = get_number_from_file("digits100k.txt", &_size);
	char* rand = random_number(number_in_file, _size,processID);

	/*
	unsigned long long last_prime = get_last_prime_fseek("prime_numbers.txt");
	printf("Last prime number in file: %llu\n", last_prime);
	for (unsigned long long i = last_prime; ; i++) {
		if (is_prime(i)) {
			collect_prime_numbers("prime_numbers.txt", i);
		}
		if (i == ULLONG_MAX) {
			printf("all ull primes are collected\n");
		}
	}
	*/

	/*
	unsigned long long count = count_primes_in_file("prime_numbers.txt");
	printf("%llu prime numbers are in file\n", count);
	*/

	free(number_in_file);


	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f seconds\n", elapsed_time);


	return 0;
}
