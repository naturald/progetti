#include <stdio.h>
#include<string.h>

int main()
{
	int card_n;
	int card_k;
	
	prinf("Benvenuto nel calcolatore di combinazioni massime con lunghezza minima fissa \n");
	prinf("di seguito dovrai mettere i dati del alfabeto sorgente e del alfabeto del codice \n \n");
	
	prinf("immetti cardinalita' del alfabeto sorgente: ");	
	scanf("%d",&card_n);
	
	int size_arr=card_n*10;
	char Alf_src[size_arr];
	int i=0;
	for(i=0;i<size_arr;i++)
	{
		prinf("immetti elemento alfabeto sorgente (lunghezza MAX 10): ");	
		scanf("%100s",&Alf_src[i]);	
	}
	
	
	prinf("immetti cardinalita' del alfabeto del codice: ");	
	scanf("%d",&card_k);
	

	return 0;
	
}
