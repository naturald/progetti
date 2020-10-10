//programma emulazione del gioco Mastermind creato da Marco schiavello  il 05/10/2020
/*
	chiunque guardi il codice prego di non guardare l'aspetto grammatico (lo so fa schifo)
	il programma non è ottimizato al meglio ma ho cercato di fare il mio meglio senza guardare da internet
*/
#include <iostream>
#include <stdlib.h>//per rand() e srand()
#include <time.h>//per time(NULL)
#include <conio.h>//per getch()
#define LEN_MAX 1000000000
using namespace std;

//funzione che cerca la prima occorenza di un elemento in un array
int prim_occ(int arr[4],int ele)
{
	int pos_prim;
	for(int i=0;i<4;i++)	
		if(arr[i]==ele)
		{
			pos_prim=i;
			break;
		}
		
	return pos_prim;
}
//funzione per vedere se è presente un elemento in un array di cardinalità 4
int cerca_ele(int arr[4],int ele)
{
	int pos=-1;
	for(int i=0;i<4;i++)
		if(arr[i]==ele)
		{
			pos=i;
			break;
		}
		
	return pos;		
}
//funzione per mettere spazzi
void spazzi(int n_spaz)
{
	for(int i=0;i<n_spaz;i++)
		cout<<"\n";
}
void linea()
{
	for(int i=0;i<70;i++)
		cout<<"-";
}

int main()
{

	srand(time(NULL));
	//da un seed alla combinazione casuase ad ogni seed è associata una combinazione fissa ma se cambiamo il seed ogni volta avremmo combinazioni diverse 
	//questo è possibile  grazie a time() che returna i secondi da una data 1970(credo) il numero dei secondi cambia sempre dando sempre un seed diverso a srand()
	int comb[4],soluz[4]={-1},i,indizzi[4]={0},tenta=0,primo,pos_sbagl,prov_sol,com_sort,n_volt2;
	string risposta;
	
	cout<<"Benvenuto sul gioco Mastermind \nvuoi leggere il manuale prima di iniziare rispondi si o no : ";
	cin>>risposta;
	while(risposta!="no"&&risposta!="si")
	{
		cout<<"mettere si o no : ";
		cin>>risposta;
	}
	if(risposta=="si")
	{
		spazzi(20);
		cout<<"Questo programma si basa su un gioco da tavolo chiamato 'Mastermind'\n";
		cout<<"dove c'e' un codificatore (in questo caso il programma) che crea un codice nascosto a chi deve cercare di indovinarte \n";
		cout<<"colui che cerca di indovinare ha 10 tentativi per indovinare la combinaziione nascosta se no perde\n";
		cout<<"in caso sbagliasse la conmbinazione gli verranno dati degli indizzi\n";
		cout<<"dove il 2 significa che un numero non specificato della combinazione e'esatto ed e' nella posizione giusta \n";
		cout<<"l'indizio con numero 1 indica che un numero non specificato e' giusto ma non nella posizione corretta \n";
		cout<<"\n\n\n\n PREMERE QUALSIASI TASTO PER INIZIARE A GIOCARE\n\n\n\n";
	
		getch();
	}
	
	//per creare un effetto di pagina nuova 
	spazzi(50);
	
	//creo il codice nascosto che ha ogni singolo numero diverso dal altro grazie alla funzione creata sopra cerca_ele()
	for(i=0;i<4;i++)
	{
		do
		{
			prov_sol=rand()%10;	
		}
		while(cerca_ele(soluz,prov_sol)!=-1);
		soluz[i]=prov_sol;
	}


	//ciclo che cicla per 10 volte, 10 perché corrispondono ai tentativi massimi 
	do
	{
		for(i=0;i<4;i++)
			indizzi[i]=0;
			
		cout<<"cifre a disposizione : ";
		for(i=0;i<10;i++)
			cout<<i<<";";
		
		spazzi(4);	
		
		for(i=0;i<4;i++)
		{
			cout<<"metti numero per la combinazione tra quelli a disposizione: ";
			cin>>comb[i];
			while((comb[i]>9 || comb[i]<0)|| cin.fail())//cin.fail() chiede lo stato dell input ovvero di cin
			{
				cin.clear();//pulisce l'input stream 
				cin.ignore(LEN_MAX, '\n');// ignora i caratteri messi in precedenza fino a LEN_MAX che è uguale a 1000000000
			
				/*
					ho fatto questo perché se si prova a mettere un  carattere o una stringha dentro una variablie intera 
					si avrà come se il buffer dell input fosse sempre "pieno" o completato  dopo qualche ricerca ho scoperto che questo è dovuto 
					dal fatto  che il cin e uno stato fallimentare e attiva una flag d'errore che è il motivo per cui continua a ciclare all'infinito 
					lui cicla fino a che la flag dell'errore e il buffer non sono resettati (o almeno credo)
				*/
				cout<<"mettere un numnero tra 0 a 9 \n";
				cout<<"metti numero per la combinazione tra quelli a disposizione: ";
				cin>>comb[i];	
			}
		}
		cout<<"\n";
			
		//confronto gli elementi del tentativo con quelli della combinazione segreta
		for(int j=0;j<4;j++)	
		{
			for(int x=0;x<4;x++)
			{
				if(comb[j]==soluz[x])
				{
					if(j==x)
					{
						indizzi[j]=2;	
						break;	
						//chiamo il break in modo da evitare giri di ciclo inutili e che rovinerebberò il risultato finale
					}
					else	
					{
						primo=prim_occ(comb,comb[j]);
						if(primo==j)
							indizzi[j]=1;
						else
							indizzi[j]=0;
						
						//se j!=k ovvero il numero è giusto ma posizione sbagliata e ci sono piu numeri uguali nel tentativo allora chiamo la funz prim_occ() 
						//che trova la prima occorenza del numero passato nel array passato  facendo cosi tento conto del numero solo la prima volta che lo incontro 
						//evitando cosi di mettere 1 in piu 
					}				
				}
			}			
		}
		//questo ciclo è stato fatto principalmente per togliere quei numeri che ripetendosi prendevo il primo solo che il primo magari era nella posizione sbagliata
		//e magari uno dei successivi è giusto al posto giusto percio cosi controllo se uno di quei numeri era giusto e nel posto giusto e se è cosi cancello gli altri indizzi 
		//riferiti a quel numero che si ripete mettendoli a 0
		for(i=0;i<4;i++)	
		{
			if(indizzi[i]==2)
				for(int j=0;j<4;j++)
					if(comb[i]==comb[j]&&i!=j)
						indizzi[j]=0;
			
			cout<<comb[i];			
		}
		
		
		//sorto gli indizzi in modo che non si capisca dalla posizione del indizzio a chi è riferito	
		for(i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{		
				if(indizzi[i]>indizzi[j])
				{
					com_sort=indizzi[j];
					indizzi[j]=indizzi[i];
					indizzi[i]=com_sort;
				}
			}
		}

		cout<<"  indizzi: ";
		for(i=0,n_volt2=0;i<4;i++)
		{
			cout<<indizzi[i];
			if(indizzi[i]==2)
				n_volt2++;
		}
		
		spazzi(3);	
		linea();
		spazzi(3);	
		
		if(n_volt2==4)
		{
			cout<<"HAI VINTO \n\n";	
			break;	
		}
	
		tenta++;
		
	}
	while(tenta<10);
	
	if(n_volt2<4)
		cout<<"HAI PERSO \n\n";	
		
	cout<<"la combinazione giusta era: ";
	for(i=0;i<4;i++)
		cout<<soluz[i];
		
	spazzi(4);
	
		
	
	getch();	
}
