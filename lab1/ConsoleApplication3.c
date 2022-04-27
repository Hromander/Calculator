//Автор Татьяна Хромина
//Лицензия GNU GPL
//Код калькулятора
//Калькулятор способен считать со знаками после запятой
//Оперций в калькуляторе 9:
//степень,факториал,сумма,разность,деление,умножение,векторное сложение и разность,склярное произведение веторов.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251");

	double a, b, d, i, f, g, e, h, w;//Вводим переменные для работы с арифметическими операциями
	int k, m, j;
	char c, s, v, o;
	float* x, * y, * res;//Вводим переменные для работы с векторами
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

				for (int j = 1; j <= k; j++)//Считаем факториал
				{
					m = m * j;
				}

				printf("Результат:%d", m);
			}
			else if (c != '!')//Считаем все остальные виды операций
			{
				printf("Введите первое число a:\n");
				scanf("%lf", &a);
				printf("Введите второе число b:\n");
				scanf("%lf", &b);

				switch (c)
				{
				case '+'://Считаем сложение
					d = a + b;
					printf("Результат:%lf", d);
					break;
				case'-'://Считаем разность
					i = a - b;
					printf("Результат:%lf", i);
					break;
				case'/'://Считаем деление
					g = a / b;
					printf("Результат:%lf", g);
					break;
				case'*'://Считаем умножение
					f = a * b;
					printf("Результат:%lf", f);
					break;
				case'^'://Считаем степень
					w = pow(a, b);
					printf("Результат:%lf", w);
					break;
				}
			}
		}
		else if (v == '2')//Если пользователь хочет работать с векторами
		{
			printf("Введите размер векторов: ");
			scanf(" %i", &size);
			printf("Введите операцию(+,-,*(скалярное произведение): ");
			scanf(" %c", &o);
			if (o == '+')//Считаем сумму
			{
				x = malloc(size * sizeof(int));//Выделяем память
				y = malloc(size * sizeof(int));
				res = malloc(size * sizeof(int));
				printf("Введите первый вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &x[i]);
				printf("Введите второй вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &y[i]);
				printf("Результат: ");
				for (int i = 0; i < size; i++) printf("%f ", x[i] + y[i]);//Выполняем операцию
				printf("\n");
				free(x);//Очищаем память
				free(y);
				free(res);
			}
			else if (o == '*')
			{
				x = malloc(size * sizeof(int));//Выделяем память
				y = malloc(size * sizeof(int));
				res = malloc(size * sizeof(int));
				printf("Введите первый вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &x[i]);
				printf("Введите второй вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &y[i]);
				printf("Результат: ");
				for (int i = 0; i < size; i++) printf("%f ", x[i] * y[i]);//Выполняем операцию
				printf("\n");
				free(x);//Очищаем память
				free(y);
				free(res);
			}
			else if (o == '-')
			{
				x = malloc(size * sizeof(int));//Выделяем память
				y = malloc(size * sizeof(int));
				res = malloc(size * sizeof(int));
				printf("Введите первый вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &x[i]);
				printf("Введите второй вектор: ");
				for (int i = 0; i < size; i++) scanf("%f", &y[i]);
				printf("Результат: ");
				for (int i = 0; i < size; i++) printf("%f ", x[i] - y[i]);//Выполняем операцию
				printf("\n");
				free(x);//Очищаем память
				free(y);
				free(res);
			}

		}
		printf("\nПродолжить?Если да введите любую букву кроме n,если нет введите n:");
		scanf(" \n%c", &s);
	} while (s != 'n');//Заканчиваем цикл,если пользователь вводит букву n
	return 0;
}

