#include <bits/stdc++.h>
#define RIGHE 3
#define COLONNE 3

using namespace std;

void rotateMatrix(vector<vector<int>> a)
{
    // Consider all squares one by one
     // Traverse each cycle
    for (int i = 0; i < COLONNE / 2; i++) {
        for (int j = i; j < COLONNE - i - 1; j++) {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[COLONNE - 1 - j][i];
            a[COLONNE - 1 - j][i] = a[COLONNE - 1 - i][COLONNE - 1 - j];
            a[COLONNE - 1 - i][COLONNE - 1 - j] = a[j][COLONNE - 1 - i];
            a[j][COLONNE - 1 - i] = temp;
        }
    }
}

void displayMatrix(vector<vector<int>> mat)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

// Complete the formingMagicSquare function below.
int main()
{
    int p[3][3] = {7, 6, 5,
7, 2, 8,
5, 3, 4};

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            s[i][j] = p[i][j] ;
        }
    }
    displayMatrix(s);

    int min = 99999;
    for(int x = 0;x<4;x++)
    {
        rotateMatrix(s);
        int c = COLONNE/2,r = 0;
        int c2 = COLONNE/2,r2 = RIGHE-1;

        int costo = 0,costo2 = 0;

        for(int i = 0;i<(RIGHE*COLONNE);i++)
        {
            if(r == -1)
                r = RIGHE-1;
            if(c == COLONNE)
                c = 0;

            if(r2 == RIGHE)
                r2 = 0;
            if(c2 == COLONNE)
                c2 = 0;

                cout<<costo<<" "<<costo2<<"\n\n";

            if(s[r][c] != i+1)
                costo += abs((i+1)-s[r][c]);

            if(s[r2][c2] != i+1)
                costo2 += abs((i+1)-s[r2][c2]);



            if((i+1)%3 != 0)
            {
                c = c+1;
                r = r-1;
            }
            else
                r = r+1;

            if((i+1)%3 != 0)
            {
                c2 = c2+1;
                r2 = r2+1;
            }
            else
                r2 = r2-1;
        }
        if(costo<min)
            min = costo;
        if(costo2<min)
            min = costo2;
        cout<<costo<<" "<<costo2<<"\n\n";
    }
    cout<<min;
    return 0;

}


/*
//marco schiavello 3^CI 05/11/2020
//programma per provare forme di algoritmi credo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <ctime>

#define RIGHE 9            //n. di righe
#define COLONNE 9          //n. di colonne
#define DIM 5          //dimensione massima di una stringa
#define NUM 5          // numero di stringhe


void stampaMat(int m[][COLONNE])
{
  int i,j;
   printf("stampa dei valori della matrice\n");

    for(i=0;i<RIGHE; i++)
    {
      printf("\n");
      for(j=0;j<COLONNE; j++)
        if(j == (COLONNE/2) || i == (COLONNE/2))
            printf(" 1 ");
        else
          printf("%2d ",m[i][j]);
    }
}

int main()
{

    char mat[RIGHE][COLONNE];// array (vettore) monodimensionale di 10 elementi interi
    for(int i = 0;i<RIGHE;i++)
    {
        scanf("%s",mat[i]);
        printf("%s",mat[i]);
    }
}
*/


