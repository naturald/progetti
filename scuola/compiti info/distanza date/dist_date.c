//Marco Schiavello 3^CI 31/01/2021
/*
	leggere due date dello stesso anno.
	Nota: effettuare il controllo formale delle date inserite 
	(compreso il controllo sul fatto che le due date siano dello stesso anno)
	e dire quanti giorni intercorrono tra una data e l'altra.	
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N_DATE 2

void setDate(int gg[],int mm[],int aaaa[],bool * bise)
{
	bool rep;
	int i;
	do
	{
		for(i=0;i<N_DATE;i++)
		{
		    do
		    {
		        do
		        {
		            do
		            {
		                system("cls");
		                printf("immettere data %d\n",i);
		                printf("inserisci il giorno %d --> ",i);
		                scanf("%d",&gg[i]);
		            }
		            while(gg[i]<1||gg[i]>31);
		            do
		            {
		                system("cls");
		                printf("immettere data\n");
		                printf("inserisci il giorno %d --> %d",i,gg[i]);
		                printf("\ninserisci il mese %d   --> ",i);
		                scanf("%d",&mm[i]);
		            }
		            while(mm[i]<1||mm[i]>12);
		        }
		        while((mm[i]==4||mm[i]==6||mm[i]==9||mm[i]==11)&&gg[i]==31);
		        do
		        {
		            system("cls");
		            printf("immettere data\n");
		            printf("inserisci il giorno %d --> %d",i,gg[i]);
		            printf("\ninserisci il mese %d   --> %d",i,mm[i]);
		            printf("\ninserisci l'anno  %d   --> ",i);
		            scanf("%d",&aaaa[i]);
		        }
		        while(aaaa[i]<1);
		        if(mm[i]==2&&gg[i]>28)
		            if((aaaa[i]%4==0&&aaaa[i]<=1917)||((aaaa[i]%4==0&&aaaa[i]%100!=0)||aaaa[i]%400==0)&&aaaa[i]>1917)
		                if(gg[i]==29)
		                {
		                    rep=false;
							*bise=true;	
						}
		                else
		                    rep=true;
		            else
		                rep=true;
		        else
		            rep=false;
		
		    }
		    while(rep==true);
		}
	}
	while(aaaa[0]!=aaaa[1]);
	if((aaaa[0]%4==0&&aaaa[0]<=1917)||((aaaa[0]%4==0&&aaaa[0]%100!=0)||aaaa[0]%400==0)&&aaaa[0]>1917)
		if((mm[0]<=2 || mm[1]<=2)&&(mm[0]>2 || mm[1]>2))
		*bise=true;
}

int deltaGioni(int gg[],int mm[], bool bise)
{
  int ris,i,anno[12] = {31,28,31,30,31,30,31,31,30,31,30,31},min,max;
  if(bise == true)
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
    bool bise = false;
    setDate(gg,mm,aaaa,&bise);
    printf("%d",deltaGioni(gg,mm,bise));
    return 0;
}

