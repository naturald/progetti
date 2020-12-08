//marco schiavello 3^CI 08/10/2020
//contare e stampare i numeri da 1 a n
#include <stdio.h>
#include <conio.h>
#define MAX_INT 1000000000 //inetro massimo usato in questo programma per computare

int main()
{
	int i=1,n_max;
	printf("metti numero fine arco di numeri da 0 a numero che scegli(min 2 max 1000000000 ): ");
	scanf("%d",&n_max);
	while(n_max<2||n_max>MAX_INT)
	{
		printf("rimetti: ");
		scanf("%d",&n_max);	
	}
	
	do
	{
		printf("%d \n",i);
		i++;//i=i+2;
	}
	while(i<=n_max);
	getch();
}
