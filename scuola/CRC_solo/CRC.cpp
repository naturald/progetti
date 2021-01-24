#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int getLenB(int mes)
{
	int len_mes;
	for(len_mes = 0;mes>0;len_mes++)
		mes >>= 1;
	return len_mes;		
}
void printB(int bina)
{
	if(!bina)
		return;
	if(bina & 1)
	{
		bina >>= 1;
		printB(bina);
		printf("1");	
	}
	else
	{
		bina >>= 1;
		printB(bina);
		printf("0");	
	}
}
int main()
{
	srand(time(NULL));
	int mes = (rand()%254)+1;
	mes <<= 3;
	int pol = 11,res = mes;
	pol<<= getLenB(mes)-4;
	bool err = false;
	
	for(int i = 1;res>>3;i++)
	{
		for(int j= 0 ;j<11-getLenB(res);j++)
			printf("0");
		printB(res);
		printf("\n");
		for(int j= 0 ;j<11-getLenB(pol);j++)
			printf("0");
		printB(pol);
		printf("\n\n");
		if(res & (int)pow(2,(float)getLenB(mes)-i))
			res ^= pol;
		pol >>= 1;
	}
	
	printf("----------------------------------------\n");
	pol=11;
	pol<<= getLenB(mes)-4;
	int recive = mes+res;
	for(int i = 1;i<getLenB(mes<<3)&&recive!=0;i++)
	{
		for(int j= 0 ;j<11-getLenB(recive);j++)
			printf("0");
		printB(recive);
		printf("\n");
		for(int j= 0 ;j<11-getLenB(pol);j++)
			printf("0");
		printB(pol);
		printf("\n\n");
		if(recive & (int)pow(2,(float)getLenB(mes)-i))
			recive ^= pol;
		pol >>= 1;
	}
	printB(recive);
	if(recive!=0)
		printf("c'e'un errore");
	else
		printf("tutto ok");		

}
