//marco schiavello 3^Ci
//menu calcolatrice
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
	int scelta,ope1,ope2;
	do
	{
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
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				printf("inserisci primo operando --> ");
				scanf("%d",&ope1);
				printf("inserisci secondo operando --> ");
				scanf("%d",&ope2);
				printf("%d + %d = %d",ope1,ope2,ope1+ope2);
				getch();				
				break;	
			}
			case 2:
			{
				system("cls");
				printf("inserisci primo operando --> ");
				scanf("%d",&ope1);
				printf("inserisci secondo operando --> ");
				scanf("%d",&ope2);
				printf("%d - %d = %d",ope1,ope2,ope1-ope2);
				getch();
				break;	
			}
			case 3:
			{
				system("cls");
				printf("inserisci primo operando --> ");
				scanf("%d",&ope1);
				printf("inserisci secondo operando --> ");
				scanf("%d",&ope2);
				printf("%d * %d = %d",ope1,ope2,ope1*ope2);	
				getch();		
				break;	
			}
			case 4:
			{
				system("cls");
				printf("inserisci primo operando --> ");
				scanf("%d",&ope1);
				printf("inserisci secondo operando --> ");
				scanf("%d",&ope2);
				printf("%d / %d = %d",ope1,ope2,ope1/ope2);		
				getch();		
				break;	
			}
		}
	}
	while(scelta!=5);
}

