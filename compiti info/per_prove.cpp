//marco schiavello
//programma per provare forme di algoritmi credo 
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int i=1;
	do
	{
		printf("ciao %d\n",i);
		i=i+1;
	}
	while(i<=10);
	
	
	/* ciao con for 
	for(int i=0;i<10;i=i+1)
		printf("ciao\n");
	*/
	
	/* prova operatori logici
	int peso;
	do
	{
		system("cls");
		printf("inserisci tuo peso (min 1 max 650): ",peso);
		scanf("%d",&peso);
	}
	while(peso<1||peso>650);
	*/
	
	/* prova per cicli
	int n,i=0;
	printf("quanti numeri vuoi stampare : ");
	scanf("%d",&n);
	while(i<n)
	{
		i+=1;
		printf("il numero e' %d \n",i);
		// da 0 a n-1 i+=1;
	}
	*/
	
	printf("\n");
		
	getch();
}
