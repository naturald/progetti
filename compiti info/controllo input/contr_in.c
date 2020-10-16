//marco schiavello 15/10/2020
//controllo input
#include <stdio.h>
#include <conio.h>//TEORICAMENTE SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")

int main()
{
	int n1,n2,prod=0;
	do
	{
		system("cls");
		printf("moltiplica (positivo) : ");
		scanf("%d",&n1);
	}
	while(n1<0);
	do
	{
		printf("per (positivo) : ");
		scanf("%d",&n2);
	}
	while(n2<0);
	while(n2>0)
	{
		prod=prod+n1;
		n2--;
	}
	printf("il risultato e': %d",prod);
	getch();
}
