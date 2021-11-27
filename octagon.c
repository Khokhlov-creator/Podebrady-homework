#include <stdio.h>

int main()
{
	int xstart, x1, x2, xend, ystart, y1, y2, yend,a;
	int i, j;
	
	printf("input your coordinates of the main coordinates x0 and y0 \n");
	scanf("%d %d", &xstart, &ystart);
	printf("\n input x1 and y1 \n ");
	scanf("%d %d", &x1, &y1);
	printf("\n input x2, y2 \n");
	scanf("%d %d", &x2, &y2);
	printf("\n input the end coordinates of octangular \n");
	scanf("%d %d", &xend, &yend);
	
	for(i=0; i<xend; i++)
			{
				if(i<(x1) || i>(x2))
								printf("%c",32);
				else
					printf("%c",196);
			}			
	printf("\n");
	for(j=0; j<y1; j++)
	{
		for(i=0; i<xend;i++)
			{
				a++;
				if(i==(x1-a))
					printf("%c", 47);
				if(i==(a+x2))	
					printf("%c", 47);
				if(i<(x1-a)||(i>(x1-a)&&i<(x2+a))||i>(x2+a))
					printf("%c", 32);
				
				if((x1-a)==xstart)
					break;	
						
			}
	}
		
}
