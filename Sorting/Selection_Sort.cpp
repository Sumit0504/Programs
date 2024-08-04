//always select a minimum element by traversing
#include<iostream>
using namespace std;

void print(int *a, int n )
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

void sort(int *a, int sz)
{
    
    for(int i=0 ;i<sz-1; i++)
    {
        int min = a[i];
        int min_indx = i;
        for(int j=i+1; j<sz; j++)
        {
            if(min>a[j])
            {
                min = a[j];
                min_indx = j;
            }
        }

        swap(a[i], a[min_indx]);
    }
}

void swap(int &a ,int &b)
{
    int temp = a;
    a =b;
    b = temp;
}
int main()
{
    int a[] = {9, 4, 1, 6, 7};
    int sz = sizeof(a)/sizeof(int);

    sort(a, sz);
    print(a, sz);
}