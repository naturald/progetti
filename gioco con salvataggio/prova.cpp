#include "prova.h"

using namespace std;

void prova()
{
    string punti;
    int v;
    string risposta;
    int error=0;
    int p=0;
    ifstream q("prova.txt");

    if(!q)
    {
        punti="0";
    }
    else
    getline(q,punti);

    p=atoi(punti.c_str());


    cout<<"i tuoi punti sono : "<<punti<<endl;

    cout<<"vuoi azzare i tuoi punti rispondere si o no : ";
    cin>>risposta;


    if(risposta=="no")
    {
        ofstream q("prova.txt");
        p++;
        q<<p;

    }
    if(risposta=="si")
    {
        p=0;
        ofstream q("prova.txt");
        q<<0;
    }


    q.close();

    cout<<"i tuoi punti attuali sono : "<<p;
    cin>>v;

}


