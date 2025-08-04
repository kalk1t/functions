






char* dword_to_string(DWORD processID) {
	char* buffer = malloc(MAX_SIZE);
	if (!buffer) {
		return NULL;
	}
	snprintf(buffer, MAX_SIZE, "%lu", (unsigned long)processID);

	return buffer;
}

char* get_number_from_file(const char* path, size_t* len) {

	FILE* num_100k = fopen(path, "rb");
	if (!num_100k) {
		printf("Error opening num_100k.txt\n");
		return NULL;
	}
	if (fseek(num_100k, 0, SEEK_END) != 0) {
		printf("Error seeking to end of file\n");
		fclose(num_100k);
		return NULL;
	}
	long size = ftell(num_100k);
	if (size < 0) {
		printf("Error getting file size\n");
		fclose(num_100k);
		return NULL;
	}
	rewind(num_100k);


	char* buffer = malloc(size + 1);
	if (!buffer) {
		printf("Memory allocation failed\n");
		fclose(num_100k);
		return NULL;
	}
	size_t read = fread(buffer, 1, (size_t)size, num_100k);
	if (read != (size_t)size) {
		printf("Error reading file\n");
		free(buffer);
		fclose(num_100k);
		return NULL;
	}
	buffer[read] = '\0'; // Null-terminate the string
	fclose(num_100k);
	*len = read;


	return buffer;
}

unsigned long long* power(unsigned long long* digit, int power) {
	if (power < 0) return NULL;

	unsigned long long* result = malloc(sizeof(unsigned long long));
	if (!result) return NULL;
	*result = 1;

	for (int i = 0;i < power;i++) {
		*result *= *digit;
	}
	return result;
}

int* string_to_digit_array(const char* str, int* out_len) {
	int len = strlen(str);
	int* digits = malloc(sizeof(int) * len);
	if (!digits) return NULL;

	for (int i = 0;i < len;i++) {
		if (str[len - i - 1] >= '0' && str[len - i - 1] <= '9') {
			digits[i] = str[len - i - 1] - '0';
		}
		else {
			free(digits);
			return NULL;
		}
	}
	*out_len = len;

	return digits;
}

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

char* factorization(DWORD number) {
	char* array = malloc(128);
	if (!array) {
		return NULL;
	}
	array[0] = '\0';

	DWORD buffer = number;
	for (unsigned int i = 2;i <= buffer;i++) {
		int count = 0;
		while (buffer % i == 0) {
			buffer /= i;
			count++;
		}
		if (count > 0) {
			char buffer[32];
			sprintf_s(buffer, sizeof(buffer), "[%d]^%d ", i, count);
			strcat_s(array, sizeof(buffer), buffer);
		}
	}

	return array;
}


char* grade_school(const char* a, const char* b) {
	//O(n^2)
	//this algorithm is good for number with lwoer than 1000 digits


	size_t a_len = strlen(a);
	size_t b_len = strlen(b);
	size_t max_len = a_len + b_len;

	int* multiplied_result = calloc(max_len + 1, sizeof(int));
	if (multiplied_result == 0) {
		return NULL;
	}
	if (a_len == 0 || b_len == 0) {
		return NULL;
	}

	size_t len_1 = 0;
	size_t len_2 = 0;
	if (a_len >= b_len) {

	}
	else {

	}


	for (int i = 0; i < a_len; i++) {
		int first_operand = a[a_len - i - 1] - '0';
		if (first_operand == 0) {
			continue;
		}
		for (int j = 0; j < b_len; j++) {
			int second_operand = b[b_len - j - 1] - '0';
			if (second_operand == 0) {
				break;
			}
			multiplied_result[i + j] += first_operand * second_operand;
			if (multiplied_result[i + j] >= 10) {
				multiplied_result[i + j + 1] += multiplied_result[i + j] / 10;
				multiplied_result[i + j] %= 10;
			}
		}
	}

	char* result = calloc(max_len + 1, sizeof(char));
	if (result == 0) {
		return NULL;
	}
	int count = 0;
	for (int i = (int)max_len - 1; i >= 0; i--) {
		int k = 5;
		if ((multiplied_result[i] == 0) && (i == max_len - 1)) {
			continue;
		}
		else {
			result[count++] = (unsigned char)multiplied_result[i] + '0';
		}
	}
	result[count] = '\0';

	free(multiplied_result);
	return result;
}

char* karatsuba(const char* a, const char* b) {
	//O(n^1.585) good for few thousand digis

}

char* toom_cook(const char* a, const char* b) {
	//O(n^1.465) good for few 10^4 digits

}

char* schonhage_strassen(const char* a, const char* b) {
	//O(n log n log log n)  good for 10^4 - 10^6 digits

}

char* harvey_van_der_hoevem(const char* a, const char* b) {
	//O(n log n)galactic,asymptotic optimum, hude n only

}