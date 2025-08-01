#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


#include "define.h"
#include "random_prime_number.h"
#include "factorization.h"
#include "unlimited_random_prime_num.h"



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
	
	char* string_1 = "3333333";
	char* string_2 = "21212121";
	char* multiplied = multiply(string_1, string_2);
	printf("%s * %s = %s\n",string_1,string_2, multiplied);
	free(multiplied);


	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f seconds\n", elapsed_time);


	return 0;
}
