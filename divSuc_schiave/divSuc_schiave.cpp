#include <iostream>
#include <conio.h>
#define MAX_LEN 700

using namespace std;

int main()
{
	int n,base,comb[MAX_LEN]={0},i=0,comodo;
	printf("inserire numero in base 10: ");
	scanf("%d",&n);
	comodo=n;
	printf("inserire base di arrivo: ");
	scanf("%d",&base);
	printf("\n\n\n\n\n\n");
	while(n!=0)
	{
		printf("%d : %d = %d + %d \n",n,base,n/base,n%base);
		comb[i]=n%base;
		n/=base;
		if(n!=0)
			i++;
	}
	printf("\n\n%d 10 = ",comodo);
	for(;i>=0;i--)
	{
		if(comb[i]>9)
			switch(comb[i])
			{
				case 10:
					printf("A");
				break;
				case 11:
					printf("B");
				break;	
				case 12:
					printf("C");
				break;
				case 13:
					printf("D");
				break;
				case 14:
					printf("E");
				break;
				case 15:
					printf("F");
				break;
			}
		else
			printf("%d",comb[i]);
		
	}

	printf(" %d\n\n",base);
	getch();
}
