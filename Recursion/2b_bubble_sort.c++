#include<iostream>
using namespace std;

void bubble_sort(int *a, int n, int i,int j)
{
    if(i == n-1)
    {
        return ;
    }
    
    if(j<n-i-1)
    {
        if(a[j]> a[j+1])
        {
            swap(a[j],a[j+1]);
        }
        bubble_sort(a,n,i,j+1);
    }
    bubble_sort(a,n,i+1,0);
}
int main()
{
    int a[]={8, 2, 5, 1, 3, 4};
    int n = sizeof(a)/sizeof(int);

    bubble_sort(a, n, 0,0);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
    
}