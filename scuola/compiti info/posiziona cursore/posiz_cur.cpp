//marco schiavello 3^CI 03/12/2020
//fare una funzione che posizioni il cursore nella posizione X Y
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct cursore
{
	int x;
	int y;
};

void goToXY(struct cursore cur)
{
  system("cls");
  for(int i=1;i<cur.y;i++)
    printf("\n");
  for(int j=1;j<cur.x;j++)
    printf(" ");
}

int main() 
{

	struct cursore cur;
	do
	{
		system("cls");
		printf("inserisci il valore X: ");
		scanf("%d",&cur.x);
	}
	while(cur.x<=0||cur.x>28);
	do
	{
		system("cls");
		printf("inserisci il valore X: %d\n",cur.x);
		printf("inserisci il valore Y: ");
		scanf("%d",&cur.y);
	}
	while(cur.y<=0||cur.y>28);
	goToXY(cur);
	printf("ciao");
} 


