#include <stdio.h>

int main() {

	int a[10];
	int min[1];
	int idx[1];

	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}

	if (a[0] < a[1]) {
		min[0] = a[0];
		min[1] = a[1];
		idx[0] = 0;
		idx[1] = 1;
	}
	else {
		min[0] = a[1];
		min[1] = a[0];
		idx[0] = 1;
		idx[1] = 0;
	}

	for (int i = 2; i < 9; i++) {

		if (a[i] < min[0]) {
			int val = min[0];
			int ni = idx[0];
			min[0] = a[i];
			min[1] = val;
			idx[0] = i;
			idx[1] = ni;
			continue;
		}

		if (a[i] < min[1]) {
			min[1] = a[i];
			idx[1] = i;
		}

	}

	printf("%d\n", min[1]);
	printf("%d", idx[1] + 1);

	return 0;
}