//Schiavello marco 3^CI 21/01/2021
/*
	leggere 20 numeri interi e memorizzarli in un vettore num,
	calcolare i quadrati dei venti numeri e memorizarli in un vettore quad.
	stamapare i numeri e i loro quadrati in mdo opportuno in una tabell opportuna
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 20

void caricaVet(int lati[],int quad[])
{
	for(int i = 0;i<DIM;i++)
	{
		do
		{
			printf("metti lato %2d : ",i+1);
			scanf("%d",&lati[i]);
		}
		while(lati[i]>999);
		quad[i] = lati[i]*lati[i];
	}	
}

void stampaVet(int lati[],int quad[])
{
	for(int i = 0;i<DIM;i++)
		printf("\n%2d)il quadrato del lato %3d e': %d",i+1,lati[i],quad[i]);
}

int main()
{
	int lati[DIM],quad[DIM];
	caricaVet(lati,quad);
	stampaVet(lati,quad);
}
