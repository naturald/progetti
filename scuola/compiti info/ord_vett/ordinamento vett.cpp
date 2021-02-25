#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void swap(int vett[],int a,int b)
{
	int tmp = vett[a];
	vett[a] = vett[b];
	vett[b] = tmp;
}

int main ()
{
	int vett[DIM] = {1,5,8,3,9};
	int i,j;
	for(i = 0;i<DIM-1;i++)
		for(j = i+1;j<DIM;j++)
			if(vett[i]>vett[j])
				swap(vett,i,j);
	
}
