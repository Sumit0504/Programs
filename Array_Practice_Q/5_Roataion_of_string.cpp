#include<iostream>
using namespace std;
void rotate(char *ar)
{
    int len = strlen(ar);
    int a= ar[len-1];
    int i=len -2;
    while(i>=0)
    {
        ar[i+1]=ar[i];
        i--;
    }
    i++;
    ar[i]=a;
    cout<<ar<<endl;
}
int main()
{
    char ch[10]="Sumit";
    int k;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        rotate(ch);
    }
    
}