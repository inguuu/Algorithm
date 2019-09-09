#include <stdio.h>

int main() {

	int a[10001];
	int s;

	scanf("%d", &s);

	for (int i = 0; i < s; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = s - 1; i >= 0; i--) {
		printf("%d ", a[i]);
	}

	return 0;
}