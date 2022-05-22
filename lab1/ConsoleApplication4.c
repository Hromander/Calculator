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
	FILE* input, * output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");


	double a, b, d, i, f, g, e, h, w;//Вводим переменные для работы с арифметическими операциями
	int k, m, j;
	char c, s, v, o;
	float *x,*y;//Вводим переменные для работы с векторами
	int size;
	do
	{
		//fprintf(output, "С каким видом операций вы хотите работать?\nЕсли с арифметическим(-,+,/,*,!,^)введите цифру s.\nЕсли с векторным,введите v\n");
		fscanf(input, " %c", &v);
		if (v == 's')
		{
			//fprintf(output, "Введите операцию(-,+,*,/,^,!):\n");
			fscanf(input, " %c", &c);
			if (c == '!')
			{
				//fprintf(output, "Введите число для операции факториал:");
				fscanf(input, " %d", &k);
				m = 1;

				for (int j = 1; j <= k; j++)//Считаем факториал
				{
					m = m * j;
				}

				fprintf(output, "%d!=%d",k, m);
			}
			else if (c != '!')//Считаем все остальные виды операций
			{
				///fprintf(output, "Введите первое число a:\n");
				fscanf(input, "%lf", &a);
				//fprintf(output, "Введите второе число b:\n");
				fscanf(input, "%lf", &b);

				switch (c)
				{
				case '+'://Считаем сложение
					d = a + b;
					fprintf(output, "%lf+%lf=%lf",a,b,d);
					break;
				case'-'://Считаем разность
					i = a - b;
					fprintf(output, "%lf-%lf=%lf",a,b,i);
					break;
				case'/'://Считаем деление
					g = a / b;
					fprintf(output, "%lf/%lf=%lf",a,b,g);
					break;
				case'*'://Считаем умножение
					f = a * b;
					fprintf(output, "%lf*%lf=%lf",a,b,f);
					break;
				case'^'://Считаем степень
					w = pow(a, b);
					fprintf(output, "%lf^%lf=%lf",a,b,w);
					break;
				}
			}
		}
		else if (v == 'v')//Если пользователь хочет работать с векторами
		{
			//fprintf(output, "Введите размер векторов: ");
			fscanf(input, " %i", &size);
			//fprintf(output, "Введите операцию(+,-,*(скалярное произведение): ");
			fscanf(input, " %c", &o);
			if (o == '+')//Считаем сумму
			{
				x = malloc(size * sizeof(float));//Выделяем память
				y = malloc(size * sizeof(float));
				//fprintf(output, "Введите первый вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &x[i]);
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &y[i]);
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",x[i]);
				fprintf(output, ")");
				fprintf(output,"+");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",y[i]);//Выполняем операцию
				fprintf(output, ")");
				fprintf(output, "=(");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",(x[i]) + (y[i]));
				fprintf(output, ")");
				fprintf(output, "\n");
				free(x);//Очищаем память
				free(y);
			}
			else if (o == '*')
			{
				x = malloc(size * sizeof(float));//Выделяем память
				y = malloc(size * sizeof(float));
				//fprintf(output, "Введите первый вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &x[i]);
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &y[i]);
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",x[i]);
				fprintf(output, ")");
				fprintf(output,"*");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",y[i]);//Выполняем операцию
				fprintf(output, ")");
				fprintf(output, "=(");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",(x[i]) * (y[i]));
				fprintf(output, ")");
				fprintf(output, "\n");
				free(x);//Очищаем память
				free(y);
				
			}
			else if (o == '-')
			{
				x = malloc(size * sizeof(float));//Выделяем память
				y = malloc(size * sizeof(float));
				//fprintf(output, "Введите первый вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &x[i]);
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i < size; i++) fscanf(input,"%f", &y[i]);
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",x[i]);
				fprintf(output, ")");
				fprintf(output,"-");
				fprintf(output, "( ");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",y[i]);//Выполняем операцию
				fprintf(output, ")");
				fprintf(output, "=(");
				for (int i = 0; i < size; i++) fprintf(output,"%f ",(x[i]) - (y[i]));
				fprintf(output, ")");
				fprintf(output, "\n");
				free(x);//Очищаем память
				free(y);
				
			}

		}
		//fprintf(output, "\nПродолжить?Если да введите любую букву кроме n,если нет введите n:");
		fscanf(input, " \n%c", &s);
	} while (s != 'n');//Заканчиваем цикл,если пользователь вводит букву n
	fclose(input);
	fclose(output);
	return 0;
}