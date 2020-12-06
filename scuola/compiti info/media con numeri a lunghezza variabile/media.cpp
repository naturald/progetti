//marco schiavello 3^CI 1/10/2020
//dato un numero intero n chiedere n numeri interi e fare la media di essi
#include <stdio.h>
#include <conio.h>

int main()
{
	int sum,i,n,n_inser,media;
	printf("numero di numeri con cui fare la media: ");
	scanf("%d",&i);
	n_inser=i;
	while(i>0)
	{
		printf("inserisci numero %d : ",(n_inser+1)-i);
		scanf("%d",&n);
		sum=sum+n;
		printf("%d",sum);
		i=i-1;
	}
	media=sum/n_inser;
	printf("\nla media e' %d",media);
}

