#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>

#define MAXN 10000000

char forward[MAXN + 1], backward[MAXN + 1], observation[MAXN + 1];

int solve(int N, char forward[], char backward[], int M, char observation[])
{
  int ans=0;
  bool err=false;
  for(int i=0;i<M;i++)
  {
    if(observation[i]=='<')
      observation[i]='^';
    else
      observation[i]='v';
  }
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(observation[j]!=forward[i+j])
      {
        err=true;
        break;
      }

    }
    if(err==false)
      ans++;
    err=false;
  }
  for(int i=0;i<M;i++)
    if(observation[i]=='^')
      observation[i]='v';
    else
      observation[i]='^';
  for(int i=N-1;i!=-1;i--)
  {
    for(int j=M-1;j!=-1;j--)
      if(observation[j]!=backward[i-j])
      {
        err=true;
        break;
      }
    if(err==false)
      ans++;
    else
      err=false;
  }

  return ans;
}

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    assert(1 == fscanf(fr, "%s", forward));
    assert(1 == fscanf(fr, "%s", backward));
    assert(1 == fscanf(fr, "%d", &M));
    assert(1 == fscanf(fr, "%s", observation));

    fprintf(fw, "%d\n", solve(N, forward, backward, M, observation));
    fclose(fr);
    fclose(fw);
    return 0;
}

