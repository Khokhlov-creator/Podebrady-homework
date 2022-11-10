#include <stdio.h>
#include <math.h>
#include <malloc.h>

int fakt(int y){

	if (y == 0)
		return 1;
	return y * fakt(y - 1);

}

int outZnak(char a, int b, int c)
{
	if(a == '+')//ASCII 43 == "+"	
			{
				if(c!=b)
					printf(" + ");
			}
	if(a == '-')//ASCII 45 == "-"
			{
				if(c!=b&& c%2 == 0)
					printf(" - ");
				if(c!=b && c%2 !=0)
					printf(" + ");					
			}
}
	
int main()
{
	int x,n,l;
	char znak;
	printf("Zadej znak(+/-) a exponent(bez mezery napr: +3) :");
    scanf("%c%d",&znak,&n); 
    int k,tmp;
    l=n;
	for(k=0; k<=n; k++)
		{			
			tmp = (fakt(n)/(fakt(k)*(fakt(n-k))));
			if(tmp == 1)
				{
					if(l!=0 && k==0)
						printf("a^%d",l);
					if(l==0 && k!=0)
						printf("b^%d",k);
				}				
			else				
				printf("%d * a^%d * b^%d", tmp, l, k);
			outZnak(znak,n,k);
			l--;
		}
	return 0;
}
