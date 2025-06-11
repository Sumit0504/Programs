#include <iostream>
using namespace std;

int binary_search(int *a, int s, int e, int k)
{
    if(s>e) return -1;
    
    int mid = s + ((e-s)/2);
    
    if(a[mid] == k) return mid;
    else if(k < a[mid]) return binary_search(a, s , mid-1, k);
    else return binary_search(a, mid+1, e, k);
    
}
int main() {
    int n;
    cout<<"Enter size of array:"; cin>>n;
    int *a = new int[n];
    cout<<"Enter values in array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int t;
    cout<<"Enter num you are searching for: "; cin>>t;
    cout<<binary_search(a, 0, n-1, t);
    return 0;
}