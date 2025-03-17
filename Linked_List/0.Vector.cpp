#include<iostream>
using namespace std;

class Vector
{
public:
    int *a;
    int cs; // its the size of array (no. of elements present in an array)
    int ms; // it's capacity( maximum elements that we add into an array)

    Vector(int s=1)
    {
        ms = s;
        cs = 0;
        a = new int [ms];
    }
    void push_back(int d)
    {
        int* na = NULL;
        if(cs == ms)
        {
            int * na = new int [2*ms]; // na is new a
            int nms = 2*ms; // new max size/ capacity
            for(int i=0 ;i<ms; i++)
            {
                na[i] = a[i];
            }
            delete []a;
            a = na;
            ms = nms;
        }

        a[cs++] = d;
    }
    void pop_back()
    {
        if(cs > 0) cs--;
    }
    int size() {return cs;}

    int capacity() {return ms;}

    int operator[] (int i)
    {
        return a[i];
    }
};

int main()
{
    Vector v;


    for(int i=0; i<5; i++)
    {
        v.push_back((i+1)*10);
        cout<<v[i]<<", size = "<<v.size()<<", capacity = "<<v.capacity()<<endl;
    }
}