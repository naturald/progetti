//marco schivello 3^CI 25/09/2020
//inesrire ora in ora minuti e secondi per averla solo in secondi totali
#include <stdio.h>
#include <conio.h>

int main()
{
	int ore,min,sec,tempo_s;
	
	printf("inserire ore: ");
	scanf("%d",&ore);
	
	printf("inserire min: ");
	scanf("%d",&min);
	
	printf("inserire sec: ");
	scanf("%d",&sec);
	
	tempo_s=(ore*3600)+(min*60)+sec;
	
	printf("i secondi totali sono sono: %d",tempo_s);
}
