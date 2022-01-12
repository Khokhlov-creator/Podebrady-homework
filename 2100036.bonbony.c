
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX = 50

//Funkce pro random
int PrintRandoms(int lower, int upper, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %
			(upper - lower + 1)) + lower;
		return num;
	}
}

int main()
{

	int radek, sloupec, k;
	int* array;
	srand(time(0));
	printf("Zadej pocet sloupcu (x): ");
	if (scanf("%d", &sloupec) != 1)
	{
		printf("Chyba!");
		return 1;
	}
	printf("Zadej pocet radku (y): ");
	if (scanf("%d", &radek) != 1)
	{
		printf("Chyba!");
		return 2;
	}
	printf("Zadej cislo penez na nakup Kc: ");
	if (scanf("%d", &k) != 1)
	{
		printf("Chyba!");
		return 3;
	}

	array = (int*)malloc(sloupec * radek * sizeof(int));
	if (!array)
		return (NULL);
	int i, j, summ = 0;
	for (i = 0; i < radek; i++)
	{
		for (j = 0; j < sloupec; j++)
		{																			//Theese two work with Rand
		*(array + i * sloupec + j) = PrintRandoms(1, 5, radek * sloupec);	//printf("Zadej hodnotu bunky [%d][%d] = ", i, j);				//
			printf("array [%d][%d] =  %d  ", i, j, *(array + i * sloupec + j));//	if(scanf("%d", (array + i * sloupec + j))!=1)					//printf
			//{
			//	printf("Chyba!");
			//	return 4;
		//	}	
		}
	}
	printf("\n");
	for (i = 0; i < radek; i++)
	{
		for (j = 0; j < sloupec; j++)
		{
			printf("%5d ", *(array + i * sloupec + j));
		}
		printf("\n");
	}
	printf("\n");
	int ans = 0;
	int ans_left_x = -1, ans_left_y = -1, ans_right_x = -1, ans_right_y = -1;
	int x1, y1, x2, y2;
	int x, y, area, area_max = 0, count = 0, summ_max = 0;
	for (x1 = 0; x1 < radek; ++x1)
	{
		for (y1 = 0; y1 < sloupec; ++y1)
		{
			for (x2 = x1; x2 < radek; ++x2)
			{
				for (y2 = y1; y2 < sloupec; ++y2)
				{
					summ = 0;
					for (x = x1; x <= x2; ++x)
					{
						for (y = y1; y <= y2; ++y)
							summ += *(array + y * sloupec + x);
					}
					area = (x2 - x1 + 1) * (y2 - y1 + 1);
					if ((summ <= k) && (area >= ans))
					{
						ans = area;
						if (summ > summ_max)
						{
							summ_max = summ;
						}
					}						
				}
			}
			for (x2 = x1; x2 < radek; ++x2)
			{
				for (y2 = y1; y2 < sloupec; ++y2)
				{
					summ = 0;
					for (x = x1; x <= x2; ++x)
					{
						for (y = y1; y <= y2; ++y)
							summ += *(array + y * sloupec + x);
					}
					area = (x2 - x1 + 1) * (y2 - y1 + 1);
					if ((summ <= k) && (area == ans))
					{
						if (summ <= k && summ == summ_max)	
							count++;
					}
				}
			}
		}
	}
	printf("Reseni - cena za bonbony: %d Kc, pocet bonbonu: %d , pocet reseni: %d  \n souradnice oblasti vyberu bonbonu [Sloupec, Radek] - [Sloupec, Radek]:\n", summ_max, ans, count);
	ans = 0;
	area_max = 0, count = 0, summ_max = 0;
	for (x1 = 0; x1 < radek; ++x1)
	{
		for (y1 = 0; y1 < sloupec; ++y1)
		{
			for (x2 = x1; x2 < radek; ++x2)
			{
				for (y2 = y1; y2 < sloupec; ++y2)
				{
					summ = 0;
					for (x = x1; x <= x2; ++x)
					{
						for (y = y1; y <= y2; ++y)
							summ += *(array + y * sloupec + x);
					}
					area = (x2 - x1 + 1) * (y2 - y1 + 1);
					if ((summ <= k) && (area >= ans))
					{
						ans = area;
						if (summ > summ_max)
						{
							summ_max = summ;
						}
					}
				}
			}
			for (x2 = x1; x2 < radek; ++x2)
			{
				for (y2 = y1; y2 < sloupec; ++y2)
				{
					summ = 0;
					for (x = x1; x <= x2; ++x)
					{
						for (y = y1; y <= y2; ++y)
							summ += *(array + y * sloupec + x);
					}
					area = (x2 - x1 + 1) * (y2 - y1 + 1);
					if ((summ <= k) && (area == ans))
					{

						ans_left_x = x1;
						ans_left_y = y1;
						ans_right_x = x2;
						ans_right_y = y2;
						if (summ <= k && summ == summ_max)
						{
							printf("[%d , %d] - [%d , %d] \n", ans_left_y, ans_left_x, ans_right_y, ans_right_x);
							count++;
						}

					}
				}
			}
		}
	}
	free(array);
	return 0;
}

