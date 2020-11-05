//marco schiavello 15/10/2020
//quadrato con primi n numeri dispari
#include <stdio.h>
#include <conio.h>//SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")

int main()
{
	int n,ris=0,i,n_disp=1;
	printf("inserire num : ");
	scanf("%d",&n);
	if(n<0)
		n=n*-1;
	
	
	for(i=0;i<n;i=i+1)
	{
		ris=ris+n_disp;
		n_disp=n_disp+2;
	}
	
	printf("il quadrato e' : %d \n\n",ris);
	getch();
}
