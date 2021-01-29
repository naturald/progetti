#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N_DATE 2

void setDate(int gg[],int mm[],int aaaa[],bool * bise)
{
	int i;
	bool err;
  do
  {
    if(err==true)
    {
      system("cls");
      printf("valori inseriti non corretti");
      getch();
      system("cls");
    }
    for( i = 0;i<2;i++)
    {
      do
      {
        err=true;
        system("cls");
        printf("inserisci il giorno %d: ",i+1);
        scanf("%d",&gg[i]);
        while(gg[i]<1||gg[i]>31)
        {
          system("cls");
          printf("dato inserito non valido \n");
          getch();
          system("cls");
          printf("rinserisci il giorno %d: ",i+1);
          scanf("%d",&gg[i]);
        }
        system("cls");
        printf("inserisci il mese %d: ",i+1);
        scanf("%d",&mm[i]);
        while(mm[i]<1||mm[i]>12)
        {
          system("cls");
          printf("dato inserito non valido \n");
          getch();
          system("cls");
          printf("rinserisci il mese %d: ",i+1);
          scanf("%d",&mm[i]);
        }
        system("cls");
        printf("inserisci l'anno %d: ",i+1);
        scanf("%d",&aaaa[i]);
        while(aaaa[i]<0)
        {
          system("cls");
          printf("dato inserito non valido \n");
          getch();
          system("cls");
          printf("rinserisci l'anno %d: ",i+1);
          scanf("%d",&aaaa[i]);
        }
        if(mm[i]==1||mm[i]==3||mm[i]==5||mm[i]==7||mm[i]==8||mm[i]==10||mm[i]==12)
          err=false;
        else
        {
          if((mm[i]==4||mm[i]==6||mm[i]==9||mm[i]==11)&&(gg[i]>0&&gg[i]<31)) 
            err=false;
          else
          {
              if((aaaa[i]%4==0||aaaa[i]==0)&&mm[i]==2&&(gg[i]>0&&gg[i]<30)) 
              {
                err=false;
                *bise=true;
              }
              else
              {
                  if(aaaa[i]%4!=0&&mm[i]==2&&(gg[i]>0&&gg[i]<29)) 
                  {
                    err=false;
                    *bise=false;
                  }
                  else
                  {
                    system("cls");
                    printf("i dati inseriti non sono corretti\n");
                      
                  }
              }
          }

        }
      }
      while(err==true);
    }
  err=false;
  if(aaaa[0]!=aaaa[1]) 
    err=true;
  }
  while(err==true);
}

int deltaGioni(int gg[],int mm[], bool bise)
{
  int ris,i,anno[12] = {31,28,31,30,31,30,31,31,30,31,30,31},min,max;
  if(bise)
    anno[1] = 29;
  if(mm[0]==mm[1])
    ris = abs(gg[0] - gg[1]);
  else
  {
    if(mm[0]<mm[1])
      min = 0,max = 1;
    else 
      min = 1,max = 0;

    ris=anno[mm[min]-1]-gg[min];
    ris+=gg[max];
    for(i = mm[min];i<mm[max]-1;i++)
      ris+=anno[i];
  }
  return ris;
}

int main()
{
  	int gg[N_DATE], mm[N_DATE], aaaa[N_DATE];
    bool bise;
    setDate(gg,mm,aaaa,&bise);
    printf("%d",deltaGioni(gg,mm,bise));
}

