//Marco Schiavello 3^CI 24/11/2020
/*
	Cassa automatica
	Progetta un terminale per automatizzare la spesa in un supermercato:
	il terminale deve contare il numero di prodotti messi nel carrello, con il vincolo che la spesa può avere come importo massimo 100 euro.
*/
#include <stdio.h>

int main()
{
	int	prez_art,n_art=0,tot=0;
	bool max=false;//flag che dice se si è raggiunto il massimo o no 
	do
	{
		printf("mettere prezzo prodotto (0 = esci): ");
		scanf("%d",&prez_art);
		if(tot+prez_art>100||prez_art==0)
		{
			max=true;
		}
		else
		{
			tot+=prez_art;
			n_art++;	
			if(tot==100)
				max=true;
		}
	}
	while(max==false);
	printf("il totale e': %d \nnumero di art e': %d",tot,n_art);
}
