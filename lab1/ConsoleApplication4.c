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
#include <malloc.h>

FILE* input, * output;
struct input1
{
	float a, b,  d;//Вводим переменные для работы с арифметическими операциями
	int k, m, j;
	char c, s, v, o;
	float *vv,*x,*y;//Вводим переменные для работы с векторами
	int size;
	struct input1 *next;
};
typedef struct input1 input1;
struct result{
	float d;
	struct result *next;
};
typedef struct result result;
long int faktorial(long int ss)
{
	if(ss==0 || ss==1) return 1;
	return ss*faktorial(ss-1);
}

void push(input1** head)
{
	
	input1 *list=(input1*)malloc(sizeof(input1));
	input1 *last=*head;

		fscanf(input,"%c",&list->v);
		fscanf(input,"%c",&list->c);
		if (list->v == 's')
		{
			fscanf(input,"%c",&list->c);
			if (list->c == '!')
			{
				fscanf(input,"%d",&list->k);
			}
			else if (list->c != '!')
			{
				fscanf(input,"%f",&list->a);
				fscanf(input,"%f",&list->b);
			}
		}else if (list->v == 'v')
		{
			fscanf(input, " %i", &list->size);
			list->x = malloc(list->size * sizeof(float));//Выделяем память
			list->y = malloc(list->size * sizeof(float));
			fscanf(input, " %c", &list->o);
			if (list->o == '+')
			{
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->x[i]);
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->y[i]);
			}
			else if (list->o == '*')
			{
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->x[i]);
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->y[i]);
			}
			else if (list->o == '-')
			{
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->x[i]);
				for (int i = 0; i < list->size; i++) fscanf(input,"%f", &list->y[i]);
			}
		}
	fscanf(input, " \n%c", &list->s);
	list->next = NULL;
	if(*head == NULL)
		{
			*head = list;
			return;
		}
	while(last->next != NULL)
		{
			last =last->next;
		}
	last->next=list;
	return;
}
void resault(input1** head1,float resfult)
{
	input1*list=(input1*) malloc(sizeof(input1));
	input1*last =*head1;

	list->d = resfult;
	list->next= NULL;
	if(*head1 == NULL)
	{
		*head1 =list;
		return;
	}
	while(last->next !=NULL)
	{
		last = last->next;
	}
	last->next = list;
	return;

}
void wektora(input1** head2,float *resault35)
{
	input1* list=(input1*) malloc(sizeof(input1));
	input1*last =*head2;

	list->vv = resault35;
	list->next= NULL;
	if(*head2 == NULL)
	{
		*head2 =list;
		return;
	}
	while(last->next !=NULL)
	{
		last = last->next;
	}
	last->next = list;
	return;
}
int main()
{
	float resfult36;
	
	input1* head;
	input1* current;
	input1* head1;
	input1* head2;
	input1* current2;
	input1* current1;
	head1=NULL;
	head2=NULL;
	current2=NULL;
	current1=NULL;
	head=NULL;
	current = NULL;
	
	input = fopen("input.txt", "r");
	while(feof(input)==0)
	{

		push(&head);

	}
	fclose(input);
	current= head;
	
		//fprintf(output, "С каким видом операций вы хотите работать?\nЕсли с арифметическим(-,+,/,*,!,^)введите цифру s.\nЕсли с векторным,введите v\n");
		if (current->v == 's')
		{
			//fprintf(output, "Введите операцию(-,+,*,/,^,!):\n");
			if (current->c == '!'){
				resfult36==faktorial(current->k);
				resault(&head1,resfult36);
		 	//fprintf(output, "Введите число для операции факториал:");
			// 	current->m = 1;

			// 	for (int j = 1; j <= current-> k; j++)//Считаем факториал
			// 	{
			// 		current->m =current-> m * j;
			// 	}
			// }else if (current->c != '!')//Считаем все остальные виды операций
			// {
			// 	///fprintf(output, "Введите первое число a:\n");
			// 	//fprintf(output, "Введите второе число b:\n");

				
					
			}else if(current->c == '+'){                            //Считаем сложение
					resfult36 =current-> a +current-> b;
					resault(&head1,resfult36);
				}
					
			else if(current->c == '-'){ //Считаем разность
					resfult36 =current-> a -current-> b;
					resault(&head1,resfult36);
					
				}
			else if(current->c == '/'){ //Считаем деление
					resfult36 =current-> a /current-> b;
					resault(&head1,resfult36);
					
				}
			else if(current->c == '*'){                                          
					resfult36 =current-> a * current->b;
					resault(&head1,resfult36);
					
				}
			else if(current->c == '^'){              //Считаем степень
					resfult36 = pow(current->a,current-> b);
					resault(&head1,resfult36);
				}
			}
		
		else if (current->v == 'v')//Если пользователь хочет работать с векторами
		{
			float *resault_wektor;
			resault_wektor=(float*) malloc(current->size * sizeof(float));
			float aa;
			//fprintf(output, "Введите размер векторов: ");
			//fprintf(output, "Введите операцию(+,-,*(скалярное произведение): ");
			if (current->o == '+')//Считаем сумму
			{
				//fprintf(output, "Введите первый вектор: ");
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i <current-> size; i++){

				 resault_wektor[i]=(current->x[i]) + (current->y[i]);
				}
                wektora(&head2,resault_wektor);
			}
			else if (current->o == '*')
			{
				//fprintf(output, "Введите первый вектор: ");
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i < current->size; i++)
				{
					 aa+=(current->x[i]) * (current->y[i]);
				}
				resault(&head1,aa);
				
			}
			else if (current->o == '-')
			{
				//fprintf(output, "Введите первый вектор: ");
				//fprintf(output, "Введите второй вектор: ");
				for (int i = 0; i < current->size; i++)
				{
					 (resault_wektor[i]=(current->x[i]) - (current->y[i]));
				}
				wektora(&head2,resault_wektor);	
			}
		}
		
	
	
	current1=head1;
    current2=head2;
	output = fopen("output.txt", "w");
	
	  if(current->v == 's')
	  {
	  	if(current->c=='+')
	  	{
			fprintf(output,"%f+%f=%f",current->a,current->b,current1->d);
	  	}
	  	else if(current->c=='-')
	  	{
	  		fprintf(output,"%f-%f=%f",current->a,current->b,current1->d);
	  	}
	  	else if(current->v=='/')
	  	{
	  		fprintf(output,"%f/%f=%f",current->a,current->b,current1->d);
	  	}
	  	else if(current->v=='*')
	  	{
	  		fprintf(output,"%f*%f=%f",current->a,current->b,current1->d);
	  	}
	  	else if(current->v=='^')
	  	{
	 		fprintf(output,"%f^%f=%f",current->a,current->b,current1->d);
	 	}
	  }
	  else if (current->v == 'v')
	  {
	  if (current->o == '+')//Считаем сумму
	  			{
	  				//fprintf(output, "Введите первый вектор: ");
	  				//fprintf(output, "Введите второй вектор: ");
	  				fprintf(output, "( ");
	  				for (int i = 0; i < current->size; i++) fprintf(output,"%f ",current->x[i]);
	  				fprintf(output, ")");
	  				fprintf(output,"+");
	  				fprintf(output, "( ");
	  				for (int i = 0; i < current->size; i++) fprintf(output,"%f ",current->y[i]);//Выполняем операцию
	  				fprintf(output, ")");
	  				fprintf(output, "=(");
	  				fprintf(output,"%f ",current2->vv);
	  				fprintf(output, ")");
	  				fprintf(output, "\n");
	  				free(current->x);//Очищаем память
	  				free(current->y);
	  			}
	  			else if (current->o == '*')
	  			{
	  				
	  				//fprintf(output, "Введите первый вектор: ");
	  				//fprintf(output, "Введите второй вектор: ");
	  				fprintf(output, "( ");
	  				for (int i = 0; i < current->size; i++) fprintf(output,"%f ",current->x[i]);
	  				fprintf(output, ")");
	  				fprintf(output,"*");
	  				fprintf(output, "( ");
	  				for (int i = 0; i <current-> size; i++) fprintf(output,"%f ",current->y[i]);//Выполняем операцию
	  				fprintf(output, ")");
	  				fprintf(output, "=(");
	  				fprintf(output,"%f ",current1->d);
	  				fprintf(output, ")");
	  				fprintf(output, "\n");
	  				free(current->x);//Очищаем память
	  				free(current->y);
					
	  			}
	  			else if (current->o == '-')
	  			{
	  				
	  				//fprintf(output, "Введите первый вектор: ");
	  				//fprintf(output, "Введите второй вектор: ");
	  				fprintf(output, "( ");
	  				for (int i = 0; i < current->size; i++) fprintf(output,"%f ",current->x[i]);
	  				fprintf(output, ")");
	  				fprintf(output,"-");
	  				fprintf(output, "( ");
	  				for (int i = 0; i < current->size; i++) fprintf(output,"%f ",current->y[i]);//Выполняем операцию
	  				fprintf(output, ")");
	  				fprintf(output, "=(");
	  				for (int i = 0; i < current->size; i++)fprintf(output,"%f ",current2->vv[i]);
	  				fprintf(output, ")");
	  				fprintf(output, "\n");
	  				free(current->x);//Очищаем память
	  				free(current->y);	
	  			}
	  		}
		fclose(output);
		
}

