#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int r = 0;
	int result[1000];
	int i = 0;

	while (n > 0) {

		r = n % 2;
		n = n / 2;
		result[i] = r;
		++i;

	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%d", result[j]);
	}

	return 0;
}