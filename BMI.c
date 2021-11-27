#include <stdio.h>
#include <math.h>

void BMI(float x, float y);

void BMI(float x, float y)
{
	printf("Tvuj BMI je = %.2f\n", x/(y*y)+fmod(x,y*y));
	if(x/(y*y)+fmod(x,y*y)<18.5)
				printf("Mas podvahu!");
	if((x/(y*y)+fmod(x,y*y)>=18.5) && (x/(y*y)+fmod(x,y*y)<=25))
				printf("Jsi OK!");
	if(x/(y*y)+fmod(x,y*y)>25)
				printf("Mas nadvahu!");								
}

int main()
{
	float Vyska, Hmotnost;
	
	printf("Input your hmotnost(KG): ");
	if(scanf("%f",&Hmotnost)!=1||(Hmotnost <20)||(Hmotnost >199))
	{
		printf("Chyba");
		return 1;
	}
	
	printf("\nInput your vyska(M): ");
	if(scanf("%f",&Vyska)!=1||(Vyska <0)||(Vyska >2.4))
	{
		printf("Chyba");
		return 1;
	}
	printf("\n");	
	BMI(Hmotnost,Vyska);	
	return 0;	
}
