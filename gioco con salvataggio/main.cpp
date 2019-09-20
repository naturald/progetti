#include <iostream>
#include <stdlib.h>
#include "prova.h"
#include <time.h>

using namespace std;

int main()
{
    string difficolta;
    string rispo;
    int error=0;
    int n;
    int risposta;
    srand (time(NULL));
    cout<<"benvenuto nel gioco indivino del numero "<<endl;
    cout<<"devi indovinare il numero nel intervallo che verra prestabilito dalla difficolta"<<endl;
    do
    {
    if(error!=0)
        cout<<"non hai messo nessuna delle 3 opzioni rimetti.."<<endl;

    cout<<"scegli la difficolta tra |facile da da 0-10|medio 0-100|difficile 0-1000| :";
    cin>>difficolta;

    if(difficolta=="facile")
        n=rand()%10+1;
    else
        if(difficolta=="medio")
            n=rand()%100+1;
        else
            if(difficolta=="difficile")
                n=rand()%1000+1;
                else
                    error++;

    }while(difficolta!="facile"&&difficolta!="medio"&&difficolta!="difficile");

    error=0;

    cout<<n<<endl;

    cout<<"indovina il numero : ";
    cin>>risposta;
    if(difficolta=="facile")
    {
        while(risposta<0||risposta>10)
        {
            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
            cin>>risposta;
        }
    }
     if(difficolta=="medio")
    {
        while(risposta<0||risposta>100)
        {
            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
            cin>>risposta;
        }
    }
    else
    {
        while(risposta<0||risposta>1000)
        {
            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
            cin>>risposta;
        }
    }

    error=0;

    if(n==risposta)
    {
        cout<<"hai vinto"<<endl;
        prova();
    }
    else
    {

        cout<<"hai sbagliato"<<endl;
        cout<<"il numero era :"<<n<<endl;
        cout<<"vuoi riprovarci :";
        cin>>rispo;
        while(rispo!="si"&&rispo!="no")
        {
            cout<<"rimetti :";
            cin>>rispo;
        }

                while(rispo=="si")
                {
                    if(difficolta=="facile")
                            n=rand()%10+1;
                        else
                            if(difficolta=="medio")
                                n=rand()%100+1;
                            else
                                if(difficolta=="difficile")
                                    n=rand()%1000+1;

                    cout<<"indovina il numero : ";
                    cin>>risposta;
                    if(difficolta=="facile")
                    {
                        while(risposta<0||risposta>10)
                        {
                            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
                            cin>>risposta;
                        }
                    }
                     if(difficolta=="medio")
                    {
                        while(risposta<0||risposta>100)
                        {
                            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
                            cin>>risposta;
                        }
                    }
                    else
                    {
                        while(risposta<0||risposta>1000)
                        {
                            cout<<"hai messo un numero troppo piccolo o troppo grande per la difficolta scelta rimetti: ";
                            cin>>risposta;
                        }
                    }

                 if(n==risposta)
                    {
                        cout<<"hai vinto"<<endl;
                        prova();
                    }
                else
                    {
                        cout<<"hai sbagliato"<<endl;
                        cout<<"il numero era :"<<n<<endl;
                        cout<<"vuoi riprovarci :";
                        cin>>rispo;
                        while(rispo!="si"&&rispo!="no")
                        {
                           cout<<"rimetti :";
                           cin>>rispo;
                        }

                    }
                }



    }

    return 0;
}
