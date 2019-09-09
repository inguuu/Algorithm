#include <stdio.h>

int main() {

	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = n; i <= m; i++) {
		int j;
		for (j = 2; j < i; j++) {
			if (i%j == 0) {
				break;
			}
		}


		if (j == i) {
			printf("%d ", i);
		}

	}

	return 0;
}