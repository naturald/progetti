#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM_CAMPO 10
#define N_NAVI 3
const int NaviLen[N_NAVI] = {4,3,3};//,2,2,2,1,1,1,1};

void pulisciCapo(int campo[][DIM_CAMPO]);
void posNavi(int campo[][DIM_CAMPO]);
void stampCampo(int campo[][DIM_CAMPO]);

int main()
{
    int campo[DIM_CAMPO][DIM_CAMPO],scelta[2],turniUtili[2];

    pulisciCapo(campo);

    posNavi(campo);

    stampCampo(campo);
}

/*
    prede una matrice e la "pulisce"
    mettendo a zero ogni casela
    Parametri:
        -int campo[][]: output
*/
void pulisciCapo(int campo[][DIM_CAMPO])
{
    for(int i = 0;i<DIM_CAMPO;i++)
        for(int j = 0;j<DIM_CAMPO;j++)
            campo[i][j] = 0;
}


void stampCampo(int campo[][DIM_CAMPO])
{
    for(int i = 0;i<DIM_CAMPO;i++)
    {
        for(int j = 0;j<DIM_CAMPO;j++)
            printf(" %d ",campo[i][j]);
        printf("\n");
    }
}

/*
    dato una matrice mette tutte le navi
    Parametri:
        -int campo[][]: output
*/
void posNavi(int campo[][DIM_CAMPO])
{
    int pos[2],dire = 0;
    bool direGiusta = true;
    srand(time(0));
    for(int i = 0;i<N_NAVI;i++)
    {
        do
        {
            pos[0] = rand()%DIM_CAMPO;
            pos[1] = rand()%DIM_CAMPO;
        }
        while(campo[pos[0]][pos[1]] != 0);

        dire = 0;

        do
        {
            switch(dire)
            {
                case 0:
                    if(pos[1]-(NaviLen[i]-1) >= 0)
                    {
                        printf("%d\n",i);
                        direGiusta = true;
                    }
                    else
                    {
                        printf("dire 0 %d\n",dire);
                        getchar();
                        direGiusta = false;
                    }
                break;
                case 1:
                    if(pos[1]+(NaviLen[i]-1) < DIM_CAMPO)
                        direGiusta = true;
                    else
                    {
                        printf("dire 1\n");
                        getchar();
                        direGiusta = false;
                    }
                break;
                case 2:
                    if(pos[0]-(NaviLen[i]-1) >= 0)
                        direGiusta = true;
                    else
                    {
                        printf("dire 2\n");
                        getchar();
                        direGiusta = false;
                    }
                break;
                case 3:
                    if((pos[0]+(NaviLen[i]-1)) < DIM_CAMPO)
                        direGiusta = true;
                    else
                    {
                        printf("dire 3\n");
                        getchar();
                        direGiusta = false;
                    }
                break;
            }

            if(!direGiusta)
                dire++;
        }
        while(direGiusta == false && dire<4);

        if(!direGiusta)
            printf("caio");

        for(int j = 0;j<NaviLen[i];j++)
            switch(dire)
            {
                case 0:
                    campo[pos[0]-j][pos[1]] = NaviLen[i];
                break;
                case 1:
                    campo[pos[0]+j][pos[1]] = NaviLen[i];
                break;
                case 2:
                    campo[pos[0]][pos[1]-j] = NaviLen[i];
                break;
                case 3:
                    campo[pos[0]][pos[1]+j] = NaviLen[i];
                break;
            }

    }
}
