//marco schiavello 15/10/2020
//peso medio
#include <stdio.h>
#include <conio.h>//SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")

int main()
{
	int n,ris=0,i;
	printf("inserire num : ");
	scanf("%d",&n);
	if(n<0)
		n=n*-1;
	
	
	for(i=1;i<n;i=i+2)
		ris=ris+i;
	
	printf("il quadrato e'' : %d",ris);
}
