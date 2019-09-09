#include <stdio.h>

int main()
{

	int n, s;

	scanf("%d", &n);
	scanf("%d", &s);
	int num;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1 - i; k++)
		{
			printf(" ");
		}
		num = s;
		for (int j = 0; j < 2 * i + 1; j++)
		{
			if (i % 2 == 0)
			{
				printf("%d", num);
				if (j == 2 * i)
				{
					if (s == 9)
					{
						s = 1;
					}
					else
					{
						++s;
					}
				}
				else
				{
					if (num <= 1)
					{
						num = 9;
					}
					else
					{
						--num;
					}
				}

			} //감소
			if (i % 2 == 1)
			{
				printf("%d", num);
				if (j == 2 * i)
				{
					if (s + 4 * i + 3 > 9)
					{
						s = (s + 4 * i + 3) % 9;
					}
					else
					{
						s = s + 4 * i + 3;
					}
				}
				else
				{
					if (num == 9)
					{
						num = 1;
					}
					else
					{
						++num;
					}
				}
			} //증가
		}
		printf("\n");
	}

	return 0;
}