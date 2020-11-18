/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 10000

// input data
int N, i;
int T[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    int t_min=T[0],ans=0;
    for(i=1;i<N;i++)
    {
      if(T[i]+i<t_min)
      {
        t_min=T[i]+i;
        ans++;
      }
    }

    printf("%d %d \n", t_min,ans); // print the result
    return 0;
}
