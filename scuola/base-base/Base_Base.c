//marco schiavello e alberto  benedicenti 3^CI
//conversione base-decimale con numeri frazzionari
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_LEN 100  //numero massimo di numeri e lettere
#define LEN_RIS 100

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

char IntToChar(int n)
{
    if(n<10)
        return n+48;
    else if(n<36)
            return n+55;
}


int main()
{
	int base_par, base_ar,pot_num,pos_vir = -1,num_len,n_dec, n_int,i,j,part_int, inte[LEN_RIS], dec[LEN_RIS];
	double ris, calcolo, part_dec;
	char numero[MAX_LEN];//creazione array con MAX_LEN perciò da 0 a MAX_LEN-1
	char rispo;
	bool err;
	do
	{
		ris = 0, err = false, n_int=0;
        for(i=0;i<MAX_LEN;i++)
		{
			inte[i]=0;
			dec[i]=0;
		}
		system("cls");
		do
		{
		    num_len=0, pos_vir=-1;
			system("cls");
			if(err == true)
            {
                printf("base di partenza (2-36): %d",base_par);
                printf("\n\nil numero che hai inserito non appartiene alla base selezionata");
                getch();
                system("cls");
                do
                {
                    system("cls");
                    printf("base di partenza (2-36): ");
                    scanf("%d",&base_par);
                }
                while(base_par>36||base_par<2);
                printf("\nnumero di partenza: ");
                scanf(" %s", numero);
                err = false;
            }
            else
            {
                do
                {
                    system("cls");
                    printf("base di partenza (2-36): ");
                    scanf("%d",&base_par);
                }
                while(base_par>36||base_par<2);
                printf("\nnumero di partenza: ");
                scanf(" %s", numero);
            }

			//controlliamo che ogni singola cifra sia contenuta nella base selezionata
			for(i = 0;numero[i] != 0;i++)//0 indica la fine della stringa
			{
				if(numero[i] == 44 || numero[i] == 46)
				{
					pos_vir = i;
					num_len++;
					continue;
				}

				if(CharToInt(numero[i]) >= base_par)
	        	{
	        		err = true;
	        		break;
				}
				num_len++;
			}
		}
		while(err == true);
		do
        {
            system("cls");
            printf("base di partenza (2-36): %d",base_par);
            printf("\n\nnumero di partenza: %s",numero);
            printf("\n\nbase di arrivo (2-36): ");
            scanf("%d",&base_ar);
        }
		while(base_ar>36||base_ar<2);

		if(pos_vir != -1)
        {
            do
			{
			    system("cls");
                printf("base di partenza (2-36): %d",base_par);
                printf("\n\nnumero di partenza: %s",numero);
                printf("\n\nbase di arrivo (2-36): %d",base_ar);
				printf("\n\ninserisci sensibilita (min 1): ");
				scanf("%d",&n_dec);
			}
			while(n_dec<1);
        }

		printf("\n");
		printf("( %s )",numero);
		printf("%d = ",base_par);

		/*
			Controlliamo la posizione della virgola nel numero in modo
			da capire quale sara la potenza massima della prima cifra del numero
		*/
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
		for(i = 0;i<num_len;i++)
		{
		    if(i == pos_vir) // saltiamo se c'è la virgola
		    	continue;

		    printf("%c*%d^%d",numero[i],base_par,pot_num);

		    if(i+1 == num_len)
		        printf(" = ");
		    else
		        printf(" + ");

			calcolo = CharToInt(numero[i]) * pow(base_par,pot_num);
			//prendiamo il simbolo che rappresenta il numero in posizione i-esima per fare i calcoli

		    ris += calcolo;
		    pot_num--;
		}
		if(pos_vir == -1)
			printf("%.f",ris);
		else
			printf("%.4f",ris);

        printf("\n\n");
        //dividiamo il nuumero il parte decimale e frazzionaria
		part_int=(int)ris;
		part_dec=ris-(int)ris;
		
		while(part_int!=0)
		{
			printf("%d : %d = %d + %d \n",part_int,base_ar,part_int/base_ar,part_int%base_ar);
			inte[n_int]=part_int%base_ar;
			part_int/=base_ar;
			if(part_int!=0)
            	n_int++;
		}
        printf("\n");

		for(j=0;j<n_dec;j++)
		{
			if(part_dec==0.0)
				break;

			printf("%.5f * %d = %.5f --> %.5f + %d \n",part_dec,base_ar,part_dec*base_ar,(part_dec*base_ar)-(int) (part_dec*base_ar), (int) (part_dec*base_ar));
			part_dec*=base_ar;
			dec[j]=(int) part_dec;
			part_dec-=(int) part_dec;
		}

		printf("\n\n( ");
		if(pos_vir == -1)
			printf("%.f",ris);
		else
			printf("%.5f",ris);
			
		printf(" ) 10 = ( ",ris);
		
		for(i=n_int;i>=0;i--)
		{
			printf("%c",(IntToChar(inte[i])));
		}
		
		if(pos_vir != -1)
        {
            printf(".");
            for(int i=0;i<n_dec;i++)
            {
                printf("%c",(IntToChar(dec[i])));
            }
        }
        printf(" )%d",base_ar);
		printf("\n\nvuoi fare un altro numero ( s o n ): ");
		scanf(" %c",&rispo);
	}
	while(rispo == 's');
}
