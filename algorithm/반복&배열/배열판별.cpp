#include <stdio.h>

int main() {

	int n[100];
	int s[100];

	int size;

	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		scanf("%d", &n[i]);
	}

	int b = 0;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (n[i] == 0) {
			s[i] = 0;
			b = 0;
		}
		if (n[i] == 1) {
			s[i] = 1 + b;
			sum += s[i];
			++b;
		}
	}

	printf("%d", sum);

	return 0;
}