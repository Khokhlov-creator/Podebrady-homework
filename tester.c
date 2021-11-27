#include <stdio.h>

int VstupKG (float *prom)
{
	printf("Zadej svoji hmotnost [kg]: "); 
	if((scanf("%f",prom) != 1) || (*prom <= 1) || (*prom > 199)||(getchar()!='\n')) return 1; else return 0;
}

int VstupM (float *prom)
{
	printf("Zadej svoji vysku [m]: ");
	if((scanf("%f",prom) != 1) || (*prom < 1) || (*prom > 2.4)||(getchar()!='\n')) return 1; else return 0;
}

void Vystup (float kg, float m)
{
	float BMI;
	BMI=kg/(m*m);
	printf("Tvuj BMI je %.2f\n", BMI);
	if (BMI<18.5) printf("Mas podvahu!"); else if (BMI<=25) printf("Jsi OK!"); else printf("Mas nadvahu!");
}

int main (void)
{
	float M, KG;
	if (VstupKG(&KG)) {printf("Chyba!");return 1;}
	if (VstupM(&M)) {printf("Chyba!");return 1;}
	Vystup(KG,M);
	return 0;
} 
