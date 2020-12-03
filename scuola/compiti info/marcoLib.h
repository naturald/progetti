//libreria marco schiavello 

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
void leggi_int(char messagio[],int da_leg) 
{
	printf("%s",messagio);
	scanf("%d",&da_leg);
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
