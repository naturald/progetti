#include <iostream>

using namespace std;

int main()
{
  //---input------
  int n,path_fix,time_c=0;
  cin>>n;
  int t[n],salva=n-1;
  for(int i=0;i<n;i++)
  {
    cin>>t[i];
    if(t[i]==n-1)
    {
      salva=i;//pero questo guardalo
    }
  }
  //-------------
  for(int i=n-1;i!=-1;i--)
  {
    if(t[i]==salva)
    {
      salva=i;
      if(salva==0)
      {
        cout<<salva;
        return 0;
      }
    }
  }
  int i=0;
  while(i<n-1&&i!=salva)
    if(t[i]>i)
      i=t[i];
    else
    {
      i++;
      time_c++;
    }

  cout<<"\n"<<time_c;

}
