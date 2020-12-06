//marco schivello 3^CI 25/09/2020
//inesrire ore per sestituire data in ore minuti secondi
#include <stdio.h>
#include <conio2.h>

int main()
{
	int ore,min,sec,ts;
	
	printf("inserire ore: ");
	scanf("%d",&ore);
	
	printf("inserire min: ");
	scanf("%d",&min);
	
	printf("inserire sec: ");
	scanf("%d",&sec);
	
	ts=(ore*3600)+(min*60)+sec;
	
	printf("i secondi totali sono sono: %d",ts);
}
