#include <stdio.h>

int main() {

	int i;
	int j;
	int input;

	scanf("%d", &input);

	for (int i = 0; i < input; i++) {

		for (int j = 0; j < input - i - 1; j++) {
			printf(" ");
		}
		for (int j = input - i - 1; j < input; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}