#include<iostream>
using namespace std;

int multiply(int a, int b)
{
    if(b==0)
    {
        return 0;
    }

    int k = multiply(a, b-1) + a;
    return k;
}
int main()
{
    cout<<multiply(3, 4);
}