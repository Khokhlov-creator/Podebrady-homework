#include <stdio.h>

int main()
{
	float a,b,i;
	printf ("zadey svoji hmotnost (kg) a pak vysku (m): ");
	if((scanf("%f", &a)!=1)||(scanf("%f",&b)!=1)||a<20||a>199||b<1||b>2.4)
		{
			printf("Chyba!!!111!!!!1!1");
			return 1;
		}
	i=(a/(b*b));
	printf("\n Tvoje BMI je = %f\n", i);
	if(i<18.5)
		printf("Mas povahu!");
	if(i>18.5&&i<25)
		printf("Jsi Ok!");
	if(i>25)
		printf("Mas nadvahu!");
	return 0;
}
