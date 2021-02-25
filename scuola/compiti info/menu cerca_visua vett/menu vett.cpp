/*
	Marco Schiavello 3^CI 11/02/2021
	
	Scrivere un programma che:
	- definisce un vettore di interi  di dimensione a piacere
	- definisce una variabile di stato per per indicare se il vettore è stato caricato  o meno.
	- visualizza un menu che permette di scegliere i valori 1,2,3,4,5
	-In base al valore scelto: 
	se scelto 1: effettua il caricamento del vettore e la variabile di stato viene posta a 1
	se scelto 2: visualizza il contenuto del vettore (se il vettore era caricato)  oppure
	                    richiede il caricamento del vettore  (se il vettore non era caricato)
	se scelto 3: effettua la ricerca del primo elemento :
	                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio 
	                     con:
	                    - la posizione del primo elemento del vettore che contiene quel numero (se trovato)
	                    -  l'indicazione che quel numero non è presente nel vettore
	se scelto 4: effettua la ricerca di tutti gli elementi:
	                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio 
	                     con:
	                    - le posizioni degli elementi del vettore che contengono quel numero(se trovati)
	                    - l'indicazione che quel numero non è presente nel vettore
	se scelto 5: effettua l'uscita da programma
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define DIM 5
#define MAX_VAL 99
#define MIN_VAL 1
#define OK 0
#define KO -1
#define GRAD 248

void swap(int vett[],int a,int b)
{
	int tmp = vett[a];
	vett[a] = vett[b];
	vett[b] = tmp;
}

void menu(int *scelta, bool caricato)
{
  bool err;
	system("cls");
  do
  {
    err=false;
    printf("1) carica il vettore\n");
	printf("2) visualizza il vettore\n");
	printf("3) carica la prima occorrenza del valore nel vettore\n");
    printf("4) tutte le occorrenze del valore nel vettore\n");
    printf("5) ordina crescente\n");
    printf("6) ordina decrescente\n");
	printf("7) esci\n");
    printf("scegli l'operazione da eseguire: ");
	scanf("%d",scelta);
    if((*scelta<=7&&*scelta>=2)&&caricato==false)
    {
      	err=true;
      	system("cls");
		printf("dato inserito incorretto\ndevi prima caricare il vettore");
		getch();
      	system("cls");
    }
    else if(*scelta<1||*scelta>7)
    {
      	err=true;
      	system("cls");
		printf("dato inserito incorretto\nla scelta deve essere compresa tra 1 e 5");
		getch();
    }
  }while(err==true);
}

void caricaVet(int vet[], bool * caricato)//cerca nel vettore 
{
	system("cls");
  	int i;
	for(i=0;i<DIM;i++)
	{
		printf("inserisci il numero %d: ",i+1);
		scanf("%d",&vet[i]);
	}
	*caricato=true;
}

int cercaVet(int vet[],int val)//cerca nel vettore la prima occorrenza e ritorna l'indice 
{
  int i;
  for(i = 0;i<DIM;i++)
    if(vet[i] == val)
      return i;
}

void visVet(int vet[])//visita vettore
{
  int i;
  for(i = 0;i<DIM;i++)
    printf("il %d %c valore del'array %d\n",i+1,GRAD,vet[i]);
}

void cercaPlusVet(int vet[], int val)//cerca anche dopo la prima occorrenza il valore coluto e ritorna gl'indici
{
  int i;
  for(i=0;i<DIM;i++)
    if(vet[i]==val) 
      printf(" %d",i);
  if(i==0)
  {
    system("cls");
    printf("il numero %d non e' presente nel vettore",val);
  }
}

void ordinaVet(int vet[])//ordina l'array in modo crescente
{
	int i,j;
	for(i = 0;i<DIM-1;i++)
		for(j = i+1;j<DIM;j++)
			if(vet[i]>vet[j])
				swap(vet,i,j);
}

void ordinaVetRev(int vet[])//ordina l'array in modo decrescente
{
	int i,j;
	for(i = 0;i<DIM-1;i++)
		for(j = i+1;j<DIM;j++)
			if(vet[i]<vet[j])
				swap(vet,i,j);
}


int main() 
{
	int vet[DIM], scelta, val;
	bool caricato;
	
  do
  {
    menu(&scelta,caricato);
    switch(scelta)
    {
      case 1:
      {
      	system("cls");
        caricaVet(vet,&caricato);
        getch();
        break;
      }
      case 2:
      {
      	system("cls");
        visVet(vet);
        getch();
        break;
      }
      case 3:
      {
        system("cls");
        printf("metti il valore da cercare :");
        scanf("%d",&val);
        int index = cercaVet(vet,val);
        printf("il valore e' in posizione : %d",index);
        getch();
        break;
      }
      case 4:
      {
        system("cls");
        printf("inserisci quale valore voui cercare nel vettore: ");
        scanf("%d",&val);
        printf("il numero %d si trova alla posizione : ",val);
        cercaPlusVet(vet,val);
        getch();
        break;
      }
      case 5:
      {
        system("cls");
        ordinaVet(vet);
        visVet(vet);
        getch();
        break;
      }
      case 6:
      {
        system("cls");
        ordinaVetRev(vet);
        visVet(vet);
        getch();
        break;
      }
    }
  }
  while(scelta != 7); 

	return 0;
} 
