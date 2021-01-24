#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LEN 8
#define PAR 4

void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color + (__BACKGROUND << 4));
}

void getWorkcode(int * workcode,int pos_err = -1,int cor_err = -1)
{
	for(int i = 0;i<=(LEN+PAR);i++)
	{
		if(i == pos_err)
			textcolor(5);
		else
			if(i == cor_err)
				textcolor(2);	
			else
				if(i == 0)
					textcolor(3);
				else
					if(i == 1 || i== 2 || i== 4 || i== 8)
						textcolor(4);
					else
						textcolor(15);
						
		printf("%d",workcode[i]);	
	}
}
int main()
{
	srand(time(NULL));
	int mes[LEN],workcode[(LEN+PAR)+1],uno_tot=0,err;
	
	//genero messagio
	for(int i = 0; i<LEN;i++)
	{
		mes[i] = rand()%2;	
		printf("%d",mes[i]);
	} 
	printf("\n");
	
	//metto il messagio crato sopra nel workcode con dovuti spazzi per parity bit e il bit 0
	for(int i = 1, j = 0,abs = 1; i<=(LEN+PAR);i++)
		if(i ==  1 || i== 2 || i== 4 || i== 8)
		{
			workcode[i] = 0;
			abs ++;
		}
		else
		{
			workcode[j+abs] = mes[j];
			j ++;
		}	
		
	//calcolo i parity bit 
	for(int i = 0, n_uno = 0; i<PAR;i++)
	{
		n_uno = 0;
		int bit_sele = (int)pow(2,(float)i);
		for(int j = 1;j<=(LEN+PAR);j++)
		{
			if((j & bit_sele) == bit_sele)
				if(workcode[j]==1)
					n_uno++;
			if(workcode[j]==1 && i==0)
				uno_tot++;
		}
		if(n_uno%2 == 1)
			workcode[bit_sele] = 1;
		else
			workcode[bit_sele] = 0;
	} 
	if(uno_tot%2 == 1)
			workcode[0] = 1;
		else
			workcode[0] = 0;
			
	//metto errore a caso
	err = (rand()%(LEN+PAR))+1;
	
	getWorkcode(workcode);
	
	workcode[err] = !workcode[err];
	printf("\n");
	
	getWorkcode(workcode,err);
	
	//simulazione recezione messaggio
	int pos_err = 0;
	
	//trovo erroe 
	for(int i = 0;i<=(LEN+PAR);i++)
		if(workcode[i] == 1)
			pos_err ^= i;
			
	//corrego errore
	workcode[pos_err] = !workcode[pos_err];
	printf("\n");
	
	getWorkcode(workcode,-1,pos_err);
}
