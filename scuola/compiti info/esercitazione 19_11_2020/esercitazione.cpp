//marco schiavello 15/10/2020
//controllo input
#include <stdio.h>
#include <conio.h>//TEORICAMENTE SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")
#define N_RIGHE 14

void linea(int volte,bool invio=false,bool trat=false)
{
	for(int i=0;i<volte;i++)
	{
		printf("o-----");		
	}
	printf("o");
	if(invio==true)
		printf("\n");
	if(trat==true)
		printf("|");
		
}

int main()
{
	linea(N_RIGHE,true,true);
	for(int i=0;i<256;i++)
	{
		if(i%N_RIGHE==0&&i!=0)
		{
			printf("\n");
			linea(N_RIGHE,true,true);	
		}

		if(i<=13)
			printf("%3d %c|",i,14);
		else
			printf("%3d %c|",i,i);
	}
	printf("\n");
	linea(N_RIGHE,true,false);;
}
