//marco schiavello 3^CI 03/12/2020
//fare una funzione che posizioni il cursore nella posizione X Y
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void goToXY(int x,int y)
{
  system("cls");
  for(int j=0;j<y;j++)
  {
    printf("\n");
  }
  for(int i=0;i<x;i++)
  { 
    printf(" ");
  }
  getch();
}


int main() 
{
  int x,y;
  printf("inserisci il valore X: ");
  scanf("%d",&x);
  printf("inserisci il valore Y: ");
  scanf("%d",&y);
  goToXY(x,y);
} 


