//marco schiavello 3^CI 03/12/2020
//fare una funzione che posizioni il cursore nella posizione X Y
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void goToXY(int x,int y)
{
  system("cls");
  for(int i=1;i<y;i++)
    printf("\n");
  for(int j=1;j<x;j++)
    printf(" ");
}

int main() 
{
	int x,y;
	do
	{
		system("cls");
		printf("inserisci il valore X: ");
		scanf("%d",&x);
	}
	while(x<=0||x>28);
	do
	{
		system("cls");
		printf("inserisci il valore X: %d\n",x);
		printf("inserisci il valore Y: ");
		scanf("%d",&y);
	}
	while(y<=0||y>28);
	goToXY(x,y);
	printf("ciao");
} 


