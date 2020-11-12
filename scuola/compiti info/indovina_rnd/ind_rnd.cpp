//marco schiavello 05/11/2020
//indovina un numero rand
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main()
{
	srand(time(0));
	int n=rand()%10000+1,ind,i=0;
	//printf("%d\n",n);
	while(i<14)
	{
		i++;
		do
		{
			printf("%d )prova a indovinare: ",i); 
			scanf("%d",&ind);
		}
		while(ind<0||ind>10000);
		if(ind==n)
			printf("hai indovinato HAI VINTO\n");
		else if(ind<n)
			printf("troppo basso\n");
		else if(ind>n)
			printf("troppo alto\n");
	}
	printf("HAI PERSO")
	getch();
}
