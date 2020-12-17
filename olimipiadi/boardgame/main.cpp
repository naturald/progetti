/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// input data
int N, L, U;

int main() 
{
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &L, &U));

    int gru_inc,ans;

    if(N<L)
    {
      ans=-1;
      goto fine;
    }
    ans=N/U;
    gru_inc=N%U;
    if(gru_inc!=0&&L==U)
    {
      ans=-1;
      goto fine;
    }
    if(gru_inc!=0)
    {
	    if(gru_inc<L)
	    {
		  int da_togli=(U-L)*ans;
	      for(int i=0;i<da_togli;i++)
	      {
	        if(gru_inc==L)
	        {
	          ans++;
	          break;
	        }
	        gru_inc++;
	      }
	      if(gru_inc<L)
	      {
	        ans=-1;
	      }
	    }
	    else
	    	ans++;
	}
	
	fine:
    printf("%d\n",ans); // print the result
    return 0;
} 
