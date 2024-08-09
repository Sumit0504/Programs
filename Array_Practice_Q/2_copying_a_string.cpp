#include<iostream>
using namespace std;
void str_copy(char *a, char *b)
{
    int i=0;
    int len =strlen(b);
    while(i<=len)
    {
        a[i]=b[i];
        i++;
    }
    cout<<"after copying str2 in str1: "<<a;
}
int main()
{
    char x[100]= "Hello";
    char y[100]= "Hello, My name is Sumit!";
    cout<<"before copying str1 is: "<<x<<endl;
    str_copy(x,y);
}