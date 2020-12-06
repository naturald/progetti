//marco schiavello 3^CI 8/11/2020
//codifica in c della verifica
#include <stdio.h>
#include <conio.h>

int main()
{
	int n,n_tot=0,n_dis=0,n_par=0;
	do
	{
		printf("metti n (0=fine) : ");
		scanf("%d",&n);
		if(n!=0)
		{
			n_tot++;
			if(n%2==0)
			{
				n_par++;
			}
			else
			{
				n_dis++;
			}
		}
	}
	while(n!=0);
	printf("num tot: %d num dis: %d num par: %d \n\n",n_tot,n_dis,n_par);
	getch();
}
	
