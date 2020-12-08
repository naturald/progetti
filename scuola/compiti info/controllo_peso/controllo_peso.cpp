//marco schiavello 3^CI 08/10/2020
//chiedere peso e età e dire se si è normo peso o no 
#include <stdio.h>
#include <conio.h>
#define MAX_INT 1000000000 //inetro massimo usato in questo programma per computare

int main()
{
	int eta,peso;
	
	do
	{
		printf("metti la tua eta (min 1): ");
		scanf("%d",&eta);
	}
	while(eta<=0||eta>MAX_INT);
	
	do
	{
		printf("metti il tuo peso (min 1): ");
		scanf("%d",&peso);
	}
	while(peso<=0||peso>MAX_INT);

	if(eta<=18)
		if(peso<=60)
			printf("sei in pesoforma");
		else
			printf("non sei in pesoforma");		
	else if(eta<=50)
		if(peso<=70)
			printf("sei in pesoforma");
		else
			printf("non sei in pesoforma");	
	else
		if(peso<=75)
			printf("sei in pesoforma");
		else
			printf("non sei in pesoforma");	
		
	getch();
}
