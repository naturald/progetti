#include <stdio.h>
#include <math.h>
#include <windows.h>
#define BASE 2
#define IEE_LEN 32
#define BIN_LEN 32

/*
    funzione che permette di cambiare il colore
    delle scritte funziona su windows (credo)
    comunque e stata compiata percio non so cosa piu precisamente faccia
*/
void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color + (__BACKGROUND << 4));
}

/*
    data una lunghezza stampa un array di
    caratteri di lunghezza len
*/
void printArrChar(char arr[],int len)
{
    for(int i = 0;i<len;i++)
        printf("%c",arr[i]);
}

int charToInt(char letter)
{
    if(letter>= 48 && letter<= 57)
        return letter - 48;
    if(letter>= 65 && letter<= 70)
        return letter - (65 - 10);
}

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
		return 1;
	else
		return 0;
}

/*
    dato un numero float prende la parte intera
    e dice quanti bit occuperà continuado a shiftare
    il nuero a destra finche non sarà ugale a 0
*/
int nIntBina(float numDeci)
{
   int partInt = (int)numDeci,nBitInt = 0;
   while(partInt)
   {
     partInt >>= 2;
     nBitInt++;
   }
   return nBitInt;
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
	int i = 0,partInt,nBitInt = nIntBina(deci);
	float n,partDec;
    partInt = (int)deci;
    partDec = deci - partInt;

    for(int i = nBitInt-1;partInt!=0;i--)
    {
        num_bina[i] = partInt % BASE;
        partInt /= BASE;
    }

    if(nBitInt == 0)
        i = 1;
    else
        i = nBitInt;

    for(int j=0;j<(BIN_LEN-i) && partDec != 0.0;j++)
    {
        partDec *= BASE;
        num_bina[i+j] = (int)partDec;
        partDec -= (int)partDec;
    }

    return nBitInt-1;
}

char HexDigit(int hexDigit)
{
    if(hexDigit>=0 && hexDigit<=9)
        return 48+hexDigit;
    if(hexDigit >= 10)
        return (65-10) + hexDigit;
}

void IeeeHex(int ieeeFormat[],char ieeeFormatHex[])
{
    int hexDigit = 0;
    for(int i = 0, j = 0;i<IEE_LEN;i++)
    {
        if((i % 4 == 0 && i != 0) || i == IEE_LEN-1)
        {
            ieeeFormatHex[j] = HexDigit(hexDigit);
            j++;
            hexDigit = 0;
        }
        hexDigit += pow(2,3 - (i%4)) * ieeeFormat[i];
    }
}

//---------------------------main------------------
int main()
{
    float deci;
    int ieeeFormat[IEE_LEN],num_bina[BIN_LEN],offset = 0,espo;
    char ieeeFormatHex[(IEE_LEN/4)*2];


    //inizializazione a 0
    for(int i = 0;i<40;i++)
    {
        if(i<IEE_LEN)

        if(i<((IEE_LEN/4)*2))
            ieeeFormatHex[i] = 0;

        num_bina[i] = 0;
    }
    printf("metti numero reale in base 10 : ");
    scanf("%f",&deci);

    //settagio big segno mantissa
    if(deci<0)
    {
        ieeeFormat[0] = 1;
        deci*=-1;
    }
    else
        ieeeFormat[0] = 0;

    espo = decToBina(num_bina,deci);

    //calcolo sponente con eccesso 127
    if(espo != -1)
    {
        espo += 127;
    }
    else
    {
        /*
            in caso non abbia parte intera si andrà indietro nel numero
            finche non si trovera un bit a 1 che diventerà il hidden bit.
            nel procedimanto di andare all indietro la potenza che dovra
            esse calcolata sul 10 verra descrementata in modo che
            10^esponente * 1.mantissa = numero iniziale
        */
        offset = 1;
        //si mette un offset per capire da dove iniziare a copiare dall'array del numero binario sull'array della notazione IEEE
        for(int x = 1;num_bina[x] != 1;offset++,x++)
            espo--;
        espo += 127;
    }

    //tracopiatura dell'array numero bianrio in quello notazione IEEE
   for(int i = 0; i<IEEE_LEN; i++)
   {
       printf("\u001b[37m");
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

    printf("\n\n");
    IeeeHex(ieeeFormat,ieeeFormatHex);
    printf("0x");
    printArrChar(ieeeFormatHex,sizeof(ieeeFormatHex));
    printf("\n\n");

    return 0;
}
