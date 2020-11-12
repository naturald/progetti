//marco schiavello 12/11/2020
//controllo formale della data
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int gg,mm,aaaa;
do
{
	do
	{
		do
		{
			system("cls");
			printf("immettere data\n");
			printf("inserisci il giorno --> ");
			scanf("%d",&gg);
		}
		while(gg<1||gg>31);
		do
		{
			system("cls");
			printf("immettere data\n");
			printf("inserisci il giorno   --> %d",gg);
			printf("\ninserisci il mese   --> ");
			scanf("%d",&mm);
		}
		while(mm<1||mm>12);
	}
	while((mm==4||mm==6||mm==9||mm==11)&&gg==31);
}
while(mm==2&&gg>29);
	
	
	
	/*
	do
	{
		system("cls");
		printf("immettere data\n");
		printf("inserisci il giorno   --> %d",gg);
		printf("\ninserisci il mese   --> %d",mm);
		printf("\ninserisci l'anno    --> ");
		scanf("%d",&aaaa);
	}
	while(aaaa<1);*/
}
