#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
	long int a, i, c, count = 1;

	int* prv;

	if ((scanf("%ld", &a) != 1))
	{
		printf("Chyba!\n");
		return 1;
	}
	prv = (int*)malloc(i * sizeof(long int));
	c = a;
	printf("%ld -> ", a);
	for (i = 2; i <= a; i++)
	{
		prv = (int*)realloc(prv, i * sizeof(long int));
		prv[i] = 0;
		while ((a % i == 0) && (a > 0))
		{
			a = a / i;
			prv[i]++;
		}
		if(prv[i]>0 && count==2)
					printf(" * %d",i);
		if(prv[i]>0 && count == 1)
			{
				printf("%d", i);
				count=2;
			}	
		
		if(prv[i]>1)
			printf("^%d ",prv[i]);	
	}

	free(prv);
}

