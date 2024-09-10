#include<iostream>
using namespace std;

void bubble_sort(int *a, int n, int i)
{
    if(i == n-1)
    {
        return ;
    }
    
    for(int j=0; j<n-i-1; j++)
    {
        if(a[j]> a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    bubble_sort(a,n,i+1);
}

int main()
{
    int a[]={8, 2, 5, 1, 3, 4};
    int n = sizeof(a)/sizeof(int);

    bubble_sort(a, n, 0);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
    
}