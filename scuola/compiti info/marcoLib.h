//libreria marco schiavello 3^CI 4/12/2020
//boh e una libreria
#include <windows.h>

void tabella(int volte,bool invio=false,bool trat=false)
{
	for(int i=0;i<volte;i++)
	{
		printf("+-----");		
	}
	printf("+");
	if(invio==true)
		printf("\n");
	if(trat==true)
		printf("|");
		
}
int leggi_int(char messagio[],int da_leg) 
{
	printf("%s",messagio);
	scanf("%d",&da_leg);
	return da_leg;
}
double pow(int base,int esp,int volte=0,int ris=1,bool neg=false)
{
	if(esp==0)
		return 1;
	if(base==0)
		return 0;
	if(volte==0)
		if(esp<0)
		{
			esp*=-1;
			neg=true;
		}
	if(volte==esp)
	{
		if(neg==true)
			return (double)1/ris;
		return ris;
	}
	volte++;
	ris*=base;
	if(neg==true)
		return pow(base,esp,volte,ris,true);
	return pow(base,esp,volte,ris);
	
}
void goToXY(int x,int y)
{
	
	// questa cosatnte serve per le versioni di windows arretrate rispetto alla 10
	#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
	
	//----------abilito le ANSI sequence per windows 10----------
  	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(console, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;//bitwise OR
    SetConsoleMode(console, consoleMode);
    //------------------------------------------------------------
    
	printf("\x1b[%d;%df",y,x);
	/*
		"\x1b", sarebbe il numero esadecimale 1bche in decimale sarebbe 27. 
		27 è il numero del carattere ESC;
		questo carattere porta la stringa ad essere interpretata come una sequenza di escape.
		dove si ha la ANSI sequence con una sintassi di questo tipo "esc[righa;colonna f"
	*/

}
void tab_ascii(int N_COL)
{
	int col=0;
	tabella(N_COL,true,true);
	for(int i=0;i<256;i++)
	{
		if(i%N_COL==0&&i!=0)
		{
			printf("\n");
			tabella(N_COL,true,true);	
			col=0;
		}

		if(i<=13||i==27)
			printf("%3d %c|",i,14);
		else
			printf("%3d %c|",i,i);
		col++;
	}
	printf("\n");
	tabella(col,true);

	getch();
}
char toUpper(char c)
{
	printf("scegli minuscola --> ");
	fflush(stdin);
	scanf(" %c",&c);
	if(c>96&&c<123)
		printf("il carattere maiuscolo e'--> %c\n",c-32);//	printf("il carattere maiuscolo e'--> %c\n",toupper(c));
	else
		printf("il carattere maiuscolo e'--> %c\n",c);
	getch();
}
char toLow(char c)
{
	printf("scegli maiuscola --> ");
	fflush(stdin);
	scanf(" %c",&c);
	if(c>64&&c<91)
		printf("il carattere maiuscolo e'--> %c\n",c+32);//	printf("il carattere maiuscolo e'--> %c\n",tolower(c));?
	else
		printf("il carattere maiuscolo e'--> %c\n",c);
	getch();
}
int* singlDig(int num)
{
	/*
		MANUALE FUNZIONE 
		dato un numero come parametro restituisce un inirizzo all'array contenete le singole cifre separate 
		questo array viene salvato sull'heap e non sullo stack questo perche le funzioni quando finiscono
		cancellano tutte le varibili riferite alla funzione e chiude il blocco della riferito ad essa percio quando
		si cercherà di accedere all'indirizzo dell'array riferito alla funzione esso non esisterà piu fuori da essa
		(perciò ci sara credo un memory leak).
		facendo cosi l'heap per la durata del programma salvera quell'array in modo 
		da essere richiamato da altre parti via indirizzo notare che questo accade perche creamo un array 
		in modo che la sua dimensione sia dinamica con malloc/calloc percio viene messo nella parte delòla memoria
		chiamata heap che conservera quei dati con allocazione dinamicha di memoria.
		quando finito di utilizare l'array fare free(nome puntatore a cui avete assegnato il ritorno della funzione) in modo da evitare memory leak.
		non funzionera sizeof() sopra l'array per motivi spiegati sotto ma si potra definire la sua lunghezza
		stabilendo che il valore dell'ultima cella di esso e -1
	*/
	int n_dig = 1,somDaTogl=0,tmp=num/pow(10,n_dig);
	while(tmp!=0)
	{
		tmp=num/pow(10,n_dig);
		n_dig++;
	}
	if(n_dig!=1)
		n_dig--;
	int pot=n_dig-1;
	int *dig = (int*)calloc(n_dig+1, sizeof(int));
	/*
		si potrebbe fareanche *dig = (int*)malloc((n_dig * sizeof(int))+1) 
		ma non inizializzarebbe le celle di memoria a zero		
		RICORDARSI di castare il risultato di malloc e calloc a un puntatore di int
		se si usa calloc usare questa notazione calloc(lunchezza array, grandezza singole celle)
		se si usa malloc usare questa notazione malloc(numero totale di byte da occupre) 
		TIP: fare lunghezza desiderata array e moltiplicarla per la grandezza di ogni cella
	*/	
	dig[n_dig]=-1;
	/*
		essendo che quando ritorno l'array non posso sapere la sua lunghezza che sta puntando 
		metto una cella in piu dove mettero -1 che indica la fine dell'array  
	*/
	for(int i = 0;i<n_dig;i++)
	{
		dig[i]=(num-somDaTogl)/pow(10,pot);
		somDaTogl+=(dig[i]*pow(10,pot));
		pot--;
	}
	return dig;
}
//------------------Quick Sort------------------------
void scmbio(int * arr,int a,int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] =tmp;
}

int pos_pivot(int * arr,int min,int max)
{
	int piv = arr[max],ult_min = min;
	for(int i = min;i<=max;i++)
	{
		if(arr[i]<=piv)
		{
			scmbio(arr,i,ult_min);	
			if(i!=max)	
				ult_min ++;	
		}
	}
	return ult_min;
}

void quickSort(int * arr,int min,int max)
{
	if(min<max)
	{
		int pivI = pos_pivot(arr,min,max);
		quickSort(arr,min,pivI-1);
		quickSort(arr,pivI+1,max);
	}
}
//----------------------------------------------------
float sconto(float tot, float percentuale) 
{
	return tot - ((tot*percentuale)/100);
}




