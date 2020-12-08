//marco schiavello 3^CI 1/10/2020
//compito numero succ e precendente
#include <stdio.h>
#include <conio.h>

int main()
{
	int n;
	//prima versione prece e succ adiacenti 
	/*
	printf("inserisci numero : ");
	scanf("%d",&n);
	printf("il succ e' %d ",n+1);
	printf("\nil precedente e' %d",n-1);
	*/
	
	//seconde versione prece e succ secondo tipologia	
	printf("inserisci numero : ");
	scanf("%d",&n);
	if(n==0)
	{
		printf("non si puo con 0");
		getch();
		return 0;
	}
	printf("il succ e' %d ",n+2);
	printf("\nil precedente e' %d",n-2);
	
}
