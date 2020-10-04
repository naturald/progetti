#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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



int main()
{
	srand(time(NULL));
	int comb[4],soluz[4]={-1},i,indizzi[4]={0},tenta=0,primo,pos_sbagl,prov_sol,com_sort;
	
	for(i=0;i<4;i++)
	{
		do
		{
			prov_sol=rand()%10;	
		}
		while(cerca_ele(soluz,prov_sol)!=-1);
		soluz[i]=prov_sol;
	}

	
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
					{
						indizzi[j]=2;	
						break;					
					}
					else	
					{
						primo=prim_occ(comb,comb[j]);
						if(primo==j)
							indizzi[j]=1;
						else
							indizzi[j]=0;
					}				
				}
			}			
		}
		for(i=0;i<4;i++)	
		{
			if(indizzi[i]==2)
				for(int j=0;j<4;j++)
					if(comb[i]==comb[j]&&i!=j)
						indizzi[j]=0;
			
			cout<<comb[i];			
		}
				
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

		cout<<"  ";
		for(i=0;i<4;i++)
			cout<<indizzi[i];
			
		cout<<"  ";
		for(i=0;i<4;i++)
			cout<<soluz[i];
			
		cout<<"\n\n\n";	
			
		tenta++;
	}
	while(tenta<10);
	
	
	
	
}
