void collect_prime_numbers(const char* file_name,unsigned long long prime) {

	if (!file_name) {
		return ;
	}
	else {
		FILE *fp=fopen(file_name, "a");
		if (!fp) {
			printf("Error opening file %s\n", file_name);
			return;
		}
		fprintf(fp, "%llu\n", prime);
		fclose(fp);
	}

}

bool is_prime(unsigned long long n) {
	if (n < 2) return false;
	if ((n & 1ULL) == 0) return n == 2;
	if (n % 3 == 0) return n == 3;

	// Test 6k ± 1
	for (unsigned long long d = 5; d  <= n /d ; d += 6) {
		if (n % d == 0 || n % (d + 2) == 0) return false;
	}
	return true;
}

unsigned long long count_primes_in_file(const char* filename) {
	FILE* fp = fopen(filename, "rb");
	if (!fp) {
		perror("File open failed");
		return 0;
	}
	unsigned long long count = 0;
	unsigned long long temp;
	while (fscanf_s(fp, "%llu", &temp) == 1) {
		count++;
	}
	fclose(fp);
	return count;
}

unsigned long long get_last_prime_fseek(const char* filename) {
	FILE* fp = fopen(filename, "rb");
	if (!fp) {
		perror("File open failed");
		return 0;
	}

	if (fseek(fp, 0, SEEK_END) != 0) {
		perror("fseek failed");
		fclose(fp);
		return 0;
	}

	long pos = ftell(fp);
	if (pos == -1L) {
		perror("ftell failed");
		fclose(fp);
		return 0;
	}
	pos--; 

	while (pos > 0) {
		pos--;
		fseek(fp, pos, SEEK_SET);
		if (fgetc(fp)=='\n') {
			pos++;
			break;
		}
	}

	unsigned long long last_prime = 0;
	fseek(fp, pos, SEEK_SET);
	if (fscanf_s(fp, "%llu", &last_prime) != 1) {
		fprintf(stderr, "Failed to read number\n");
	}

	fclose(fp);
	return last_prime;
}


char* random_number(char* min_n,size_t n_size,DWORD processID) {
	if (n_size == 0 || min_n == NULL) {
		return NULL;
	}
	char* result = min_n;
	size_t frequency =processID/21;
	//printf("%zu\n", frequency);
	size_t count = n_size / frequency;
	//printf("%zu\n", count);
	for (size_t i = 0; i < count; i++) {
		if ((min_n[frequency * i] < 9 + '0') && (min_n[frequency * i] > 3 + '0')) {
			//printf("min_n[%zu * %zu] = %c\n", frequency, i, min_n[frequency * i]);
			result[frequency * i] = min_n[frequency * i] +1;
			//printf("min_n[%zu * %zu] = %c\n", frequency, i, min_n[frequency * i]);
		}
	}

	return result;
}

char* nearest_prime_number(char* random_n,size_t n_size){
	if (random_n == NULL || n_size == 0) {
		return NULL;
	}

	return NULL;
}
