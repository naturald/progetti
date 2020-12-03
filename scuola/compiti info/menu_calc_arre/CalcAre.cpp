//marco schiavello 3^Ci
//menu calcolatore aree
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../marcoLib.h";
#define P_GRECO 3.1415926535897932384626433 

void menu()
{
	system("cls");
	printf("Calcolatore aree\n\n");
	printf("1) Trinagolo\n\n");
	printf("2) Quadrato\n\n");
	printf("3) Cerchio\n\n");
	printf("scegli --> ");
}
float tri_area(int base,int alt)
{
	return (float)(base*alt)/2;
}
int quand_area(int lato)
{
	return (int)pow(lato,2);
}
float cerc_area(int raggio)
{
	return (float)(pow(raggio,2)*P_GRECO);
}
int main()
{
	int scelta,ope1,ope2;
	do
	{
		do
		{
			menu();
			scanf("%d",&scelta);	
		}
		while(scelta<1||scelta>5);
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				printf("inserisci base --> ");
				scanf("%d",&ope1);
				printf("inserisci altezza --> ");
				scanf("%d",&ope2);
				printf("%f", tri_area(ope1,ope2));
				getch();				
				break;	
			}
			case 2:
			{
				system("cls");
				printf("inserisci lato --> ");
				scanf("%d",&ope1);
				printf("%d",quand_area(ope1));
				getch();
				break;	
			}
			case 3:
			{
				system("cls");
				printf("inserisci raggio --> ");
				scanf("%d",&ope1);
				printf("%f",cerc_area(ope1));	
				getch();		
				break;	
			}
		}
	}
	while(scelta!=5);
}

