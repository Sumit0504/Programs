#include <iostream>
using namespace std;

int main() {
    
    int a[] = {1, 4, 3, -10, 2, 6, 8, -4, 5, 7 };
    int n = sizeof(a)/sizeof(int);
    int s= 0, prev_s=0;
    for(int i=0; i<n; i++)
    {
        s= a[i];
        for(int j=i+1; j<n; j++)
        {
            s = s+a[j];
            if(s > prev_s)
            {
                prev_s = s;
            }
        }
    }
    cout<<prev_s;
    
    return 0;
}