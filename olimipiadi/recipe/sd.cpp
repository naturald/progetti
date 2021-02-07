/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// input data
int N, M;
vector<vector<double> > P;
vector<double> R;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> M;
    P.resize(N);
    R.resize(1000000);
    for (int i=0; i<N; i++)
        P[i].resize(M);
    for (int j=0; j<M; j++)
        for (int i=0; i<N; i++)
            cin >> P[i][j];    
    
    //Somma
    double m;
    int s, i , j;
    for(i=0; i<M; i++){
      s=0;
      for( j=0; j<N; j++)
      {
        s = s + P[j][i];
      }
     
      if(s!=1000000)
      {
        m=(float)1000000/s;
        
        //printf("m e uguale a %f ", m);
        for(j=0; j<N; j++)
        {
          P[j][i]=P[j][i]*m;
        }
      }
    }
    
    //Media
    for(i=0; i<N; i++)
      R[i] = 0;
    
    for(i=0; i<N; i++){
      
      for(j=0; j<M; j++){
        R[i] += P[i][j]; 
        //cout<<(int)R[i]<<" ";
      }
      R[i] /=(double) M;
      cout<<(int)R[i]<<" ";
    }
    cout << endl;
    return 0;
}

