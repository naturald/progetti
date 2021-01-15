//marco schiavello 3^CI 18/12/2020 
/*
	dopo aver ricevuto il numero di libri che il cliente viole comperar, acquisisce altrettanti valori, cioè gli importi di tutti i libri, 
	che sommati forniranno l’importo totale della spesa.
	Su questo totale, per via della campagna promozionale, è applicato uno sconto da calcolare e da detrarre, così formato:
	fino a 50,00 euro lo sconto è del 5%, da 50,01 a 150,00 euro lo sconto è del 10%, oltre lo sconto è del 15%.
	L’algoritmo visualizza l’importo totale della spesa, il valore dello sconto che viene applicato, e l’importo di spesa finale effettivamente pagato, 
	tutti espressi in euro.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../marcoLib.h"

float getSconto(float tot)
{
	if(tot<50.01)
		tot =(tot * 5)/100;
	else if(tot>50&&tot<150)
		tot = (tot * 10)/100;
	else
		tot = (tot * 15)/100;	
	return tot;
}

void setNumLib(int * n_lib)
{
	do
	{
		system("cls");
		printf("inserisci numeri libri: ");
		scanf("%d",n_lib);
	}
	while(*n_lib<0||*n_lib>10);
}
void setCostLib(float * tot,int n_lib)
{
	float cost_lib;	
	for(int i=0;i<n_lib;i++)
	{
		do
		{
			printf("inserisci costo libro %d : ",i+1);
			scanf("%f",&cost_lib);
		}
		while(cost_lib<0||cost_lib>200);
		*tot+=cost_lib;
	}
}
void scontrino(float tot)
{
	printf("il prezzo totale non scontato e': %.2f\n",tot);
	printf("il prezzo totale scontato e': %.2f",tot - getSconto(tot));	
} 
int main()
{
	int n_lib;
	float tot=0;
	setNumLib(&n_lib);
	setCostLib(&tot,n_lib);
	scontrino(tot);
	getch();
}
