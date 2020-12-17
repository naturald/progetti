#include <stdio.h>
#include <assert.h>
#include <iostream>

// input data
int N, L, U;

int main() 
{
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &L, &U));

    int ans, raw_gru, nr, ng;
    if(N<L)
    {
      printf("-1\n");
      return 0;
    }
	else
	{
		if(N<U)
		{
			printf("1\n");
      		return 0;
		}
    	raw_gru=N/U;
		nr=N-(U*raw_gru);
		if(nr==0)
		{
			printf("%d",raw_gru);
      		return 0;
		}
    	if(nr>=L)
    	{
			raw_gru++;
		}
		else
		{	
		    ng=U;
    		while(nr<L)
    		{
    				nr+=raw_gru;
    				if(nr>=L) 
					{
						raw_gru++;
					}
    			ng--;
    			if(ng<L) 
    			{
				    printf("-1\n");
				    return 0;
				}
			}
		}
		printf("%d\n", raw_gru);
	}
    
    

    // print the result
    return 0;
}
