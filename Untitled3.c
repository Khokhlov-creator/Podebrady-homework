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
	
	int count[10],count_all=0,i;
	for(i=1; i<10; i++)
		count[i]=0;
		
	for(i=1;i<10;i++)
	{
		if(c%i==0)
			{
				if(i==2)
					count[2]++;
				if(i==3)
					count[3]++;
				if(i==5)
					count[5]++;
				if(i==7)
					count[7]++;				
			}
	count_all=count[2]+count[3]+count[5]+count[7];
	}
	if(count_all>0)
		{
			printf("Cislo je delitelne ");
			for(i=2;i<10;i++)
				{
					if(count[i]!=0)
						printf(" %d,", i);
				}		
		}
	else
		printf("Cislo je ne delitelne");
	printf("\n");	
	return 0;	
}
	
	
