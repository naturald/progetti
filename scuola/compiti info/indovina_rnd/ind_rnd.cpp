//marco schiavello 3^CI 05/11/2020
//indovina un numero random
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main()
{
	srand(time(0));
	int n=rand()%10000+1,ind;
	//printf("%d\n",n);
	for(int i=0;i<14;i++)
	{
		do
		{
			printf("%d )prova a indovinare: ",i+1); 
			scanf("%d",&ind);
		}
		while(ind<0||ind>10000);
		if(ind==n)
			printf("hai indovinato HAI VINTO\n");
		else if(ind<n)
			printf("troppo basso\n");
		else 
			printf("troppo alto\n");
	}
	printf("HAI PERSO");
	getch();
}
