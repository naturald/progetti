#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define DIM 3

void seleAuto(char campo[][DIM])
{
  int i,j;
  do
  {
    i=rand()%3;
    j=rand()%3;
  }
  while(campo[i][j]=='O' || campo[i][j]=='X');
  campo[i][j]='O';
}

void seleManu(char campo[][DIM],char segno)
{
  int i,j;
  bool err = false;
  printf("scegli cordinate dove mettere la %c\n",segno);
  do
  {
    err = false;
    printf("indice righa tra 1 e 3: ");
    scanf ("%d", &i);
    i--;
    printf("indica colonna tra 1 e 3: ");
    scanf ("%d", &j);
    j--;

    if(campo[i][j]!=' ' || (i<0 || i>2) ||  (j<0 || j>2))
    {
      err = true;
      printf("questa posizione e' gia' stata occupata o e' fuori dal campo rimetti \n");
    }

    printf("\n\n");
  }
  while(err);
  campo[i][j]=segno;
}

int cotrollo(char campo[][DIM],char segno)
{
  int i, fine = 0;
  for(i=0;i<3;i++)
  {
    if(campo[i][0]==campo[i][1] && campo[i][1]==campo[i][2])
    {
      if(campo[i][1] == segno)
        fine=1;
    }

    if(campo[0][i]==campo[1][i] && campo[1][i]==campo[2][i])
    {
      if(campo[1][i] == segno)
        fine=1;
    }
  }
  if
  (
    (campo[0][0]==campo[1][1] && campo[1][1]==campo[2][2])
    ||
    (campo[0][2]==campo[1][1] && campo[1][1]==campo[2][0])
  )
  {
    if(campo[1][1] == segno)
      fine=1;
  }
  if(fine != 0)
  {
    if(segno == 'O')
      return 2;
    else
      return 1;
  }
  return 0;
}

void dis_campo(char campo[DIM][DIM])
{
  printf("   1   2   3 \n");
  printf(" o---o---o---o \n");
	for(int i=0;i<DIM;i++)
	{
			printf("%d",i+1);
			for(int j=0;j<DIM;j++)
			{
				printf("| %c ",campo[i][j]);

			}
			printf("|\n");
      printf(" o---o---o---o \n");
	}
}

void ripulisci()
{
  system("cls");
}

int  main()
{
	int i,j,turno=0,fine=0,n_gioc;
	char campo[DIM][DIM];

	srand(time(NULL));

	printf("Benvenuto nel gioco del tris\n");
	do
	{
		printf("quanti giocatori min 1 max 2: ");
		scanf("%d", &n_gioc);
	}
	while(n_gioc<1||n_gioc>2);

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			campo[i][j]=' ';

  ripulisci();
  dis_campo(campo);
	do
	{
	  seleManu(campo,'X');

    //-----------------controllo combinazioni X------------------
		if(turno>=2)
			fine = cotrollo(campo,'X');
		//----------------------------------------------------------------

		if(turno<4 && fine == 0)
		{
			switch(n_gioc)
			{
				case 1:
				  seleAuto(campo);
				break;

				case 2:
					ripulisci();
					dis_campo(campo);
					seleManu(campo,'O');
				break;
			}

    //-----------------controllo combinazioni O------------------
		if(turno>=2)
			fine = cotrollo(campo,'O');
		//----------------------------------------------------------------
		}

	  ripulisci();
		dis_campo(campo);
		turno++;
	}
	while(turno<5 && fine == 0);

  switch(fine)
  {
    case 0:
      printf("\nPARITA'\n\n");
    break;
    case 1:
      if(n_gioc==2)
        printf("\nHA VINTO X\n\n");
      else
        printf("\nHAI VINTO \n\n");
    break;

    case 2:
      if(n_gioc==2)
        printf("\nHA VINTO O\n\n");
      else
        printf("\nHAI PERSO \n\n");
    break;

  }

	scanf("%d", &i);

  return 0;
}
