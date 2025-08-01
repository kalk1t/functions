#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "random_prime_number.h"
#include "factorization.h"
#include "unlimited_random_prime_num.h"

int main() {

	DWORD processID = GetCurrentProcessId();
	printf("ProcessID :%lu\n", processID);
	DWORD random_num = rand_num(processID);
	printf("Random num :%lu\n", random_num);

	clock_t start_time = clock();

	DWORD prime_num = prime_near_random_num(random_num);
	printf("Prime Number Found: %lu\n", prime_num);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f seconds\n", elapsed_time);


	return 0;
}
