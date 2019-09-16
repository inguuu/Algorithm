#include <stdio.h>
#include <string.h>

int main() {

	char a[101] = { 0, };
	char b[101] = { 0, };
	int result[102] = { 0, };

	scanf("%s", a);
	scanf("%s", b);

	int lena = strlen(a);
	int lenb = strlen(b);

	int size;
	int min;
	if (lena >= lenb) {
		size = lena;
		min = lenb;
	}
	else {
		size = lenb;
		min = lena;
	}

	for (int i = 0; i < lena / 2; i++) {
		char val = a[i];
		a[i] = a[lena - i - 1];
		a[lena - i - 1] = val;

	}
	for (int i = 0; i < lenb / 2; i++) {
		char val = b[i];
		b[i] = b[lenb - i - 1];
		b[lenb - i - 1] = val;
	}

	int carry = 0;
	for (int i = 0; i < size; i++) {
		if (i >= min) {
			if (carry + (a[i] - '0') + b[i] > 9) {
				result[i] = (a[i] - '0') + b[i] + carry - 10;
				carry = 1;

			}
			else {
				result[i] = (a[i] - '0') + b[i] + carry;
				carry = 0;
			}

		}
		else {

			if (carry + (a[i] - '0') + (b[i] - '0') > 9) {
				result[i] = (a[i] - '0') + (b[i] - '0') + carry - 10;
				carry = 1;
			}
			else {
				result[i] = (a[i] - '0') + (b[i] - '0') + carry;
				carry = 0;
			}
		}

	}
	if (carry == 1) {
		result[size] = 1;
		for (int i = size; i >= 0; i--) {
			printf("%d", result[i]);
		}
	}
	else {
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", result[i]);
		}
	}












	return 0;
}