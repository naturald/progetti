#include <iostream>

using namespace std;

void swap(int arr[],int index,int index2)
{
    int tmp = arr[index];
    arr[index] = arr[index2];
    arr[index2] = tmp;
}

int main()
{
    int arr[5] = {6,2,1,8,4};
    int min;
    for(int i = 0;i<5;i++)
    {
        min = i;
        for(int j = i;j<5;j++)
            if(arr[j]<arr[min])
                min = j;
        swap(arr[i],arr[min]);
    }
    for(int i = 0;i<5;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }

}
