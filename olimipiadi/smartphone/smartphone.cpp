#include <assert.h>
#include <stdio.h>
#include <iostream>

using namespace std;
#define MAXN 1000000

// input data
int N;
int P[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(1 == scanf("%d", &N));
  for (int i = 0; i < N; i++) assert(1 == scanf("%d", &P[i]));

  // insert your code here
  long long res = 42LL;
  int c_max=P[0];
  res=P[0];
  for(int i=0;i<N;i++)
  {
    if(c_max<P[i])
    {
      c_max=P[i];
      res+=P[i];
    }

  }

  printf("%lld\n", res);  // print the result
  return 0;
}