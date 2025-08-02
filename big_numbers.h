
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


	for (int i = 0;i < a_len;i++) {
		int first_operand = a[a_len - i - 1] - '0';
		if (first_operand == 0) {
			continue;
		}
		for (int j = 0;j < b_len;j++) {
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
	for (int i = (int)max_len - 1;i >= 0;i--) {
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