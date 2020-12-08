//marco schiavello 3^CI 13/11/2020
//esercizio per provare il carattere e la funzione sizeof()
#include <stdio.h>

int main()
{
	char c='A';//dichiarazione variabile di tipo char
	int arr[3];
	int size=sizeof(arr);
	int size2=sizeof(arr[0]);
	int size3=sizeof(c);
	printf("\nGrandezza del intero array e'%d Byte in memoria centrale",size);
	printf("\nGrandezza della cella del array/intero e' %d Byte in memoria centrale",size2);
	printf("\nGrandezza del array e' %d",size/size2);
	printf("\nGrandezza grandezza della varibile char e' %d e il contenuto e' %c",size3,c);
		
}
