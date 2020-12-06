//marco schiavello 3^CI 1/10/2020
//compito numero succ e precendente
#include <stdio.h>
#include <conio.h>

int main()
{
	int n,n_att;
	//prima versione prece e succ adiacenti 
	/*
	printf("inserisci numero : ");
	scanf("%d",&n);
	n_att=n+1;
	printf("il succ e' %d ",n_att);
	n_att=n-1;
	printf("\nil precedente e' %d",n_att);
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
	n_att=n+2;
	printf("il succ e' %d ",n_att);
	n_att=n-2;
	printf("\nil precedente e' %d",n_att);
	
}
