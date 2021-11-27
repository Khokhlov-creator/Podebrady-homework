#include <stdio.h>

int main()
{
	int i,j,c,x=0;
	if(scanf("%d",&c)!=1)
		{
			printf("Chyba!\n")
			;return 1;\
		}
	for(i=0;i<=c;i++)
		{
			j=-1;
			while(j<i)
				{		
					j++;		
				//	printf("%d, ",x);
					x+=j*3;
					
				}
		}
	printf("%d\n",x);return 0;
}
