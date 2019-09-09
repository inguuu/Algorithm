#include <stdio.h>

int main()
{

	int n;
	int s = 1;
	int num;
	int inc = 1;
	int sinc = 2;
	int iinc = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		num = s;
		for (int j = 0; j < n - i; j++)
		{
			printf("%d ", num);
			num = num + inc;
			++inc;
		}
		inc = 1;
		inc = inc + iinc;
		s = sinc + s;
		++sinc;
		++iinc;
		printf("\n");
	}

	return 0;
}