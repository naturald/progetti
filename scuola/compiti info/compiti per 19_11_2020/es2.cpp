//marco schiavello 3^CI 14/11/2020
//es 2
#include <stdio.h>
#include <conio.h>

int main()
{
	int n=0;
	printf("metti n: " );
	scanf("%d",&n);
	while(n>4)
	{
		printf("n: %d\n",n);
		n-=4;
	}
	getch();
}
