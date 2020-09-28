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
	int y;
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
		comb[i]=Alf_cod[0];
	
	/* 

	prima prova algoritmo brute-force

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
	
	for(i=0;i<min_len;i++)
	{
		comb[i]= Alf_cod[i];
		
	}*/
	int punt_cod=0;
	int posiz;
	int flag;
	int contr=2;
	int aumen_trig;
	int comodo;
	int status[min_len-1];
	int status_len=min_len-1;
	int n=2;
	for(i=0;i<min_len;i++)
		status[i]=1;
	
	for(i=0,posiz=2,flag=1,aumen_trig=0;flag==1;i++)
	{
		for(j=0;j<min_len;j++)
		{
			if(j==(min_len-1))
				comb[j]=Alf_cod[punt_cod];
				
			printf("%d ",comb[j]);	
		}
		if(punt_cod<card_k-1)
			punt_cod++;
		else
		{	
			if(punt_cod==card_k-1)
			{
				punt_cod=0;
				
				
				if(status[0]>=card_k-1)
				{
					status[0]=1;
					status[1]++;
					posiz++;
					comb[min_len-posiz]=Alf_cod[status[1]];
					posiz--;
				}
				else
				{
					status[0]++;
					comb[min_len-posiz]=Alf_cod[status[0]];
				}
					
				
				for(x=1;x<n;x++)
				{
					comb[min_len-x]=Alf_cod[0];	
				}

				
			}
		
		
			/*for(x=1;x<min_len && comb[min_len-x]!=Alf_cod[0] ;x++)
			{
				if(comb[min_len-x]==Alf_cod[card_k-1])
				{
					for(j=0;j<card_k-1;j++)
					{
						if(comb[min_len-(x+1)]==Alf_cod[j])
						{
							if((j+1)==card_k)
							{
								for(y=2;comb[min_len-(x+y)]>=Alf_cod[card_k-1];y++)
								{
									flag_w=y;
									comodo=x+y;
								}
								for(y=0;y<card_k;y++)
								{
									if(comb[min_len-(x+flag_w)]==Alf_cod[y])
									{
										comb[min_len-(x+flag_w)]=Alf_cod[y+1];	
										
										
									}
								}
								
							}
							else
							{
								
								comb[min_len-(x+1)]=Alf_cod[j+1];	
								comodo=x+1;
								break;
								
							}
						}		
					}	
				}	
			}
			*/
		}
		
		printf("\n");

		if(comb[0]==Alf_cod[card_k-1])
			flag=0;
	}
	
	
	getch();
	
	return 0;
	
}
