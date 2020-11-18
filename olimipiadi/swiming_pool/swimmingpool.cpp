/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));

    // insert your code here
    int pos_all, dis_lon=0, p,  s=0; 
    float m, dis_pos=1000001;
	for(i=0; i<N; i++)
	{
		s+=P[i];
	}
	 m=(float)s/i;
	 for(i=0; i<N; i++)
	{
		if(m-P[i]>=0)
			if(dis_pos>m-P[i])
			{
				dis_pos=m-P[i];
				p=P[i];
			}
		else
		{
			if(dis_pos>=P[i]-m)
			{
				dis_pos=P[i]-m;
				p=P[i];
			}
		}
	}
	 for(i=0; i<N; i++)
	{
    if(P[i]-p>0)
    {
      if(dis_lon<P[i]-p)
      {
        dis_lon=P[i]-p;
        p=P[i];
      }
    }
    else
    {  
      if(dis_lon<p-P[i])
      {
        dis_lon=P[i]-p;
        p=P[i];
      }
    }
	}

    printf("%d\n", dis_lon); // print the result
    return 0;
}
