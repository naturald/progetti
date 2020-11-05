//marco schiavello
//dato un numero scriverlo in forma letterale
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int n,u,d,c,m;
	scanf("%d",&n);
	
	m=n/1000;
	c=(n-(m*1000))/100;
	d=(n-((c*100)+(m*1000)))/10;
	u=(n-((c*100)+(d*10)+(m*1000)))/1;
	printf("%d,%d,%d,%d",m,c,d,u);
	/*switch (scelta)
	{
		case 1:
			printf("ciao");
		break;
		case 2:
			printf("ciao2");
		break;
		case 3:
			printf("ciao3");
		break;
		default:
			printf("CIAO BOH");
		break;
	}*/
}
