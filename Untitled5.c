#include <stdio.h>

int main(void)
{
printf("Zadej cele cislo ");
int c;
if (scanf("%d",&c)!=1)
{
printf("Chyba!\n");
return 1;
}
int i,a,b,t,d;
int x=0;

for (i = 2; i <10; i++)
    if(c % i == 0)
{
    if(i==2)
      a++;
    if(i==3)
      b++;
    if(i==5)
      t++;
    if(i==7)
      d++; 
    x++;
    }
	if(x>0)	
	{
		printf("Cislo je delitne ");
		if(a>0)
			printf("2, ");
		if(b>0)
			printf("3, ");
		if(t>0)
			printf("5, ");
		if(d>0)
			printf("7, ");
	}

  else   
    printf("Cislo neni delitelne\n");
    
   
    printf("\n");  
return 0;
}
