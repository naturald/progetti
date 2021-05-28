/*
    Marco Schiavello, Guido Panzieri, Alberto Benedicenti 3^CI
    A partire dall'esempio GestLibri.cpp, implementare un programma che permetta la gestione su file binario dell'oggetto prescelto dal gruppo, realizzando le seguenti funzionalità:
        - inserimento nuovo oggetto in fondo al file
        - modifica oggetto in base alla posizione
        - ricerca oggetto in base alla posizione
        - visualizzazione elenco oggetti  presenti nel file
        - cancellazione oggetto in base alla posizione ( plus per voto più alto)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20
#define OK 1
#define ERR 0
#define NOTHING_FOUND -1

typedef struct {
    char nome[STR_LEN];
    char email[STR_LEN];
    char pwd[STR_LEN];//password
} users;


void menu(int * scelta);
int addUser();
int searchUser();
int printUser();
int deleteUser();
bool thereAreUser(FILE * file);
int serchUserByName();

//___________Main__________
int main()
{
    int scelta;

    do
    {
        printf("\n\n\n");
        menu(&scelta);
        printf("\n");
        switch(scelta)
        {
            case 1:
                addUser();
            break;
            case 2:
                searchUser();
            break;
            case 3:
                printUser();
            break;
            case 4:
                deleteUser();
            break;
            case 5:
                serchUserByName();
            break;
        }

        //TODO: implementare condizione uscita
    }
    while(true);
}

/*
*   Procedura che stampa un menu e chiederà una scelta
*   che dovrà essere una voce del menu
*   Parametri:
*       - int * scelta: output: scelta utente
*/
void menu(int * scelta)
{
    do
    {
        printf("----------------------\n");
        printf("1) crea user\n");
        printf("2) cerca user\n");
        printf("3) stampa tutti user\n");
        printf("4) elimina user\n");
        printf("5) cerca per nome\n");//TODO: implemetarlo
        printf("----------------------\n");
        printf("scelta: ");
        scanf("%d",scelta);
        if(*scelta < 1 || *scelta > 5)
            printf("dato inserito non valido\n\n");

    }while(*scelta < 1 || *scelta > 5);
}


/*
*   Funzione che controlla che ci siano user nel file
*   se si ritorna true se no false
*   Parametri:
*       - FILE * file: input: file da controllare
*       - bool return: outoput: presenza o meno di utenti
*/
bool thereAreUser(FILE * file)
{
    users user;
    bool res;

    if(fread(&user,sizeof(users),1,file))
        res = true;
    else
    {
        printf("\nnon ci sono user\n");
        res = false;
    }

    fseek(file,0,SEEK_SET);
    return res;

}

/*
*   Funzione che carca nel file uno user dato un nome
*   Parametri:
*       - int return: outoput: codice di stato uscita funzione
*/
int serchUserByName()
{
    char nome[20];
    users user;
    FILE * f;
    int trov;
    
    f = fopen("data.bin","r");
    if(f == NULL)
        return ERR;

    if(!thereAreUser(f))   
        return NOTHING_FOUND;

    printf("inserisci il numero dell'user: ");
    scanf("%s",nome);

    printf("\n\n");
    for(int i = 0;fread(&user,sizeof(users),1,f);i++)
    {
        if(strcmp(user.nome,nome) == 0)
        {
            printf("user %d\n",i);
            printf("nome: %s\n",user.nome);
            printf("email: %s\n",user.email);
            printf("password: %s\n",user.pwd);
        }
    }

    fclose(f);
    return OK;
}

/*
*   Funzione che crea un utente forniti i campi
*   Parametri:
*       - int return: outoput: codice di stato uscita funzione
*/
int addUser()
{
    users user;

    printf("metti nome: ");
    scanf("%s",user.nome);
    printf("metti email: ");
    scanf("%s",user.email);
    printf("metti pwd: ");
    scanf("%s",user.pwd);


    FILE * f;

    f = fopen("data.bin","a");

    if(f == NULL)
        return ERR;

    fwrite(&user,sizeof(users),1,f);

    fclose(f);

    return OK;
}

/*
*   Funzione che cerca uno user fornito il suo numero nell'elenco
*   Parametri:
*       - int return: outoput: codice di stato uscita funzione
*/
int searchUser()
{
    int num;
    users user;
    FILE * f;
    
    f = fopen("data.bin","r");
    if(f == NULL)
        return ERR;

    if(!thereAreUser(f))   
        return NOTHING_FOUND;

    printf("inserisci il numero dell'user: ");
    scanf("%d",&num);

    printf("\n\n");
    
    fseek(f,sizeof(users) * (num-1),SEEK_SET);

    if(!fread(&user,sizeof(users),1,f))
        printf("user non esiste");
    else
    {
        printf("user %d\n",num);
        printf("nome: %s\n",user.nome);
        printf("email: %s\n",user.email);
        printf("password: %s\n",user.pwd);
    }

    fclose(f);
    return OK;
}

/*
*   Funzione che stampa tutti gli user presenti sul file
*   Parametri:
*       - int return: outoput: codice di stato uscita funzione
*/
int printUser()
{
    int i;
    users user;
    FILE * f;

    f = fopen("data.bin","r");

    if(f == NULL)
        return ERR;

    if(!thereAreUser(f))   
        return NOTHING_FOUND;

    for( i = 0;fread(&user,sizeof(users),1,f);i++)
    {
        printf("\n\nuser %d\n",i+1);
        printf("nome: %s\n",user.nome);
        printf("email: %s\n",user.email);
        printf("password: %s\n",user.pwd);
    }
    
    fclose(f);

    return OK;
}

/*
*   Funzione che cancella uno user dato il suo numero nella lista
*   Parametri:
*       - int return: outoput: codice di stato uscita funzione
*/
int deleteUser()
{
    FILE * f;
    FILE * tmpFile;
    users user;
    int numUser;

    if(printUser() == NOTHING_FOUND)
        return NOTHING_FOUND;

    printf("\n\ninserisci il numero dell'user da cancellare: ");
    scanf("%d",&numUser);
    
    f = fopen("data.bin","r");
    tmpFile = fopen("tmpData.bin","w");

    fseek(f,sizeof(numUser) * (numUser-1),SEEK_SET);

    if(!fread(&user,sizeof(users),1,f))
    {
        printf("user non esiste");
        return NOTHING_FOUND;
    }

    fseek(f,0,SEEK_SET);

    if(f == NULL || tmpFile == NULL)
        return ERR;

    for(int i = 0;fread(&user,sizeof(users),1,f);i++)
        if(i != numUser-1)
            fwrite(&user,sizeof(users),1,tmpFile);

    fclose(f);
    fclose(tmpFile);

    f = fopen("data.bin","w");
    tmpFile = fopen("tmpData.bin","r");

    if(f == NULL || tmpFile == NULL)
        return ERR;

    for(int i = 0;fread(&user,sizeof(users),1,tmpFile);i++)
        fwrite(&user,sizeof(users),1,f);
    
    fclose(f);
    fclose(tmpFile);
    
    return OK;
}