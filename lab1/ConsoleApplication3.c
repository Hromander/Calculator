﻿//Автор Татьяна Хромина
//Лицензия GNU GPL
//Код калькулятора
//Калькулятор способен считать со знаками после запятой
//Оперций в калькуляторе 6:
//степень,факториал,сумма,разность,деление,умножение#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");

	double a, b, d, i, f, g, e, h, w;
	int k, m, j;
	char c, s, v, o;
	float *x,*y,*res;
	int size;
	do
	{
		printf("С каким видом операций вы хотите работать?\nЕсли с арифметическим(-,+,/,*,!,^)введите цифру 1.\nЕсли с векторным,введите 2\n");
		scanf(" %c", &v);
		if (v == '1')
		{
			printf("Введите операцию(-,+,*,/,^,!):\n");
			scanf(" %c", &c);
			if (c == '!')
			{
				printf("Введите число для операции факториал:");
				scanf(" %d", &k);
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
		}
		else if (v == '2')
		{
			printf("Введите размер векторов: ");
			scanf(" %i", &size);
			printf("Введите операцию(+,-,*(скалярное произведение): ");
			scanf(" %c", &o);
			if (o == '+')
			{
				x=malloc(size*sizeof(int));
				y=malloc(size*sizeof(int));
				res=malloc(size * sizeof(int));
				printf("Введите первый вектор: ");
				for (int i = 0; i <size; i++) scanf("%f", &x[i]);
				printf("Введите второй вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &y[i]);
				printf("Результат: ");
				for (int i = 0; i < size; i++) scanf("%f ",x[i]+y[i]);
				printf("\n");
				free(x);
				free(y);
				free(res);
			}

		}
		printf("\nПродолжить?Если да введите любую букву кроме n,если нет введите n:");
		scanf(" %c", &s);
	} while (s != 'n');
	return 0;
}

