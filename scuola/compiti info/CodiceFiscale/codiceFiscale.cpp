/*
    Marco Schiavello 3^CI 25/03/2021

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define COD_lEN 16
#define NOME_COGN_LEN 30
const char vocali[5] = {'A','E','I','O','U'};

/*
    dato un carattere controlla se è nell'array delle vocali
    ovvero se il carattere e un carattere
    Parametri:
        -char c : input
*/
bool isVocale(char c)
{
    for(int i = 0;i<strlen(vocali);i++)
        if(toupper(c) == vocali[i])
            return true;
    return false;
}

void insertCons(char str[],char codice[],int len,int start)
{
    int nItera = 0,i = 0,letTrov = 0;
    while(letTrov < len)
    {
        if(i == strlen(str))
        {
            i = 0;
            nItera++;
        }
        switch(nItera)
        {
            case 0:
            {
                if( (toupper(str[i])>='A'&&toupper(str[i])<='Z') && !isVocale(str[i]) )
                {
                    codice[start+letTrov] = toupper(str[i]);
                    letTrov++;
                }
                break;
            }
            case 1:
            {
                if( (toupper(str[i])>='A'&&toupper(str[i])<='Z') && isVocale(str[i]) )
                {
                    codice[start+letTrov] = toupper(str[i]);
                    letTrov++;
                }
                break;
            }
            case 2:
            {
                codice[start+letTrov] = 'X';
                letTrov++;
                break;
            }
        }
        i++;
    }
}
/*
    data una stringa controlla che tutti
    i caratteri siano contemplati per un cognome.
    controlla se il nuemro di caratteri consentiti
    e minore della lunghezza della stringa se si
    ritorna lo stato della stringa invalida
    Parametri:
        -char cognome[] : input
*/
int checkCognome(char cognome[])
{
    int checked = 0;
	while( cognome[checked] && ( (toupper(cognome[checked])>='A' && toupper(cognome[checked])<='Z') || cognome[checked] == ' ' || cognome[checked] == '\'') )
		checked++;
    if(checked < strlen(cognome))
    {
        printf("non e un cognome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

/*
    controlla se il nuemro di caratteri consentiti
    e minore della lunghezza della stringa se si
    ritorna lo stato del cognome invalida
    Parametri:
        -char cognome[] : input
*/
void getCognome(char cognome[])
{
    bool err = false;
    do
    {
        printf("metti il tuo cognome : ");
        gets(cognome);
        err = checkCognome(cognome);
    }
    while(err);
}

/*
    data una stringa controlla che tutti
    i caratteri siano contemplati per un nome.
    controlla se il nuemro di caratteri consentiti
    e minore della lunghezza della stringa se si
    ritorna lo stato della stringa invalida
    Parametri:
        -char nome[] : input
*/
int checkNome(char nome[])
{
    int checked = 0;
	while( nome[checked] && ((toupper(nome[checked])>='A' && toupper(nome[checked])<='Z')))
		checked++;
    if(checked < strlen(nome))
    {
        printf("non e un nome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

/*
    controlla se il nuemro di caratteri consentiti
    e minore della lunghezza della stringa se si
    ritorna lo stato del nome invalida
    Parametri:
        -char nome[] : input
*/
void getNome(char nome[])
{
    bool err = false;
    do
    {
        printf("metti il tuo cognome : ");
        gets(nome);
        err = checkNome(nome);
    }
    while(err);
}

int main()
{

    char nome[NOME_COGN_LEN],cognome[NOME_COGN_LEN],codice[COD_lEN];
    getCognome(cognome);
    getNome(nome);
    insertCons(cognome,codice,3,0);
    printf("%s",codice);

    return 0;
}
