#include<iostream>
using namespace std;
void rev_string(char *a,int sz)
{
    int s=0;
    int e =sz-1;
    while(s < e)
    {
        swap(a[s++],a[e--]);
    }
    cout<<"Reversed String: "<<a;
}
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    int len = strlen(a);
    cout<<"String before Reversing: "<<a<<endl;
    rev_string(a,len);
}