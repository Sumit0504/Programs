// Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which inverses the array. Print the values of inverted array
// Input Format
// Enter a number N and take N more inputs
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Invese(int *a, int sz)
{
    int s =0;
    int e =sz-1;
    while(s<e)
    {
        swap(a[s++],a[e--]);
    }
}

void print(int *a, int sz)
{
    for(int i=0; i<sz; i++)
    {
        cout<< a[i]<<" ";
    }
}
int main()
{
    int a[]={0,1,5,3,2,4};
    int n = sizeof(a)/sizeof(int);
    Invese(a,n);
    print(a,n);
}