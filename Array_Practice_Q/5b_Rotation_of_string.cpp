#include<iostream>
using namespace std;

void rotate(char *ar,int k)
{
    int len = strlen(ar);
    int i = len -1;
    while(i>=0)
    {
        ar[i+k]=ar[i];
        i--;
    }
    int j=0;
    while(j<k)
    {
        ar[j]=ar[len];
        j++;
        len++;
    }
    ar[len-k]='\0';
}

int main()
{
    char a[100];
    int k;
    cin>>k;
    cin.ignore();
    cin.getline(a,100);
    rotate(a,k);
    
    cout<<a;
}