#include <stdio.h>

int main() {

	int input;
	int i;
	int j;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}