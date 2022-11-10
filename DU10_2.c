#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATUM
{
	int Den;
	int Mesic;
	int Rok;
	int Hodina;
	int Minuta;
	int Secunda;
};

int diff_find(int den, int b_1, int c_1, int d_1, int b_2, int c_2, int d_2)//A - den.1, B - Hodina.1, C - Minuta.1, D - Sekunda.1      ''''1 - max''''
{
	int tmp, hodina, minuta, sekunda, pointer_b = 1, pointer_c=1;	
	if(b_1 < b_2)
		{
			tmp = 24;
			den--;
			hodina = tmp-b_2+b_1;
		}
	else
		if(b_1 > b_2)
			hodina = b_1-b_2;
		else
			if(b_1==b_2)
				{
					hodina = 0;
					pointer_b = 0;
				}				
	if(c_1 < c_2)
		{
			tmp = 60;
			if(pointer_b!=0)
				hodina --;
			else
				{
					den--;
					hodina=23;
					pointer_b = 1;
				}
			minuta = tmp-c_2+c_1;
		}
	else
		if(c_1>c_2)
			minuta=c_1-c_2;
		else
			if(c_1==c_2)
				{
					minuta=0;
					pointer_c=0;
				}				
	if(d_1 < d_2)
		{
			tmp=60;
			if(pointer_b!=0)
				{
					if(pointer_c!=0)
						minuta--;
					else
						{
							hodina--;
							minuta=59;
						}
					
				}
			else
				{
					if(pointer_c!=0)
						minuta--;
					else
						{
							den--;
							hodina=23;
							minuta=59;
						}					
				}
			sekunda=tmp-d_2+d_1;				
		}	
	else
		if(d_1>d_2)
			sekunda = d_1-d_2;
		else
			if(d_1==d_2)
				{
					sekunda=0;
				}		
	printf("Rozdil je %d dnu, %d hodin, %d minut, %d sekund ", den, hodina, minuta, sekunda);
}

int main()
{
	struct DATUM datum1, datum2;
	int min=10000000, max =0;
	int tmp_den, tmp_rok, tmp, summ_rok;
	printf("Zadej cas (ve formatu DD.MM.RRRR HH:MM:SS): ");
	scanf("%d.%d.%d %d:%d:%d", &datum1.Den , &datum1.Mesic , &datum1.Rok , &datum1.Hodina , &datum1.Minuta, &datum1.Secunda);
	if((datum1.Den > 31)||(datum1.Den <1)||(datum1.Mesic <1)||(datum1.Mesic >12)||(datum1.Rok <1)||(datum1.Rok >9999)||(datum1.Hodina <0)||(datum1.Hodina >23)||(datum1.Minuta <0)||(datum1.Minuta >59)||(datum1.Secunda <0)||(datum1.Secunda >59) )
		{
			printf("Chyba vstupu 1 data!");
			return 1;
		}
	printf("Zadej cas (ve formatu DD.MM.RRRR HH:MM:SS): ");
	scanf("%d.%d.%d %d:%d:%d", &datum2.Den , &datum2.Mesic , &datum2.Rok , &datum2.Hodina , &datum2.Minuta, &datum2.Secunda);
	if((datum2.Den > 31)||(datum2.Den <1)||(datum2.Mesic <1)||(datum2.Mesic >12)||(datum2.Rok <1)||(datum2.Rok >9999)||(datum2.Hodina <0)||(datum2.Hodina >23)||(datum2.Minuta <0)||(datum2.Minuta >59)||(datum2.Secunda <0)||(datum2.Secunda >59) )
		{
			printf("Chyba vstupu 2 data!");
			return 2;
		}
	int mesic_runn[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int mesic_ne_runn[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int Max_ptr;
	if(datum1.Rok > datum2.Rok )
		{
			min = datum2.Rok;
			max = datum1.Rok;
			Max_ptr=1;
		}
	else
		{
			min = datum1.Rok;
			max = datum2.Rok;
			Max_ptr=2;	
		}
	
	tmp = min;
	int i,j;
    
	int days1,days2;
	days1=days2=0;

	for(i=1; i<datum1.Rok;i++)
	{
	if((i%4==0&&i%400!=0)||(i%100==0))
	days1++;
	}

	int month_day1=0;
	if((datum1.Rok%4==0||datum1.Rok%400==0)&&(datum1.Rok%100!=0))
		{
			for(j=0;j<datum1.Mesic ;j++)
				{
					month_day1=month_day1+mesic_runn[j];
				}
		}
	else
		{
			for(j=0;j<datum1.Mesic ;j++)
				{
					month_day1=month_day1+mesic_ne_runn[j];
				}
		}
	days1=(datum1.Rok-1)*365+days1+month_day1+datum1.Den;


	for( i=1; i<datum2.Rok;i++)
		{
			if((i%4==0&&i%400!=0)||(i%100==0))
			days2++;
		}

	int month_day2=0;
	if((datum2.Rok%4==0||datum2.Rok%400==0)&&(datum2.Rok%100!=0))
		{
			for( j=0;j<datum2.Mesic;j++)
			{
				month_day2=month_day2+mesic_runn[j];
			}
		}
	else
		{
			for(j=0;j<datum2.Mesic;j++)
			{
				month_day2=month_day2+mesic_ne_runn[j];
			}
		}
	days2=(datum2.Rok-1)*365+days2+month_day2+datum2.Den;

	
	
	if(datum1.Rok != datum2.Rok )
		{
			while(min % 4 != 0 && min%400!=0)
				{
					min++;
					i++;
				}
			while(max%4!=0 && max%400!=0)
				{
					max--;
					i++;
				}
			tmp = (max - min)/4;
			tmp_rok = max - min - tmp;
			tmp = tmp*366;
			summ_rok = tmp + tmp_rok*365 + i*365;
		}
	
	
	printf("\n");
	if(Max_ptr==1)
		diff_find(days1-days2, datum1.Hodina, datum1.Minuta, datum1.Secunda, datum2.Hodina, datum2.Minuta, datum2.Secunda);
	else
		if(Max_ptr==2)
			diff_find(days2-days1, datum2.Hodina, datum2.Minuta, datum2.Secunda, datum1.Hodina, datum1.Minuta, datum1.Secunda);
		
		
	
	printf("\n");
	printf("%d.%d.%d %d:%d:%d", datum1.Den , datum1.Mesic , datum1.Rok , datum1.Hodina , datum1.Minuta, datum1.Secunda);
	printf("\n");
	printf("%d.%d.%d %d:%d:%d", datum2.Den , datum2.Mesic , datum2.Rok , datum2.Hodina , datum2.Minuta, datum2.Secunda);
	printf("\n");
	
	
	printf("%d - min, %d - max,   %d  - i,    summ -> %d", min, max, i, summ_rok+1);
}
