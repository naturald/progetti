//marco schiavello
//leggere in input un carattere (0= uscita) e stampare la codifica asci del carattere 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{	
	char c;
	do
	{
		printf("inserisci carattere: ");
		c=getch();
		printf("%c\n",c);
		printf("il valore ascii e': %d\n",c);

	}
	while(c!='0');

}
