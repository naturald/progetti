#include <stdio.h>
#include <math.h>

int printB(int bina,int cifra)
{
	if(bina & (int)pow(2,(float)cifra))
		return 1;
	else
		return 0;
}

int getBina(int num_bina[],float deci)
{
	int base = 2,i = 0,part_int,j,cifr_dec;
	float n,part_dec;
    part_dec=deci;
    part_int= (int) deci;
    part_dec-=part_int;
    int nDigBin = 0;
    for(int n = part_int;n != 0;n/=base)
    {
        nDigBin++;
    }

    i =  nDigBin-1;
    while(part_int!=0)
    {
        num_bina[i]=part_int%base;
        part_int/=base;
        i--;
    }
    if(nDigBin == 0)
        i =  nDigBin+1;
    else
        i =  nDigBin;

    part_int = (int) deci;
    for(j=0;j<(40-i);j++)
    {
        if(part_dec==0.0)
            break;
        part_dec*=base;
        num_bina[i+j]=(int) part_dec;
        part_dec-=(int) part_dec;
    }
    return nDigBin-1;
}

int main()
{
    float deci;
    int ieeeFormat[32],num_bina[40],offset = 0;
    for(int i = 0;i<40;i++)
    {
        if(i<32)
            ieeeFormat[i] = 0;

        num_bina[i] = 0;
    }
    printf("metti numero reale in base 10 : ");
    scanf("%f",&deci);
    if(deci<0)
    {
        ieeeFormat[0] = 1;
        deci*=-1;
    }
    else
        ieeeFormat[0] = 0;

    int espo = getBina(num_bina,deci);
    if(espo != -1)
    {
        espo = espo + 127;
    }
    else
    {
        espo = 1;
        offset++;
        int x = 1;
        while(num_bina[x] != 1)
        {
            espo++;
            offset++;
            x++;
        }
        espo = (espo*-1) + 127;
    }
    for(int i = 0;i<32;i++)
    {
        if(i>0 && i<9)
        {
            ieeeFormat[i] = printB(espo,8-i);
        }
        if(i>8)
        {
            ieeeFormat[i] = num_bina[(i-8)+offset];
        }

        printf("%d ",ieeeFormat[i]);
        if(i == 0 || i == 8)
            printf(" ");
    }
    return 0;
}

//0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 1 0
//0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 1 0
