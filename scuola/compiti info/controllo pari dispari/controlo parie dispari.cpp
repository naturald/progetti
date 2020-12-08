//marco schiavello 3^CI 1/10/2020
//programma che dice se pari o dispari 
#include <stdio.h>
#include <conio.h>

int main()
{
	int n;
	printf("mettere numero: ");
	scanf("%d",&n);
	if(n!=0)
		if((n/2)*2==n)
			printf("e pari");
		else
			printf("e disspari");
	else
		printf("non si puo con 0");
		
	getch();
	
}
