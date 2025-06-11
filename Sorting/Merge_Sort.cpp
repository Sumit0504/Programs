//Merge Sort 
// Time complexity = O(nlog(n))
// Space complexity = O(n) // jo merge m extra temp create kiya hai uski sapce ko count krte hai 
// T(n) = T(n/2) + T(n/2) + n

#include<iostream>
#include<vector>
using namespace std;
void merge(int *a, int s, int mid, int e)
{
    vector<int> temp;
    int i = s, j = mid+1;

    while(i<=mid && j<=e)
    {
        if(a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(j<=e)
    {
        temp.push_back(a[j]);
        j++;
    }

    for(int id=0; id<temp.size(); id++)
    {
        a[id+s] = temp[id];
    }
}
void merge_sort(int *a, int s, int e)
{
    if(s==e)
    {
        return;
    }
    int mid = s + ((e-s)/2);

    merge_sort(a, s, mid); // left side array
    merge_sort(a, mid+1, e); // right side array 

    merge(a, s, mid, e);
}
int main()
{
    int n = 5; 
    int *a = new int [n];
    cout<<"enter: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}