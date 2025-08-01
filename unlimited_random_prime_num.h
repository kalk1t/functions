
char* dword_to_string(DWORD processID) {
	char* buffer = malloc(MAX_SIZE);
	if (!buffer) {
		return NULL;
	}
	snprintf(buffer, MAX_SIZE, "%lu", (unsigned long)processID);

	return buffer;
}

char* get_100k_number(const char* path, size_t* len) {

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


char* multiply(const char* a, const char* b) {


	size_t n1 = strlen(a);
	size_t n2 = strlen(b);
	if (n1 == 0 || n2 == 0) {
		return NULL;
	}

	size_t result_size = n1 + n2;
	int* res = calloc(result_size + 1, sizeof(int));
	if (!res) {
		return NULL;
	}
	int remainder = 0;
	int result = 0;
	int	main_remainder = 0;
	for (size_t i = 0; i < n1; i++) {
		int m1 = a[n1 - i - 1] - '0';
		for (size_t j = 0; j < n2; j++) {
			int m2 = b[n2 - j - 1] - '0';

			if ((res[i + j] + ((m1 * m2) % 10)) >= 10) {
				res[i + j] += (m1 * m2) % 10;
				res[i + j + 1] += (m1 * m2) / 10;
				if (res[i + j + 1] >= 10) {
					res[i + j + 2] += res[i + j + 1] / 10;
					res[i + j + 1] = res[i + j + 1] % 10;
				}
				res[i + j] = res[i + j] % 10;
			}
			else {
				res[i + j] += (m1 * m2) % 10;
				if (m1 * m2 >= 10) {
					res[i + j + 1] += (m1 * m2) / 10;
					if (res[i + j + 1] >= 10) {
						res[i + j + 2] += res[i + j + 1] / 10;
						res[i + j + 1] = res[i + j + 1] % 10;
					}

				}

			}

			//printf("m1(%d) * m2(%d)= remainder(%d) ,addtonextnumber(%d)\n", m1, m2, res[i + j], result);
		}
		printf("i=%d - [%d]%d,[%d]%d,[%d]%d,[%d]%d\n", i, res[i + 0], i + 0, res[i + 1], i + 1, res[i + 2], i + 2, res[i + 3], i + 3);

		result = 0;
	}
	size_t size = sizeof(res);
	char* multiplied_result = malloc(8 + 1);


	for (int i = sizeof(res) - 2, j = 0; i >= 0; i--) {
		multiplied_result[j++] = res[i] + '0';
	}
	multiplied_result[size - 1] = '\0'; // Null-terminate the string
	free(res);
	return multiplied_result;
}
