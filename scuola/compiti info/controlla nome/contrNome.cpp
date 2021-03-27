/*
    Marco Schiavello 3^CI

    Leggere il nome di una persona ed effettuare il controllo formale (deve essere composto solo da lettere dell'alfabeto oppure da uno spazio).
	Per agevolare il controllo potete trasformare il nome in maiuscolo. Se il nome è formalmente sbagliato bisogna chiederlo nuovamente in input.

	Leggere il cognome di una persona ed effettuare il controllo formale (deve essere composto solo da lettere
	dell'alfabeto oppure da uno spazio oppure da un apostrofo).
	Per agevolare il controllo potete trasformare il nome in maiuscolo. Se il nome è formalmente sbagliato bisogna chiederlo nuovamente in input.
	Per controllare l'apostrofo dovete confrontare cognome [i]!= '\''.
	Essendo l'apice un carattere speciale per essere riconosciuto come carattere deve essere preceduto dal backslash.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 20


/*
	scorre l'array finchè finche non trova un valore non adeguato es numeri
	e ritorna il numero di charatteri validi fino prima del primo sbagliato
	in casd non ci siano errori ritorna la lunghezza del'array
	Parametri:
		- char str[] = input
*/
int checkCognome(char str[])
{
    int checked = 0;
	while( str[checked] && ( (toupper(str[checked])>='A' && toupper(str[checked])<='Z') || str[checked] == ' ' || str[checked] == '\'') )
		checked++;

    if(checked < strlen(str))
    {
        printf("non e un cognome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

int checkNome(char str[])
{
    int checked = 0;
	while( str[checked] && ( (toupper(str[checked])>='A' && toupper(str[checked])<='Z')))
		checked++;

    if(checked < strlen(str))
    {
        printf("non e un nome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

int main()
{
    char nome[DIM],cognome[DIM];
    int i = 0;
    bool err = false;
    do
    {
		printf("immetti nome: ");
		gets(nome);
        err = checkNome(nome);
        printf("\n\n\n");
    }
    while(err);

    do
    {
		printf("immetti cognome: ");
		gets(cognome);
        err = checkCognome(cognome);
        printf("\n");
    }
    while(err);

    printf("giusto\n");
}
