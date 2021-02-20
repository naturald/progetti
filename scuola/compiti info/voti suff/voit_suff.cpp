/*
  Marco Schiavello, Alberto Benedicenti, Guido Panzieri 3^CI 18/02/2021
  Scrivere un programma che: 
  leggere  in un primo vettore i voti riportati da uno studente in diverse materie,
  e costruire un nuovo vettore contenente solo i voti sufficienti e stamparne il contenuto
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void caricaVoti(float voti[])// carichiamo l'array con i voti voti[] : input
{
  for(int i = 0;i<DIM;i++)
  {
    do
    {
      printf("inserisci il %2d ° valore : ",i+1);
      scanf("%f",&voti[i]);
    }
    while(voti[i]<1 || voti[i]>10);
  }
}

// cerca e ed assegna i voti sufficenti al array apposito voti[] : input, votiSuf[] : output, *numsuf : output
void ricercaVotiSuf(float voti[], float votiSuf[], int * numsuf)
{
  for(int i=0;i<DIM;i++)
  {
    if(voti[i]>=6)
    {
      votiSuf[*numsuf] = voti[i];
      *numsuf = *numsuf + 1;
    }
  }
}

void output(float votiSuf[],int numsuf)// stampa solo i voti sufficenti dall'array votiSuf[] : output, numsuf : comodo
{
  printf("i voti sufficenti sono : ");
  for(int i = 0;i<numsuf;i++)
  {
    printf(" %.2f ",votiSuf[i]);
  }
}

int main()  
{
  int numsuf = 0;
  float voti[DIM];
  float votiSuf[DIM];
  caricaVoti(voti);
  ricercaVotiSuf(voti,votiSuf,&numsuf); 
  output(votiSuf,numsuf);
}

