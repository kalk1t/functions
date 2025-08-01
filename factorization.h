
char* factorization(DWORD number) {
	char* array = malloc(128);
	if (!array) {
		return NULL;
	}
	array[0] = '\0';
	
	DWORD buffer = number;
	for (int i = 2;i <= buffer;i++) {
		int count = 0;
		while (buffer % i == 0) {
			buffer /= i;
			count++;
		}
		if (count > 0) {
			char buffer[32];
			sprintf_s(buffer,sizeof(buffer), "[%d][%d] ", i, count);
			strcat_s(array,sizeof(buffer), buffer);
		}
	}

	return array;
}