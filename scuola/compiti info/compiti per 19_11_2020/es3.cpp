//marco schiavello 3^CI 14/11/2020
//es 3
#include <stdio.h>
#include <conio.h>

int main()
{
	int n1=0,n2=0;
	printf("metti n1: " );
	scanf("%d",&n1);
	printf("metti n2: " );
	scanf("%d",&n2);
	while(n1<50)
	{
		printf("n1: %d\n",n1);
		n1+=n2;
	}
	getch();
}
