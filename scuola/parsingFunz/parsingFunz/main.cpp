#include <iostream>
const char opera[17] = {'+','-','/','*'};
const char number[13] = {'0','1','2','3','4','5','6','7','8','9','.',',','x'};

using namespace std;

float calcolo(int num1,char sign,int num2)
{
    float ris;
    switch(sign)
    {
        case '+':
            ris = num1 + num2;
        break;
        case '-':
            ris = num1 - num2;
        break;
        case '/':
            ris = num1 / num2;
        break;
        case '*':
            ris = num1 * num2;
        break;
    }
    return ris;
}

bool isOpera(char c)
{
    for(int i = 0;i<sizeof(opera);i++)
        if(opera[i] == c)
            return true;
    return false;
}

bool isNum(char c)
{
    for(int i = 0;i<sizeof(number);i++)
        if(number[i] == c)
            return true;
    return false;
}

bool isAllow(char c)
{
    if(c == ' ' || c == '(' || c == ')')
        return true;
    else if(isOpera(c))
        return true;
    else if (isNum(c))
        return true;

    return false;
}


float parsFunz(string funz,int * skip = 0)
{
    int numBound[2] = {0,0};// inizio num e len
    float num[2] = {0,0};
    int operazione,nNum = 0,ris;
    for(int i = 0;i<funz.length() && isAllow(funz[i]);i++)
    {
        if(isNum(funz[i]) && i != funz.length()-1)
        {
            if(!isNum(funz[i-1]))
            {
                numBound[0] = i;
                numBound[1] = 1;
            }
            else
                numBound[1]++;
        }
        else
        {
            if (isOpera(funz[i]))
                operazione = i;

            if(funz[i] == ')')
            {
                if(isNum(funz[i-1]))
                {

                    numBound[0] = i-1;
                    numBound[1] = 1;

                    string str = funz.substr(numBound[0],numBound[1]);

                    char * substring = &(funz.substr(numBound[0],numBound[1])[0]);

                    if(substring[0] == 'x')
                        num[nNum] = 4;
                    else
                        num[nNum] = atof(substring);
                    cout<<"    "<<num[0]<<funz[operazione]<<num[1]<<" = "<<num[0]+num[1];
                    if(nNum == 1)
                    {
                        ris = calcolo(num[0],funz[operazione],num[1]);
                        num[0] = ris;
                    }
                    else
                        nNum++;
                }


                int pos = *skip;
                //cout<<" "<<i;
                *skip = pos + i+1;
                return ris;


            }
            if(funz[i] == '(')
            {
                num[nNum] =  parsFunz(funz.substr(i+1),&i);
                cout<<"    "<<num[0]<<funz[operazione]<<num[1]<<" = "<<num[0]+num[1];
                if(nNum == 1)
                {
                    ris = calcolo(num[0],funz[operazione],num[1]);
                    num[0] = ris;
                }
                else
                    nNum++;
            }
            else if(isNum(funz[i-1]) || (isNum(funz[i]) && i == funz.length()-1))
            {
                if(isNum(funz[i]) && i == funz.length()-1)
                {
                    numBound[0] = i;
                    numBound[1] = 1;
                }
                string str = funz.substr(numBound[0],numBound[1]);


                char * substring = &(funz.substr(numBound[0],numBound[1])[0]);

                if(substring[0] == 'x')
                    num[nNum] = 4;
                else
                    num[nNum] = atof(substring);

                 cout<<"    "<<num[0]<<funz[operazione]<<num[1]<<" = "<<num[0]+num[1];
                if(nNum == 1)
                {
                    ris = calcolo(num[0],funz[operazione],num[1]);
                    num[0] = ris;
                }
                else
                    nNum++;

            }
        }

    }
    return ris;
}

int main()
{
    int ris = parsFunz(" 2+ (5+4+(5+4) ) + 2");
    cout<<endl<<ris;

    return 0;
}
