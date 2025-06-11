// Quick sort

// Time complexity( Avg / practical) - O(nlog(n))
// Worst case - O(n^2) why?? when array already sorted - n + (n-1) + (n-2) + (n-3) + .....+ 1 = O(n^2)
// Space complexity - O(1) Why?? only stack memory of recursion is used


#include<iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int pvt = a[e];
    int i = s-1;
    for(int j=s; j<e; j++)
    {
        if(a[j] <= pvt) // to sort in ascending order but for descening(>=)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[e]);

    return i;
}
void quicksort(int *a, int s, int e)
{
    if(s>=e) return;

    int pvt_idx = partition(a, s, e); // This function take the pivot to its correct postion
    quicksort(a, s, pvt_idx-1); // left side of pivot
    quicksort(a, pvt_idx+1, e); // right side of pivot

}

void print(int *a, int n)
{
    cout<<"Array Sorted using Quick Sort"<< endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter size of array: "; cin>>n;
    int *a = new int[n];
    cout<<"Enter values in array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    quicksort(a, 0 ,n-1);
    print(a,n);
}