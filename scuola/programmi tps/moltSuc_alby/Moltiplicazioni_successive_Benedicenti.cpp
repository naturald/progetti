#include <iostream>
#include <math.h>
#define Lunghezza_massima 25  //numero massimo di numeri e lettere
using namespace std;

int main()
{
int base, lunghezza_numero=Lunghezza_massima, c, c1, pv=-1;
double s=0, calcolo;
char  numero[Lunghezza_massima]={'0'};
cout<<"inserisci il numero: ";
cin>>numero;
cout<<"inserisci la base del numero: ";
cin>>base;
cout<<endl;
for(c=0;c<Lunghezza_massima;c++)
{
if(numero[c]==0)
{
    lunghezza_numero=c;
    break;
}
if((numero[c]==44)||(numero[c]==46))
    pv=c;
}
for(c=0;c<lunghezza_numero;c++)
{
    cout<<numero[c];
}
cout<<" "<<base<<"=";
if(pv==-1)
    c1=lunghezza_numero-1;
else
    c1=lunghezza_numero-1-(lunghezza_numero-pv);
for(c=0;c<lunghezza_numero;c++)
{
    if(c!=pv)
    {
    cout<<numero[c]<<"*"<<base<<"^"<<c1;
    if(c+1<lunghezza_numero)
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
    c1--;
    }
}
cout<<s;
return 0;
}
