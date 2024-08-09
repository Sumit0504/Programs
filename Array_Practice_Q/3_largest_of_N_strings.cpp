#include<iostream>
#include<cstring>
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
}

int main()
{
    char ch[100], largest[100];
    int n, len_largest=0, len=0;
    cin>>n;
    
    cin.ignore();//it is used after recieving a number becoz ch will pick it up as string

    for(int i=0; i<n; ++i)
    {
        cin.getline(ch,100);

         len = strlen(ch);

        if(len > len_largest)
        {
            str_copy(largest,ch);
            len_largest= len;
        }
    }
    cout<<largest;
}