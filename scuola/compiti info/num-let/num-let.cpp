//marco schiavello 3^CI 5/11/2020
//dato un numero scriverlo in forma letterale
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void migliaglia(int m)
{
	switch (m)
	{
		case 2:
			printf("due ");
		break;
		case 3:
			printf("tre ");
		break;
		case 4:
			printf("quatro ");
		break;
		case 5:
			printf("cinque ");
		break;
		case 6:
			printf("sei ");
		break;
		case 7:
			printf("sette ");
		break;
		case 8:
			printf("otto ");
		break;
		case 9:
			printf("nove ");
		break;
	}
	if(m==1)
		printf("mille ");
	else if(m!=0)
		printf("mila ");
}
void centinaia(int c,int u)
{
	switch (c)
	{
		case 2:
			printf("due ");
		break;
		case 3:
			printf("tre ");
		break;
		case 4:
			printf("quatro ");
		break;
		case 5:
			printf("cinque ");
		break;
		case 6:
			printf("sei ");
		break;
		case 7:
			printf("sette ");
		break;
		case 8:
			printf("otto ");
		break;
		case 9:
			printf("nove ");
		break;
	}
	if(c!=0)
		if(u==1||u==8)
			printf("cent ");
		else
			printf("cento ");
}
void decine_unita(int d,int u)
{
	switch (d)
	{
		case 1:
			switch (u)
			{
				case 0:
					printf("dieci ");
				break;
				case 1:
					printf("undici ");
				break;
				case 2:
					printf("dodici ");
				break;
				case 3:
					printf("tredici ");
				break;
				case 4:
					printf("quattordici ");
				break;
				case 5:
					printf("quindici  ");
				break;
				case 6:
					printf("sedici ");
				break;
				case 7:
					printf("diciassette ");
				break;
				case 8:
					printf("diciotto ");
				break;
				case 9:
					printf("diciannove ");
				break;
			}
		break;
		case 2:
			if(u==1||u==8)
				printf("vent ");
			else
				printf("venti ");	
		break;
		case 3:
			if(u==1||u==8)
				printf("trent ");
			else
				printf("trenta ");	
		break;
		case 4:
			if(u==1||u==8)
				printf("quarant ");
			else
				printf("quaranta ");	
		break;
		case 5:
			if(u==1||u==8)
				printf("cinquant ");
			else
				printf("cinquanta ");	
		break;
		case 6:
			if(u==1||u==8)
				printf("sessant ");
			else
				printf("sessanta ");	
		break;
		case 7:
			if(u==1||u==8)
				printf("settant ");
			else
				printf("settanta ");	
		break;
		case 8:
			if(u==1||u==8)
				printf("ottant ");
			else
				printf("ottanta ");	
		break;
		case 9:
			if(u==1||u==8)
				printf("novant ");
			else
				printf("novanta ");	
		break;
	}
	if(d!=1)
		switch (u)
		{
			case 0:
				printf("zer0 ");
			break;
			case 1:
				printf("uno ");
			break;
			case 2:
				printf("due ");
			break;
			case 3:
				printf("tre ");
			break;
			case 4:
				printf("quatro ");
			break;
			case 5:
				printf("cinque  ");
			break;
			case 6:
				printf("sei ");
			break;
			case 7:
				printf("sette ");
			break;
			case 8:
				printf("otto ");
			break;
			case 9:
				printf("nove ");
			break;
		}
}

int main()
{
	int n,u,d,c,m;
	
	do
	{
		printf("inserire un numero (tra 1 e 9999 ) : ");
		scanf("%d",&n);		
	}
	while(n<0||n>9999);
	
	m=n/1000;
	c=(n-(m*1000))/100;
	d=(n-((c*100)+(m*1000)))/10;
	u=(n-((c*100)+(d*10)+(m*1000)))/1;
	printf("%d,%d,%d,%d \n",m,c,d,u);
	
	migliaglia(m);
	centinaia(c,u);
	decine_unita(d,u);
	
	printf("\n");
	getch();
}
