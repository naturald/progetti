//marco schiavello 05/11/2020
//indovina un numero rand
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main()
{
	srand(time(0));
	int n=rand()%1000+1,ind;
	printf("%d\n",n);
	while(ind!=n)
	{
		printf("prova a indovinare: "); 
		scanf("%d",&ind);
		if(ind==n)
			printf("hai indovinato\n");
		else if(ind<n)
			printf("troppo basso\n");
		else if(ind>n)
			printf("troppo alto\n");
	}
	getch();
}
