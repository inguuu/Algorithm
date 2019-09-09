#include <stdio.h>

int main() {

	int a[10];
	int b[10];

	int ca = 0;
	int cb = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			++ca;
			continue;
		}
		if (b[i] > a[i]) {
			++cb;
			continue;
		}
	}

	if (ca > cb)printf("A");
	else if (cb > ca)printf("B");
	else if (cb == ca)printf("D");

	return 0;
}