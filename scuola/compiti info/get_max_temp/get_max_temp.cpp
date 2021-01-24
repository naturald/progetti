// Schiavello marco 3^CI 19/01/2021
// lette delle temperature dire la massima e la minima
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define LEN 24

void leggi_temperature(int temp[])
{
	for(int i=0;i<LEN;i++)
	{
		printf("inserisci la temperatura alle ore %2d:",i+1);
		scanf("%d",&temp[i]);      // lettura della temperatura i-esima
	}
}

int getMin(int temp[])
{
	int min = temp[0];
	for(int i=0;i<LEN;i++)
	 if(min>=temp[i])
	 	min = i;
	return min;
}

int getMax(int temp[])
{
	int max = temp[0];
	for(int i=0;i<LEN;i++)
	 if(max<=temp[i])
	 	max = i;
	return max;
}

int main()
{
	int temperature[LEN];
	leggi_temperature(temperature);
	int min = getMin(temperature),max = getMax(temperature);
	while(!kbhit())//finche non primi un tasto
	{
		system("cls");
		printf("\n\n\nla temperatura massima e' %d alle ore %d e %d alle ore %d ",temperature[max],max+1,temperature[min],min+1);	
	}
 	
}
