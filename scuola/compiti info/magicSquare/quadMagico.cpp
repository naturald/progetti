#include <stdio.h>
#include <stdlib.h>

#define RIGHE 9
#define COLONNE 9

void caricaMat(int mat[][COLONNE])
{
  int c = COLONNE/2,r = 0;
  for(int i = 0;i<(RIGHE*COLONNE);i++)
  {
    if(r == -1)
      r = RIGHE-1;
    if(c == COLONNE)
      c = 0;
    mat[r][c] = i+1;
    
    if((i+1)%9 != 0)
    {
      c = c+1;
      r = r-1;
    }
    else  
      r = r+1;
  }
}

void stampaMat(int mat[RIGHE][COLONNE])
{
  	int r, c;
   	printf("Il quadrato magico 9x9 è:\n");
    for(r = 0; r < RIGHE; r++)
	  {
      printf("\n");
      for(c = 0; c < COLONNE; c++)
      	printf(" %3d ", mat[r][c]);
    }
    printf("\n");
}

int main() 
{
  int mat[RIGHE][COLONNE];
  
  caricaMat(mat);
  stampaMat(mat);
  
  return 0;
}