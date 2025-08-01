
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

	size_t a_len = strlen(a);
	size_t b_len = strlen(b);
	size_t max_len = a_len + b_len;

	int* multiplied_result = calloc(max_len+1, sizeof(int));
	if (multiplied_result == 0) {
		return NULL;
	}
	if (a_len == 0 || b_len == 0) {
		return NULL;
	}

	

	for (int i = 0;i < b_len;i++) {
		int first_operand = a[a_len - i - 1] - '0';
		if (first_operand == 0) {
			continue;
		}
		for (int j = 0;j < a_len ;j++) {
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

	char* result = calloc(max_len+1, sizeof(char));
	if (result == 0) {
		return NULL;
	}
	int count = 0;
	for (int i = max_len - 1;i >= 0;i--) {
			result[count++] = (unsigned char)multiplied_result[i] + '0';
	}
	result[count] = '\0';

	free(multiplied_result);
	return result;
}
