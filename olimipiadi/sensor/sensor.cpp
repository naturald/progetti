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
vector<vector<int>> P;
vector<double> R;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "rN", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> M;
    P.resize(N);
    R.resize(N);
    for (int i=0; i<N; i++)
        P[i].resize(M);
    for (int j=0; j<M; j++)
        for (int i=0; i<N; i++)
            cin >> P[i][j];

    R[0] = 42; // insert your code here
    
    double m;
    int s, i , j;
    for(i=0; i<N; i++){
      s=0;
      for( j=0; j<M; j++)
      {
        s = s + P[i][j];
      }
      if(s!=1000000)
      {
        m=1000000/s;
        printf("s e uguale a %d ", s);
        printf("m e uguale a %f ", m);
        for(j=0; j<M; j++)
        {
          P[i][j]=P[i][j]*m;
        }
      }
    }
  
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        printf(" %d ", P[i][j]);
      }
    }

    
    //for (int i=0; i<N; i++)
    //    cout << (int)R[i] << " "; // print the result
    cout << endl;
    return 0;
}
