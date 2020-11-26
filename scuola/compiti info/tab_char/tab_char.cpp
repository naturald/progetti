//marco schiavello 15/10/2020
//controllo input
#include <stdio.h>
#include <conio.h>//TEORICAMENTE SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")
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
	int col=0;
	tabella(N_COL,true,true);
	for(int i=0;i<256;i++)
	{
		if(i%N_COL==0&&i!=0)
		{
			printf("\n");
			tabella(N_COL,true,true);	
			col=0;
		}

		if(i<=13)
			printf("%3d %c|",i,14);
		else
			printf("%3d %c|",i,i);
		col++;
	}
	printf("\n");
<<<<<<< HEAD
	linea(col,true);
=======
	tabella(col,true);
>>>>>>> 7c2949e4fdd718b4789934afdd4e3514c14aa5e2
}
