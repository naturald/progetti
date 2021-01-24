//marco schiavello e benedicenti alberto 3^CI 
//conversione base-decimale con numeri frazzionari
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 100  //numero massimo di numeri e lettere

/*
	controlliamo se il valore ascii del carattere è nel arco dei numeri oppure delle lettere 
	dopo questa suddivisione controlliamo se sono lettere maiuscole o minuscole
	in modo da sottrarre il valore giusto per trasformarli in numeri 
*/
int CharToInt(char n)
{
    if(n>47 && n<58) // numeri
        return n-48;
    else
        if(n>64 && n<91) // lettere maiuscole
			return n-55;
        else if(n>96 && n<123) // lettere minuscole
			return n-87;
}


int main()
{
	int base,pot_num,pos_vir = -1,num_len;
	double ris, calcolo;
	char numero[MAX_LEN];//creazione array con MAX_LEN perciò da 0 a MAX_LEN-1
	char rispo;
	bool err = false;
	do
	{
		ris = 0,num_len=0;
		system("cls");
		do
		{
			system("cls");
			printf("inserisci la base del numero (2-36): ");
			scanf("%d",&base);
		}
		while(base>36||base<2);
		
		do
		{
			system("cls");
			printf("inserisci la base del numero (2-36): %d",base);
			if(err == true)
				printf("\nil numero che hai inserito non appartiene alla base selezionata");
			err = false;
			printf("\ninserisci il numero: ");
			scanf(" %s", numero);
			//controlliamo che ogni singola cifra sia contenuta nella base selezionata 
			for(int i = 0;numero[i] != 0;i++)//0 indica la fine della stringa
			{
				if(numero[i] == 44 || numero[i] == 46)
				{
					pos_vir = i;
					num_len++;
					continue;
				}
				
				if(CharToInt(numero[i]) >= base)
	        	{
	        		err = true;
	        		break;
				}
				num_len++;
			}
		}
		while(err == true);
	
		printf("\n");
		printf("( %s )",numero);
		printf("%d = ",base);
		
		/*
			Controlliamo la posizione della virgola nel numero in modo 
			da capire quale sara la potenza massima della prima cifra del numero 
		*/
		printf("\n %d %d ",num_len,pos_vir);
		if(pos_vir == -1)
		    pot_num = num_len-1;
		else
		    pot_num = pos_vir-1; //es: 1000.1 -> 4 - 1 = 3
		/* 
			Prendiamo la posizione della virgola e sottraiamo uno 
		    questo perché la posizione della virgola essendo un indice 
			incrementa da 0 dove c'è la cifra piu significativa 
		    perciò tutto quello che verrà prima della virgola sarà la parte intera
		    togliendo 1 diciamo che la parte intera va da 0 a pos della virgola -1 
			dove pos della virgola -1 indica implicitamente il numero di interi -1
			che corrisponde all esponente della cifra piu significativa del numero
		*/
		    
		    
	    /* 
			Moltiplichiamo la cifra per la base elevata alla potenza 
			che decrementera di 1 ogni volta andando a destra
			infine lo aggiungiamo al risultato per poi stamparlo
	    */	
		for(int i = 0;i<num_len;i++)
		{
		    if(i == pos_vir) // saltiamo se c'è la virgola 
		    	continue;
		    
		    printf("%c*%d^%d",numero[i],base,pot_num);
		    
		    if(i+1 == num_len)
		        printf(" = ");
		    else
		        printf(" + ");
			
			calcolo = CharToInt(numero[i]) * pow(base,pot_num);
			//prendiamo il simbolo che rappresenta il numero in posizione i-esima per fare i calcoli
			
		    ris += calcolo;
		    pot_num--;
		}
		if(pos_vir == -1)
			printf("%.f",ris);
		else
			printf("%f",ris);
			
		printf("\n\nvuoi fare un altro numero ( s o n ): ");
		scanf(" %c",&rispo);
	}
	while(rispo == 's');
}
