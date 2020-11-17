//marco schiavello
//leggere in input un carattere (0= uscita) e stampare la codifica asci del carattere 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{	
	char c;
	printf("inserisci carattere: ");
	c=getch();//oppure scanf(" %c",&c);
	while(c!='0')
	{
		printf("il valore ascii e': %d\n\n\n\n",c);
		printf("inserisci carattere: ");
		c=getch();//oppure scanf(" %c",&c);
		printf("%c\n",c);
	}


}
