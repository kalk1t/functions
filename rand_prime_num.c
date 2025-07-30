#include <stdio.h>
#include <Windows.h>
#include <time.h>

DWORD rand_num(DWORD processID) {
	DWORD rand_num = processID * processID * (processID % 11) * (processID % 37);
	if (rand_num == 0) {
		rand_num = processID * processID * (processID % 11) * (processID % 21);
	}

	return rand_num;
}

//it searchs right side of random_num
DWORD prime_near_random_num(DWORD random_num) {
	DWORD prime_number = 0;
	if (random_num == 0) {
		return 0;
	}
	BOOL isprime = FALSE;
	while (!isprime) {
		for (DWORD next_number = random_num;next_number;next_number++) {
			for (DWORD i = 2;i <= next_number;i++) {

				if ((next_number / i) == 1 && (next_number % i) == 0) {
					isprime = TRUE;
					prime_number = next_number;
					break;
				}
				else if ((next_number % i) == 0) {
					printf("next_number(%lu) : divisor(%lu) = result(%lu),remainder(%lu)\n", next_number, i, next_number / i, next_number % i);
					break;
				}
			}
			if (isprime) {
				break;
			}

			printf("Not prime\n");
			printf("-----------------------\n");
			printf("Next_number :%lu\n", next_number + 1);

		}
	}
	return prime_number;
}

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
