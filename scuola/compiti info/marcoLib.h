//libreria marco schiavello 3^CI 4/12/2020
//boh e una libreria

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
  system("cls");
  for(int i=0;i<y;i++)
    printf("\n");
  for(int j=0;j<x;j++)
    printf(" ");
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


