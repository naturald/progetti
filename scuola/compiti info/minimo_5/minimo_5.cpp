//marco schiavello 3^CI 08/10/2020
//chiedere 5 numeri e restituire il minimo 
#include <stdio.h>
#include <conio.h>
#define MAX_INT 1000000000 //inetro massimo usato in questo programma per computare

int main()
{
	int min=MAX_INT,n,i=0;
	
	do
	{
		do
		{
			printf("inserire n: ");
			scanf("%d",&n);	
		}
		while(n<(-MAX_INT)||n>MAX_INT);
		
		if(n<min)
			min=n;
		i++;//i=i+1;
	}
	while(i<5);
	
	printf("il minimo tra i 5 num e': %d",min);
	
	getch();
	
}
