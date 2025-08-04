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
		for (int i = 0; i<=k; i++) {
			if ((i >= a_len) || ((k - i) >= b_len)) {
				continue;
			}
			res += (a[i] - '0') * (b[k - i] - '0');
		}

		result[k] = res;
	}

	

	return result;
}