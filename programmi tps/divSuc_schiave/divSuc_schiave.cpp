#include <iostream>
#include <conio.h>
#define MAX_LEN 700

using namespace std;

void hex(int n)
{
	switch(n)
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
}

int main()
{
	int base,inte[MAX_LEN]={0},dec[MAX_LEN]={0},i,part_int,j,cifr_dec;
	float n,part_dec;
	string rispo;
	do
	{
		i=0;
		for(j=0;j<MAX_LEN;j++)
		{
			inte[j]=0;
			dec[j]=0;			
		}
			
		printf("inserire numero in base 10: ");
		scanf("%f",&n);
		part_dec=n;
		part_int= (int) n;
		part_dec-=part_int;
		if(part_dec>0)
		{
			do
			{
				printf("inserisci sensibilita (min 1): ");
				scanf("%d",&cifr_dec);
			}
			while(cifr_dec<1);
		}
		printf("inserire base di arrivo: ");
		scanf("%d",&base);
		printf("\n\n\n\n\n\n");
		while(part_int!=0)
		{
			printf("%d : %d = %d + %d \n",part_int,base,part_int/base,part_int%base);
			inte[i]=part_int%base;
			part_int/=base;
			if(part_int!=0)
				i++;	
		}
		printf("\n\n\n");
		for(j=0;j<cifr_dec;j++)
		{
			if(part_dec==0.0)
				break;
			printf("%.*f * %d = %.*f --> %.*f + %d \n",cifr_dec,part_dec,base,cifr_dec,part_dec*base,cifr_dec,(part_dec*base)-(int) (part_dec*base), (int) (part_dec*base));
			part_dec*=base;
			dec[j]=(int) part_dec;
			part_dec-=(int) part_dec;
		}
		
		printf("\n\n(%.*f) 10 = (",cifr_dec,n);
		for(;i>=0;i--)
		{
			if(inte[i]>9)
				hex(inte[i]);
			else
				printf("%d",inte[i]);
		}
		printf(".");
		for(int x=0;x<j;x++)
		{
			if(dec[x]>9)
				hex(dec[x]);
			else
				printf("%d",dec[x]);
		}
		printf(") %d\n\n\n\n",base);
		printf("vuoi trasformare un altro numero si o no: ");
		cin>>rispo;
	}
	while(rispo=="si");
	getch();
}
