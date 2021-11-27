#include <stdio.h>

int main()
{
	printf("Zadej cele cislo ");
	int c;
	if (scanf("%d",&c)!=1)
	{
		printf("Chyba!\n");
		return 1;
	}
	int deliteli[]={2,3,5,7};
	int deliteli_output[4];
	int count, i;
	
	for(i=0;i<=3;i++)
				{
					if(c%deliteli[i]==0)
							{
								if(deliteli_output[i-1]==0 && i>=1)
									{
										deliteli_output[i-1]=deliteli[i];
										deliteli_output[i]=0;										
									}									
								else
									deliteli_output[i]=deliteli[i];
								count++;
							}									
				}
	if(count>0)
		{
			printf("Cislo je delitelne ");
			for(i=0;i<count;i++)
						printf("%d, ",deliteli_output[i]);
		}
	else
		printf("Cislo neni delitelne");
	printf("\n");
	return 0;
}
