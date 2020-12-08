//marco schiavello 3^Ci 2/12/2020
//menu calcolatrice
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
int ope1,ope2;

void somma()
{
	system("cls");
	printf("inserisci primo operando --> ");
	scanf("%d",&ope1);
	printf("inserisci secondo operando --> ");
	scanf("%d",&ope2);
	printf("%d + %d = %d",ope1,ope2,ope1+ope2);
}
void sottrazione()
{
	system("cls");
	printf("inserisci primo operando --> ");
	scanf("%d",&ope1);
	printf("inserisci secondo operando --> ");
	scanf("%d",&ope2);
	printf("%d - %d = %d",ope1,ope2,ope1-ope2);
}
void moltiplicazione()
{
	system("cls");
	printf("inserisci primo operando --> ");
	scanf("%d",&ope1);
	printf("inserisci secondo operando --> ");
	scanf("%d",&ope2);
	printf("%d * %d = %d",ope1,ope2,ope1*ope2);	
}
void divisione()
{
	system("cls");
	printf("inserisci primo operando --> ");
	scanf("%d",&ope1);
	printf("inserisci secondo operando --> ");
	scanf("%d",&ope2);
	printf("%d / %d = %d",ope1,ope2,ope1/ope2);		
}
int menu()
{
	int scelta;
	do
	{
		system("cls");
		printf("Calcolatrice\n\n");
		printf("1) Somma\n\n");
		printf("2) Sottrazione\n\n");
		printf("3) Moltiplicazione\n\n");
		printf("4) Divisione\n\n");
		printf("5) Esci\n\n");
		printf("scegli --> ");
		scanf("%d",&scelta);	
	}
	while(scelta<1||scelta>5);
	return scelta;
}


int main()
{
	bool fine=false;
	do
	{
		switch(menu())
		{
			case 1:
			{
				somma();
				getch();				
				break;	
			}
			case 2:
			{
				sottrazione();
				getch();
				break;	
			}
			case 3:
			{
				moltiplicazione();
				getch();		
				break;	
			}
			case 4:
			{
				divisione();
				getch();		
				break;	
			}
			default:
			{
				fine=true;
				break;
			}
		}
	}
	while(fine==false);
}

