#include <stdio.h>
#include <string.h>
#define MAX_LEN 701

int potenza(int base,int espo)
{
	int Ris=1;
	int i;
	for(i=0;i< espo;i++)
		Ris*=base;
	
	return Ris;	
}

int main()
{
	int card_n;
	int card_k;
	int i;
	int j;
	int x;
	int ris=0;
	
	printf("Benvenuto nel calcolatore di combinazioni massime con lunghezza minima fissa \n");
	printf("di seguito dovrai mettere i dati del alfabeto sorgente e del alfabeto del codice \n \n");
	
	printf("immetti cardinalita' del alfabeto sorgente: ");	
	scanf("%d",&card_n);
	
	char Alf_src[card_n][MAX_LEN];
	// ho fatto una matrice perchè devo storare piu stringhe perciò funzione cosi char Alf_src[numero di stringhe][lunghezza ogniuna];

	for(i=0;i<card_n;i++)
	{
		printf("immetti elemento alfabeto sorgente: ");	
		scanf("%s",&Alf_src[i]);	
		//qua dico di assegnare la stringha in input a la righa i e la lunghezza sara quella della parola del utente con MAX 701
	}	
	
	printf("immetti cardinalita' del alfabeto del codice: ");	
	scanf("%d",&card_k);
	
	int Alf_cod [card_k];
	//ora do al utente sono la possibilita di mettere elementi per la combinazione che sono solo numeri interi in seguito mettero anche i caratteri
	
	for(i=0;i<card_k;i++)
	{
		printf("immetti elemento alfabeto del codice: ");	
		scanf("%d",&Alf_cod[i]);	
	}	
	
	int min_len;
	
	/*ho optato per un assegnamento continuo dentro il ciclo perche se facevo min_len=i; fuori da cilo mi aumentava i 
	es (i=3 dentro il ciclo quando esce fuori i=4) 
	non ho capito bene il perche ma credo che centri qualcosa con l'auto incremento o se non e quello allora qualcosa 
	sulla logica del ciclo a livello di linguaggio CREDO*/
	for(i=1;ris<card_n;i++)
	{
		ris=potenza(card_k,i);
		min_len=i;
	}
	
	//printf("%d",min_len);
	printf("\n");
	
	int comb[min_len];
	for(i=0;i<min_len;i++)
		comb[i]=0;
		
	int N_comb=potenza(card_k,min_len);
	int pos_simb=1;
	int pos_len;
	int simb_ele;
	int simb_back;
	for(simb_ele=0;simb_ele<card_k;simb_ele++)
	{
		for(simb_back=0;simb_back<card_k;simb_back++)
		{
			if(simb_ele==simb_back)
			{
				for(i=0;i<min_len;i++)
				{
					comb[i]=Alf_cod[simb_back];
					printf("%d ",comb[i]);	
					
					
				}
				printf("\n");
				continue;
			}
				
				
			for(pos_len=0;pos_len<min_len;pos_len++)
			{
				
				//imposto il back-ground
				for(i=0;i<min_len;i++)
					comb[i]=Alf_cod[simb_back];
					
				for(j=0;j<min_len;j++)
				{
					if(j==pos_len)
					{
						comb[j]=Alf_cod[simb_ele];			
					}
					else
					{
						comb[j]=Alf_cod[simb_back];
					}
					
					printf("%d ",comb[j]);
						
				}
				printf("\n");	
			}
		}
	
	}
	
	/*for(i=0;i<min_len;i++)
	{
		comb[i]= Alf_cod[i];
			
	}*/
	getch();
	
	return 0;
	
}
