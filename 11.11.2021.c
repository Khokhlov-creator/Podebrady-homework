#include <stdio.h>

int main()
{
	int x1,x2,y1,y2;
	int i,dist, j;
	
	printf("Put your coordinates x1, y1, x2, y2:");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if(x2>80||x1>80||x2<x1||y2<y1||y2>80||y1>80||x1<=0||x2<=0||y1<=0||y2<=0)			//exception pro DEBILA
		{
			printf("Upolny debil");
			return 0;
		}
	for(i=1; i<=x1-1; i++)
			printf("%c", 32);		
	printf("%c",218);			//Print the left to corner of our figure
	for(i=x1; i<x2-1; i++)
				printf("%c",196);		//print top side of the figure	
	printf("%c\n",191);					// print the right top corner of figure
	
	for(j=y1+1; j<y2-1; j++)			//ciklus where we find the height of our figure	
		{
			for(i=1; i<=x1-1; i++)
					printf("%c", 32);
			printf("%c", 179);			//print the left wall of one line
			for(dist=x1+1; dist<=x2-1; dist++)		//ciklus for filling the void inside the figure
								printf("%c", 32);
			printf("%c\n", 179);		//print the right wall of this line
		}
	
	for(i=1; i<=x1-1; i++)
			printf("%c", 32);	
	printf("%c", 192);					//print the left bottom corner of our figure	
	for(i=x1; i<x2-1; i++)
				printf("%c",196);		//print the bottom side of figure
	printf("%c", 217);					//print the right bottom corner of our figure

	return 0;
}
