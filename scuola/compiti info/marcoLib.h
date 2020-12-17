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
float pow(int base,int esp,int volte=0,int ris=1,bool neg=false)
{
	if(volte==0)
		if(esp<0)
		{
			esp*=-1;
			neg=true;
		}
	if(volte==esp)
	{
		if(neg==true)
			return (float)1/ris;
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

