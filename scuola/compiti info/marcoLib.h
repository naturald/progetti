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
