/* Problem Statement: Given a sorted array of N integers and 
an integer x, write a program to find the lower bound of x.*/

#include <iostream>
using namespace std;

int binarys(int *a, int s, int e, int k)
{
    if(s>e) return s;
    
    int mid = s + ((e-s)/2);
    
    
    if(k <= a[mid]) return binarys(a, s , mid-1, k);
    else return binarys(a, mid+1, e, k);
    
}
int main() {
    int a[] = {3, 5, 8, 15, 19};
    int n = sizeof(a)/ sizeof(int);
    
    cout<<binarys(a, 0, n-1,9);
    return 0;
}