#include<iostream>
using namespace std;

int main()
{
    int ar[] = {5, 6, 2, 3 ,8};
    int n = sizeof(ar)/sizeof(int);

    int i, j, key;

    for(i=1; i<n; i++)
    {
        key = ar[i];
        for(j=i-1; j>=0; j++)
        {
            if(ar[j] > key)
            {
                ar[j-1] = ar[j];
                ar[j] = key;
            }
        }
    }
    cout<<"After Insertion Sort: ";

    for(i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
}