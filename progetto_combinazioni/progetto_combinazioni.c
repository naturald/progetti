//programma combinazioni creato da marco schiavello il 10/10/2020
/*
	per chiuque guardi questo programma prego di non guardare la grammatica (fa schifo lo so)
	il programma potrebbe essre non ottimizato o fare schifo ma ho provato a fare del mio meglio
*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 701

// dati gli argomenti fa la potenza
int potenza(int base,int espo)
{
	int Ris=1;
	int i;
	for(i=0;i< espo;i++)
		Ris*=base;
	
	return Ris;	
}

/*
	cerca una stringa in un array di stringhe di cardinalità card 
	(si lo chiamato array perchè logicamente sarebbe cosi solo che in c per mettere piu stringhe in uno stesso "posto" si usano le matrici di char 
	dove la lunghezza e uguale a [j] e la altezza (ovvero quante stringhe ci sono) e uguale a [i] insieme formano [i][j])
*/
int in_array(int card,char matrx[card][MAX_LEN],char ele[MAX_LEN])
{
	int i;
	int pos=-1;
	for(i=0;i<card;i++)
		if(strcmp(matrx[i],ele)==0)
		{
			pos=i;
			break;
		}	
	return pos;
}

//funzione che mette gli spazzi
void spazzi(int n_spazi)
{
	int i;
	for(i=0;i<n_spazi;i++)
		printf("\n");
}

int main()
{
	int card_n,card_k,i,j,x,ris=0,n_comb,min_len;;
	char contr[MAX_LEN];
	
	printf("Benvenuto nel calcolatore di combinazioni massime con lunghezza minima fissa \n");
	printf("di seguito dovrai mettere i dati del alfabeto sorgente e del alfabeto del codice \n \n");
	
	spazzi(3);
	
	do
	{
		printf("immetti cardinalita' del alfabeto sorgente (min 1): ");	
		scanf("%d",&card_n);
	}
	while(card_n<1);
	
	char Alf_src[card_n][MAX_LEN];
	
	// ho fatto una matrice perchè devo storare piu stringhe perciò funzione cosi char Alf_src[numero di stringhe][lunghezza ogniuna];

	for(i=0;i<card_n;i++)
	{
		printf("immetti elemento alfabeto sorgente: ");	
		scanf("%s",&contr);	
		//qua dico di assegnare la stringha in input a la righa, i e la lunghezza sara quella della parola del utente con MAX 701
		while(in_array(card_n,Alf_src,contr)!=-1)
		{
			printf("metti elementi tutti diversi\n \n");	
			printf("immetti elemento alfabeto sorgente: ");	
			scanf("%s",&contr);	
		}
		strncpy(Alf_src[i], contr, MAX_LEN);
	}	
	
	spazzi(10);
	
	do
	{
		printf("immetti cardinalita' del alfabeto del codice (min 2): ");	
		scanf("%d",&card_k);
	}
	while(card_k<2);
	
	char Alf_cod [card_k][MAX_LEN];
	//ora do al utente sono la possibilita di mettere elementi per la combinazione che possono essere anche i caratteri
	
	for(i=0;i<card_k;i++)
	{
		printf("immetti elemento alfabeto del codice: ");	
		scanf("%s",&contr);	
		while(in_array(card_k,Alf_cod,contr)!=-1||	strlen(contr)>1)
		{
			printf("metti elementi tutti diversi e di lunghezza 1\n \n");	
			printf("immetti elemento alfabeto del codice: ");	
			scanf("%s",&contr);	
		}
		strncpy(Alf_cod[i], contr, MAX_LEN);
	}	
	
	spazzi(20);
	
	/*ho optato per un assegnamento continuo dentro il ciclo perche se facevo min_len=i; fuori da cilo mi aumentava i 
	es (i=3 dentro il ciclo quando esce fuori i=4) 
	non ho capito bene il perche ma credo che centri qualcosa con l'auto incremento o se non e quello allora qualcosa 
	sulla logica del ciclo a livello di linguaggio CREDO*/
	for(i=1;ris<card_n;i++)
	{
		ris=potenza(card_k,i);
		min_len=i;
		//calcolo la lughezza minima avendo i due insiemi
	}
	
	printf("\n");
	
//------dichiao e inizializzo-----
	char comb[min_len][1];
	int status[min_len];
	
	for(i=0;i<min_len;i++)
	{
		comb[i][0]=Alf_cod[0][0];
		status[i]=0;	
	}
//---------------------------------

	//ho ripetuto per tutte le combinazioni possibili con l'insieme del alfabeto del codice 
	for(n_comb=0;n_comb!=ris;n_comb++)
	{
		//stampo la combinazione con un intervallo da pos 1 a pos min_len(sarebbe posizione precedentemente calcolata massima) 
		//questo perchè quando stampavo la stringa mi metteva o del padding o un feedline
		printf("%1.*s ",min_len,comb[0]);	
			
		//assegno in ordine le parole alle combinazioni
		if(n_comb<card_n)
			printf("= %s",Alf_src[n_comb]);
	
		//vedo se il primo ha raggiunto il massimo valore del afabelo del codice
		if(status[0]>=card_k-1)
		{
			//vedo se il numero succesivo al primo e anche lui il numero massimo del insieme
			//se si, vado avanti finche non trovo un numero diverso da quello massimo del alfabeto del codice
			for(j=1;j<min_len;j++)
				if(status[j]!=card_k-1)
				{
					status[j]++;
					break;
				}
				
			//dopo aumentare il succesivo metto a zero gli altri prima es(999 +1 =1000)
			for(x=0;x<=j-1;x++)
				status[x]=0;
		}
		else
			status[0]++;
		//se non è il numero massimo continuo ad aumentare  
	
		//metto una maschera diciamo così allo status in modo che punti al corrispetivo elemento del afabeto del codice
		for(i=0;i<min_len;i++)
			comb[(min_len-1)-i][0]=Alf_cod[status[i]][0];
			
		printf("\n");
	}
	
	getch();
	
	return 0;
	/* 
		lo fatto con lo status ovvero un altro array per il fatto che lavorare direttamente con gl'indici degli array e (per me) 100 volte piu complicato 
		preferisco fare un brute-force con i numeri per poi mascherarlo con gl'indici del'array del aflabeto del codice
	*/
}

/* 
	logica tropo annidata non si capoiva nulla e non funzionava
	
for(x=1;x<min_len && comb[min_len-x]!=Alf_cod[0] ;x++)
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
