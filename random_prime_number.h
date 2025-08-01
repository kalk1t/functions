
DWORD rand_num_gen(DWORD processID) {
	DWORD rand_num = processID * processID / (processID % 33);
	if (rand_num == 0) {
		rand_num = processID * processID / (processID % 21);
		if (rand_num == 0) {
			perror("rand_num is 0");
		}
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
		for (DWORD next_number = random_num; next_number; next_number++) {
			for (DWORD i = 2; i <= next_number; i++) {

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
