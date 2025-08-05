int* convolution(const char* a, const char* b,size_t* out_len) {
	//O(n log n) good for 10^6 - 10^9 digits
	size_t a_len = strlen(a);
	size_t b_len = strlen(b);
	size_t max_len = a_len + b_len;
	*out_len = max_len - 1;
	int* result = calloc(max_len + 1, sizeof(int));

	if (result == NULL) {
		return NULL;
	}
	
	for (int k = 0; k < max_len; k++) {
		size_t res = 0;
		for (size_t i = 0; i<=k; i++) {
			if ((i >= a_len) || ((k - i) >= b_len)) {
				continue;
			}
			res += (a[i] - '0') * (b[k - i] - '0');
		}

		result[k] = res;
	}

	

	return result;
}

static size_t next_power_of_two(size_t x) {
	size_t pow= 1;
	while (pow < x) {
		pow <<= 1;
	}
	return pow;
}

int* parse_into_chunks(const char* s, int B, size_t* out_len) {
	//parse a decimal string into reversed "base -B" digits.
	//B: chunk base (10 000 for 4 digits)
	//out_len: receives number of chunks
	// returns a malloced array of ints

	size_t str_len = strlen(s);
	int chunk_digits = (int)floor(log10(B)); // 4 if B=10 000

	//how many full chunks?
	size_t n_chunks = (str_len + chunk_digits - 1) / chunk_digits;

	int* A = calloc(n_chunks, sizeof(int));
	if (!A) {
		perror("Calloc!");
		exit(1);
	}

	//walk the string backwards, slicing off chunk_digits at a time
	size_t index = 0;
	for (SSIZE_T end = (SSIZE_T)str_len;end > 0;) {
		SSIZE_T start = end - chunk_digits;
		if (start < 0) start = 0;

		char buf[MAX_DIGITS]; 
		size_t len = end - start;
		memcpy(buf, s + start, len);
		buf[len] = '\0';
		A[index++] = atoi(buf);

		end = start;
	}

	*out_len = n_chunks;
	return A;

}

