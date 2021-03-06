#include <iostream>
#include <stdlib.h>

using namespace std;

void scmbio(int * arr,int a,int b)//funzione che scambia
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] =tmp;
}

int pos_pivot(int * arr,int min,int max)
{
	int piv = arr[max];
	int ult_min = min;
	/*
        numero che segna l'indice subito dopo l'ultimo valore minore del pivot trovato
        che sarà protagonista di uno scambio in caso l'elemento in posizione i-esima fosse
        maggiore del pivot
	*/
	for(int i = min;i<=max;i++)
		if(arr[i]<=piv)
		{
			scmbio(arr,i,ult_min);
			if(i!=max)//non aumenta perché quando il pivot si confronta con se stetto non deve aumentare se no cambierebbe la posizione del pivot
				ult_min ++;
		}
	return ult_min;
}

void quickSort(int * arr,int min,int max)
{
	if(min<max)//se l'idice inferiore diventa minore o uguale a quello superiore allora ri ritorna indietro
	{
		int pivI = pos_pivot(arr,min,max);
		quickSort(arr,min,pivI-1);
		quickSort(arr,pivI+1,max);
	}

}

int main()
{
	int arr [5] = {6,2,9,1,4};//qualsiasi valore
	quickSort(arr,0,(sizeof(arr)/4)-1);
	for(int i = 0;i<sizeof(arr)/4;i++)
		cout<<arr[i]<<" ";
}

