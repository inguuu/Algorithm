#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int n = a - 1;
	int m = a - 1;
	for (int i = 0; i < a; i++) {

		for (int j = 0; j <= a * 2 - 1; j++) {
			if (i == (a + 1) / 2 - 1) {
				if (m <= j && j <= n) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			else {

				if (j == n || j == m) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}

		}
		n++;
		m--;
		printf("\n");
	}
}