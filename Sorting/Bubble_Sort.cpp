#include<iostream>
using namespace std;

void BS(int *a, int sz)
{
    for(int i= 0; i<sz-1; i++)
    {
        for(int j = 0; j<sz-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void swap(int &a ,int &b)
{
    int temp = a;
    a =b;
    b = temp;
}
void print(int *a, int n )
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[] = {2, 4, 7, 1, 5};
    int sz = sizeof(a)/ sizeof(int);

    BS(a, sz);
    print(a, sz);

}