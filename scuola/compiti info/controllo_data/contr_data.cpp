//marco schiavello 3^CI 12/11/2020
//controllo formale della data
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int gg,mm,aaaa;
	bool rep=false;
	char risp;
	do
	{
	    do
	    {
	        do
	        {
	            do
	            {
	                system("cls");
	                printf("immettere data\n");
	                printf("inserisci il giorno  --> ");
	                scanf("%d",&gg);
	            }
	            while(gg<1||gg>31);
	            do
	            {
	                system("cls");
	                printf("immettere data\n");
	                printf("inserisci il giorno  --> %d",gg);
	                printf("\ninserisci il mese    --> ");
	                scanf("%d",&mm);
	            }
	            while(mm<1||mm>12);
	        }
	        while((mm==4||mm==6||mm==9||mm==11)&&gg==31);
	        do
	        {
	            system("cls");
	            printf("immettere data\n");
	            printf("inserisci il giorno  --> %d",gg);
	            printf("\ninserisci il mese    --> %d",mm);
	            printf("\ninserisci l'anno     --> ");
	            scanf("%d",&aaaa);
	        }
	        while(aaaa<1);
	        if(mm==2&&gg>28)
	            if((aaaa%4==0&&aaaa<=1917)||((aaaa%4==0&&aaaa%100!=0)||aaaa%400==0)&&aaaa>1917)
	                if(gg==29)
	                    rep=false;
	                else
	                    rep=true;
	            else
	                rep=true;
	        else
	            rep=false;
	
	    }
	    while(rep==true);
	
	
	    printf("\nva bene\n\n");
	    do
	    {
			fflush(stdin);
		    printf("vuoi continuare (s o n): ");
		    scanf("%c",&risp);
		    tolower(risp);
		}
		while(risp!='s'&& risp!='n');

	}
	while(risp=='s');
}
