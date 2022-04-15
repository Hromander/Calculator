#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");

	double a, b, d, i, f, g, e, h, w;
	int k, m, j;
	char c, s;
	do
	{
		printf("Введите операцию(-,+,*,/,^,!):\n");
		scanf(" %c", &c);
		if (c == '!')
		{
			printf("Введите число для операции факториал:");
			scanf("%d", &k);
			m = 1;

			for (int j = 1; j <= k; j++)
			{
				m = m * j;
			}

			printf("Результат:%d", m);
		}
		else if (c != '!')
		{
			printf("Введите первое число a:\n");
			scanf("%lf", &a);
			printf("Введите второе число b:\n");
			scanf("%lf", &b);

			switch (c)
			{
			case '+':
				d = a + b;
				printf("Результат:%lf", d);
				break;
			case'-':
				i = a - b;
				printf("Результат:%lf", i);
				break;
			case'/':
				g = a / b;
				printf("Результат:%lf", g);
				break;
			case'*':
				f = a * b;
				printf("Результат:%lf", f);
				break;
			case'^':
				w = pow(a, b);
				printf("Результат:%lf", w);
				break;
			}
		}
		printf("\nПродолжить?Если да введите любую букву кроме n,если нет введите n:");
		scanf(" %c", &s);
	} while (s != 'n');
	return 0;
}

