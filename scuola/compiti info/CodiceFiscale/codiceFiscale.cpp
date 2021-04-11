/*
    Marco Schiavello 3^CI 25/03/2021

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define COD_lEN 16
#define NOME_COGN_LEN 30
const char vocali[5] = {'A','E','I','O','U'};
const unsigned char accentate[10] = {133,138,161,149,151,183,212,222,227,235};// à è ì ò ù ...

void toUpStr(char str[])
{
    for(int i = 0;i<strlen(str);i++)
        str[i] = toupper(str[i]);
}

bool isAcent(char c)
{
    for(int i = 0;i<strlen((char*)accentate);i++)
        if((unsigned char)c == accentate[i])
            return true;
    return false;
}


bool AcenToChar(char arr[],int index)
{
    if(isAcent(arr[index]))
    {
        switch((unsigned char)arr[index])
        {
            case 133:
                arr[index] = 'a';
            break;
            case 138:
                arr[index] = 'e';
            break;
            case 161:
                arr[index] = 'i';
            break;
            case 149:
                arr[index] = 'o';
            break;
            case 151:
                arr[index] = 'u';
            break;
        }
        return true;
    }

    return false;
}

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

/*
    data un lunghezza del codice lo creerà
    mettendo prima le consonanti della stringa
    finite prende le vocali se finiscono pure quelle
    mette le X come "cuscinetto"
    Parametri:
        -char str[] : input
        -char codice[] : ouput
        -int len : input
        -int start : input
*/
void insertCons(char str[],char codice[],int len,int start,bool nome = false)
{
    int nItera = 0,i = 0,letTrov = 0;
    bool skip = false;
    toUpStr(str);

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
                if( (str[i]>='A'&&str[i]<='Z') && !isVocale(str[i]) )
                {
                    if(letTrov == 1 && nome == true && skip == false)
                    {
                        int trov = 0;

                        for(int j = i+1;j<strlen(str) && trov < 2;j++)
                            if( (str[j]>='A'&&str[j]<='Z') && !isVocale(str[j]) )
                                trov++;

                        if(trov >= 2)
                            skip = true;
                    }
                    else
                        skip = false;

                    if(skip == false)
                    {
                        codice[start+letTrov] = str[i];
                        letTrov++;
                    }
                }
                break;
            }
            case 1:
            {
                if( (str[i]>='A'&&str[i]<='Z') && isVocale(str[i]) )
                {
                    codice[start+letTrov] = str[i];
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
    codice[start+letTrov] = 0;
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
bool checkCognome(char cognome[])
{
    int checked = 0;
	while(
           cognome[checked] &&
           ( (toupper(cognome[checked])>='A' && toupper(cognome[checked])<='Z') || cognome[checked] == ' ' || (cognome[checked] == '\'' && checked !=0) || AcenToChar(cognome,checked) )
         )
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
        printf("metti il tuo nome : ");
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
    insertCons(nome,codice,3,3,true);
    printf("%s",codice);

    return 0;
}
