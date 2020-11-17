//marco schiavello 14/11/2020
//es 1
#include <stdio.h>
#include <conio.h>

int main()
{
	int n=0;
	printf("metti n: " );
	scanf("%d",&n);
	while(n>10)
	{
		printf("n: %d\n",n);
		n-=3;
	}
	getch();
}
