/*
	Marco Schiavello 3^CI
	Dati due vettori di interi, fondere i due vettori in un terzo vettore
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM1 5
#define DIM2 6


//prendendo tre array di cui due di input e l'ultimo di output che sarebbbe anche l'unione dei due di input
void merge(int vet[],int vet2[],int ris[])
{
	for(int i = 0;i<(DIM1+DIM2);i++)
	{
		if(i<DIM1)
			ris[i] = vet[i];
		else
			ris[i] = vet2[i-DIM1];
	}
}

//merge con un array allocato con malloc e ritorna puntatore della memoria
int * merge_(int vet[],int vet2[])
{
	int * ris = (int*) malloc((DIM1+DIM2)*4);//creazione array nel heap con allocazione celle
	for(int i = 0;i<(DIM1+DIM2);i++)
	{
		if(i<DIM1)
			ris[i] = vet[i];
		else
			ris[i] = vet2[i-DIM1];
	}
	return ris;
}

//stampa l'array passato di lunghezza dim
void stampaVet(int ris[],int dim)
{
	for(int i = 0;i<dim;i++)
		printf("elemento dell'array in pos %2d e' : %d \n",i,ris[i]);
	printf("\n\n");
}

int main()
{
	//fase inizializazione dei dati
	int vet[DIM1] = {4,7,10,12,11},vet2[DIM2] = {4,7,10,12,8,11},ris[DIM1+DIM2];

	stampaVet(vet,DIM1);
	stampaVet(vet2,DIM2);
	merge(vet,vet2,ris);
	stampaVet(ris,DIM1+DIM2);
	int * ris_ = merge_(vet,vet2);
	stampaVet(ris_,DIM1+DIM2);
	free(ris_);//NON RICHIEDE SPIEGAZIONI E' C
}
