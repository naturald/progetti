/*
	Marco Schiavello 3^CI
	Dati due vettori di interi, fondere i due vettori in un terzo vettore
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM1 5
#define DIM2 6

/*
    questo sottoprogramma genra dentro un array di lunghezza len
    valori casuali
    Parametri:
    int vett[] : output
    int len : input
*/
void caricaRand(int vett[],int len)
{
    srand(time(0));
    for(int i = 0;i<len;i++)
        vett[i] = (rand()%20)+1;
}

/*
    questo sottoprogramma prende due elementi di un array e li scanbia con l'ausilio di una variabile temporanea
    Parametri:
    int vett[] : output
    int a : input
    int b : input
*/
void swap(int vett[],int a,int b)
{
	int tmp = vett[a];
	vett[a] = vett[b];
	vett[b] = tmp;
}

/*
    prende il vettore di lunghezza len e lo sorta per un algoritmo di selezione
    Parametri:
    int vett[] : input/output
    int len : input
*/
void ordina(int vett[],int len)
{
	int i,j;
	for(i = 0;i<len-1;i++)
		for(j = i+1;j<len;j++)
			if(vett[i]>vett[j])
				swap(vett,i,j);
}

/*
    dati piu valori uguali in un array  toglie quelli aggiuntivi creando un array
    secondario dove viene salvati solo i valori differenti per poi essere riportati
    su quello primìncipale
    Parametri:
    int vett[] : input/output
    int len : input
*/
int pulisci(int vett[],int len)
{
    int ris[len],newLen = 0;
    for(int i = 0;i<len;i++)
    {
        if(ris[newLen-1] != vett[i])
        {
            ris[newLen] = vett[i];
            newLen++;
        }
    }
    for(int i = 0;i<len;i++)
    {
        if(i<newLen)
            vett[i] = ris[i];
        else
            vett[i] = 0;
    }
    return newLen;
}

/*
    prendendo tre array di cui due di input e l'ultimo di output che
    sarebbbe l'unione dei due di input
    Parametri:
    int ris[] : output
    int vet[] : input
    int vet2[] : input
*/
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

/*
    stampa l'array passato di lunghezza dim
    Parametri:
    int ris[] : output
    int dim : input
*/
void stampaVet(int ris[],int dim)
{
	for(int i = 0;i<dim;i++)
		printf("elemento dell'array in pos %2d e' : %d \n",i,ris[i]);
	printf("\n\n");
}

int main()
{
	//fase inizializazione dei dati
	int vet[DIM1],vet2[DIM2],ris[DIM1+DIM2];
	caricaRand(vet,DIM1);
    caricaRand(vet2,DIM2);

	printf("vattore 1\n\n");
	stampaVet(vet,DIM1);

	printf("vattore 2\n\n");
	stampaVet(vet2,DIM2);

	merge(vet,vet2,ris);
    ordina(ris,DIM1+DIM2);

    printf("vattore unito e ordianto ma non pulito\n\n");
    stampaVet(ris,DIM1+DIM2);

    int newLen = pulisci(ris,DIM1+DIM2);
    printf("vattore unito,ordianto e pulito \n\n");
	stampaVet(ris,newLen);
}
