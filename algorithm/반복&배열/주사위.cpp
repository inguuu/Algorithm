#include <stdio.h>

int main() {

	int A[1000][3];
	int size;
	int m[1000];

	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < size; i++) {
		if (A[i][0] == A[i][1] && A[i][1] == A[i][2] && A[i][0] == A[i][2]) {
			m[i] = 10000 + (A[i][1] * 1000);
		}
		else if (A[i][0] == A[i][1]) {
			m[i] = 1000 + (A[i][0] * 100);
		}
		else if (A[i][1] == A[i][2]) {
			m[i] = 1000 + (A[i][1] * 100);
		}
		else if (A[i][0] == A[i][2]) {
			m[i] = 1000 + (A[i][0] * 100);
		}
		else {
			m[i] = A[i][0];
			for (int j = 1; j < 3; j++) {
				if (A[i][j] > m[i])m[i] = A[i][j];
			}

		}
		if (m[i] > max) {
			max = m[i];
		}
	}

	printf("%d", max);
	return 0;
}