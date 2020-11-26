//marco schiavello 
//menu
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define N_COL 19

void tabella(int volte,bool invio=false,bool trat=false)
{
	for(int i=0;i<volte;i++)
	{
		printf("+-----");		
	}
	printf("+");
	if(invio==true)
		printf("\n");
	if(trat==true)
		printf("|");
		
}


int main()
{
	int scelta,cod;
	char c;
	do
	{
		do
		{
			system("cls");
			printf("1) tabella codici Ascii\n\n");
			printf("2) codifica ascii di un carattere\n\n");
			printf("3) carattere corrispondente ad un codice Ascii\n\n");
			printf("4) trasforma una lettera minuscola in maiscula\n\n");
			printf("5) esci\n\n");
			printf("scegli --> ");
			scanf("%d",&scelta);	
		}
		while(scelta<1||scelta>4);
	
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				for(int i=0;i<256;i++)
				{
					printf(" %3d %c",i,i);
				}
				getch();
				break;
			}
			case 2:
			{
				system("cls");
				printf("scegli carattere--> ");
				fflush(stdin);
				scanf(" %c",&c);
				printf("il codice Ascii e' --> %d\n",c,c);
				getch();
				break;
			}
			case 3:
			{
				system("cls");
				do
				{
					printf("scegli codice Ascii--> ");
					scanf("%d",&cod);
				}
				while(cod<0||cod>255);
				printf("il caratte ascii e' --> %c\n",cod);
				getch();
				break;
			}
			case 4:
			{
				system("cls");
				printf("scegli minuscola --> ");
				fflush(stdin);
				scanf(" %c",&c);
				if(c>96&&c<123)
					printf("il carattere maiuscolo e'--> %c\n",c-32);
				else
					printf("il carattere maiuscolo e'--> %c\n",c);
					

				
				getch();
				break;
			}
		}
	}
	while(scelta!=5);
}
