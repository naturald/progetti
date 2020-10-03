#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int  main()
{
	srand(time(NULL));
	cout<<"Benvenuto nel gioco del tris \n\n";
	
	int i,j,turno=0,fine=0;
	char campo[3][3];
	
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			campo[i][j]=' ';
		
	
	do
	{	
		for(i=0;i<3;i++)
		{
			if(i==0)
			{
				cout<<"   0   1   2 \n";
				cout<<" o---o---o---o \n";
			}
			else
				cout<<" o---o---o---o \n";
				
			cout<<i;
			for(j=0;j<3;j++)
			{
				cout<<"| "<<campo[i][j]<<" ";
				
			}
			cout<<"|\n";
		}	
		cout<<" o---o---o---o \n";
		cout<<"\n\n";
		
		if(turno==5||fine!=0)
			break;
		
		
		
		
		cout<<"scegli cordinate dove mettere la X\n";
		do
		{
			cout<<"indica colonna tra 0 e 2: ";
			cin>> j;
			cout<<"indice righa tra 0 e 2: ";
			cin>>i;
			if(campo[i][j]=='O'||campo[i][j]=='X')
			{
				i=-1;
				cout<<"gia' occupata questa posizione rimetti \n";
			}
			cout<<"\n\n";
			
		}
		while((i<0 || i>2) ||  (j<0 || j>2));
		campo[i][j]='X';
		
		if(turno>=2)
		{
			for(i=0;i<3;i++)
			{
				if(campo[i][0]==campo[i][1] && campo[i][1]==campo[i][2])
				{
					if(campo[i][1]=='X')
					{
						
						fine=1;
						break;
					}

				}
				
				if(campo[0][i]==campo[1][i] && campo[1][i]==campo[2][i])
				{
					if(campo[1][i]=='X')
					{
						fine=1;
						break;
					}
				}
			}
			if
			(
				(campo[0][0]==campo[1][1] && campo[1][1]==campo[2][2]) 
				||
				(campo[0][2]==campo[1][1] && campo[1][1]==campo[2][0]) 
			)
			{
				if(campo[1][1]=='X')
				{
					fine=1;
					continue;
				}
			}
			if(fine!=0)
				continue;
			
		}
		
	
		
		
		
		if(turno<4)
		{
			do
			{
				i=rand()%3;
				j=rand()%3;
			}
			while(campo[i][j]=='O'||campo[i][j]=='X');
			campo[i][j]='O';
				
			if(turno>=2)
			{
				for(i=0;i<3;i++)
				{
					if(campo[i][0]==campo[i][1] && campo[i][1]==campo[i][2])
					{
						if(campo[i][1]=='O')
						{
							fine=2;
							break;
						}
	
					}
					
					if(campo[0][i]==campo[1][i] && campo[1][i]==campo[2][i])
					{
						if(campo[1][i]=='O')
						{
							fine=2;
							break;
						}
					}
				}
				if
				(
					(campo[0][0]==campo[1][1] && campo[1][1]==campo[2][2]) 
					||
					(campo[0][2]==campo[1][1] && campo[1][1]==campo[2][0]) 
				)
				{
					if(campo[1][1]=='O')
					{
						fine=2;
						continue;
					}
				}
				if(fine!=0)
					continue;
			}
		}
		
		if(turno<4)	
			for(i=0;i<20;i++)
				cout<<"\n";
		
		turno++;
	}
	while(turno<=5);
	
	if(turno==5)
		cout<<"PARITA'\n\n";
		
	switch(fine)
	{
		case 1:	
			cout<<"HAI VINTO \n\n";	
		break;
		
		case 2:	
			cout<<"HAI PERSO \n\n";
		break;	
	}

	cin>>i;
	
}
