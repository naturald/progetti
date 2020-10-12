#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
	int base, lunghezza_numero, c, c1, s=0, calcolo;
	cout<<"inserisci la lunghezza del numero: ";
	cin>>lunghezza_numero;
	char  numero[lunghezza_numero];
	cout<<"inserisci il numero: ";
	cin>>numero;
	cout<<"inserisci la base del numero: ";
	cin>>base;
	cout<<endl;
	for(c=0;c<lunghezza_numero;c++)
	{
		cout<<numero[c];
	}
	cout<<" "<<base<<"=";
	for(c=lunghezza_numero-1, c1=0;c>-1;c--, c1++)
	{
		cout<<numero[c]<<"*"<<base<<"^"<<c1;;
		if(c>0)
			cout<<"+";
		else
			cout<<"=";
			
		if((numero[c]>47)&&(numero[c]<58)) 
			calcolo=(numero[c]-48)*(pow(base,c1));
		else
		{
			if((numero[c]>64)&&(numero[c]<91)) calcolo=(numero[c]-55)*(pow(base,c1));
			else calcolo=(numero[c]-87)*(pow(base,c1));
		}
		s=s+calcolo;
	}
	cout<<s;
	getch();
	return 0;
}
