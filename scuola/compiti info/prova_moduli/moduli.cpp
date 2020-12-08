//marco schiavello 3^CI 1/12/2020
//prove sottoprogramma 
/*
sotto programma insieme di istruzioni che non returna nulla
----------------------------------------------------------------
funzione insieme di istruzioni che returna qualcosa
*/
#include <stdio.h>
#include <conio.h>

//sotto programma
int somma(int x,int y)//prova e una funzione che prende due parametri interi erestiruisce un intero
{//parametri formali x e y
	return x+y;
}
float pow(int base,int esp,int volte=0,int ris=1,bool neg=false)
{
	if(volte==0)
		if(esp<0)
		{
			esp*=-1;
			neg=true;
		}
	if(volte==esp)
	{
		if(neg==true)
			return (float)1/ris;
		return ris;
	}
	volte++;
	ris*=base;
	if(neg==true)
		return pow(base,esp,volte,ris,true);
	return pow(base,esp,volte,ris);
	
}

int main()
{
	printf("funzione somma risultato: %d\n",somma(5,6));//5 e 6 parametri attuali
	printf("funzione potenza risultato: %.10f",pow(2,-8));
}
