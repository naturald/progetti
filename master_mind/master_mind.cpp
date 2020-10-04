#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int comb[4],soluz[4],i,indizzi[4]={0},tenta=0;
	
	for(i=0;i<4;i++)
		soluz[i]=rand()%10;
	
	do
	{
		for(i=0;i<4;i++)
			indizzi[i]=0;
			
		cout<<"cifre a disposizione : ";
		for(i=0;i<10;i++)
			cout<<i<<";";
		
		cout<<"\n\n\n\n";	
		
		for(i=0;i<4;i++)
		{
			cout<<"metti elemento per la combinazione: ";
			cin>>comb[i];
			while(comb[i]>9 || comb[i]<0)
			{
				cout<<"mettere un numnero tra 0 a 9 \n";
				cout<<"metti elemento per la combinazione: ";
				cin>>comb[i];	
			}
		}
		cout<<"\n";
			
		for(int j=0;j<4;j++)	
		{
			for(int x=0;x<4;x++)
			{
				if(comb[j]==soluz[x])
				{
					if(j==x)
						indizzi[j]=2;
					else
						indizzi[j]=1;
							
				}
			}
			cout<<comb[j];			
		}
				
			

		cout<<"  ";
		for(i=0;i<4;i++)
			cout<<indizzi[i];
			
		cout<<"  ";
		for(i=0;i<4;i++)
			cout<<soluz[i];
			
		cout<<"\n\n\n";	
			
		tenta++;
	}
	while(tenta<=10);
	
	
	
	
}
