#include <stdio.h>
#include <math.h>
#define BASE 2
#define IEEE_LEN 32

int ecc127(int numDec);
int getBitNumDec(int bina,int cifra);
int decToBina(int num_bina[],float deci);
int IntToBina(int partInt,int num_bina[],int nBitInt = 0);
int calcEspo(int nBitInt,int num_bina[]);

int main()
{
   float deci;
   int ieeeFormat[IEEE_LEN],num_bina[IEEE_LEN],offset = 0,espo;
   char ieeeFormatHex[(IEEE_LEN/4)*2];

   //inizializazione a 0
   for(int i = 0; i<IEEE_LEN; i++)
   {
      if(i<((IEEE_LEN/4)*2))
      {
        ieeeFormatHex[i] = 0;
      }
      num_bina[i] = 0;
      ieeeFormat[i] = 0;
   }
   printf("metti numero reale in base 10 : ");
   scanf("%f",&deci);

   //settagio bit segno mantissa
   if(deci<0)
   {
       ieeeFormat[0] = 1;
       deci*=-1;
   }
   else
   {
       ieeeFormat[0] = 0;
   }

   espo = decToBina(num_bina,deci);

   //calcolo sponente con eccesso 127

  if(espo < 0)
  {
    offset = abs(espo);
  }

  espo = ecc127(espo);

  //tracopiatura dell'array numero bianrio in quello notazione IEEE
  for(int i = 0; i<IEEE_LEN; i++)
  {
    if(i == 0)
    {
      printf("\u001b[31m");
    }
    if(i>0 && i<9)
    {
      printf("\u001b[35m");
      ieeeFormat[i] = getBitNumDec(espo,8-i);
    }
    if(i>8)
    {
      printf("\u001b[32m");
      ieeeFormat[i] = num_bina[(i-8)+offset];
    }

    printf("%d ",ieeeFormat[i]);
    if(i == 0 || i == 8)
    {
      printf(" ");
    }
  }

  printf("\u001b[37m");

   return 0;
}

//---------------------------end-main---------------------------

/*
  dato un numero intero restituisce il numero nella vensione
  eccesso 127 utile per l'esponente della codifica IEEE-P754
*/
int ecc127(int numDec) {return numDec+127;}

/*
   prende un numero decimale e data una cifra farà il bitwise and tra il numero
   e la potenza perfetta che sarà 2 elevato la cifra da cercare
   in modo da prendere solo la cifra richiesta se tutto il numero sara
   composto da zeri allora la cifra cercata sarà 0 altrimenti se ci sara un solo 1
   sarà sicuramente quello ricercato
*/
int getBitNumDec(int bina,int cifra)
{
   if(bina & (int)pow(BASE,(float)cifra))
   {
      return 1;
   }
   else
   {
      return 0;
   }

}

/*
  dato la parte intera del numero e l'array che dovrà contenere
  la versione binaria del numero deciamle reale, calcola la
  rappresentazioen binaria della parte intera tramite una ricorsione
  ridando al chiamante il numero di bit che occupa la parte intera
  e assegando nel array la configuarazione binaria di esso
*/
int IntToBina(int partInt,int num_bina[],int nBitInt)
{
  if(!partInt)          // elemento determinante per la fine
  {                     // della catena di ricorsioni
    return nBitInt;
  }

  int cifraBina = partInt%2;  // resto del numero diviso per 2 ovvero la cifra binaria
  partInt >>= 1;  //shift di uno verso destra = divisione per 2
  nBitInt++;  //contatore che conta il numero di bit che occuppa il numero

  /*
    indica la lunghezza massima del nuemro bianrio,
    questo e dato dal ritorno dal'ultima ricorsione
    che tornando indietro si "trascinerà" il numero
    ritornato alla fine della catena fino a poi restiruirlo
    al chiamante
  */
  int lenMax = IntToBina(partInt,num_bina,nBitInt);

  /*
    essendo posto dopo alla chiamata questa istruzione
    verrà eseguita quando la chain di chiamate sarà finità
    e quindi tornerà indietro sapendo gia quanto e lungo il
    numero in bianrio, sotrarrà il contatore nBitInt-1
    (che avrà il valore descrescente tornando indietro nelle chiamate)
    alla lunghezza massima meno 1(perche a noi serve indice che parte da 0),
    posizionando cosi la configuarazione di bit in modo inverso nell'array
    es.
    chiamata 1
    nBitInt = 1
    lenMax = 5
    num_bina[(5-1) - (1-1)] = num_bina[4]
    cosi il primo bit della configuarazione sara messo
    nell'ultima posizione e andra avanti all'incontrario
  */
  num_bina[(lenMax-1) - (nBitInt-1)] = cifraBina;

  return lenMax;
}

/*
   prende come parametri un array dove metterà il numero binario una volta convertito
   e come secondo parametro un numero reale.
   Il programma determinerà prima la parte intera per poi andare a calcolare la parte frazzionaria
   la funzione ritornera il numero di bit interi -1 poiche esso corrisponderà alla potenza da
   applicare a 10 per far diventare il numero con era prima
*/
int decToBina(int num_bina[],float deci)
{
  int partInt = (int)deci;
  float partDec = deci - partInt;

  int i = 0;
  int nBitInt = IntToBina(deci,num_bina);
  float n;

  if(nBitInt == 0)
  {
    i = 1;
  }
  else
  {
    i = nBitInt;
  }

  for(int j=0; j<(IEEE_LEN-i) && partDec != 0.0; j++)
  {
    partDec *= BASE;
    num_bina[i+j] = (int)partDec;
    partDec -= (int)partDec;

  }

  return calcEspo(nBitInt,num_bina);
}

/*
  calcolo qua l'esponente perchè ho già il numero di interi che è utile
  per calcolare l'esponente perciò faccio che calcolarlo anche se so che
  è molto delocalizzato
*/
int calcEspo(int nBitInt,int numBina[])
{
  if(nBitInt == 0)
  {
    /*
      in caso non abbia parte intera si andrà indietro nel numero
      finche non si trovera un bit a 1 che diventerà il hidden bit.
      nel procedimanto di andare all indietro la potenza che dovra
      esse calcolata sul 2,la potenza verra descrementata in modo che
      2^esponente * 1.mantissa = numero iniziale
    */
    nBitInt = -1;
    for(int x = 1; numBina[x] != 1;x++)
    {
      nBitInt--;
    }
    return nBitInt;
  }
  return nBitInt-1;
}


