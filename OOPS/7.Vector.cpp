#include<iostream>
using namespace std;

class Vector
{
public:
    int *a;
    int cs;     // kitne kam ke elements array m hai
    int capc;  // kitne elements array m add kr skte hai 
    
    Vector(int s=1)    // Constructor
    {
        capc = s;
        cs = 0;
        a = new int [capc];
    }

    void push_back(int d){
    
        if(cs == capc)
        {
            int *new_a = new int [2*capc];
            int new_capc = 2*capc;

            for(int i=0; i<capc;i++)
            {
                new_a[i] = a[i];
            }
            delete []a;
            a = new_a;
            capc = new_capc;
        }
        a[cs++] = d;
        
    }
    void pop_back(){
        if(cs>0){cs--;}
    }
    int size(){return cs;}
    int capacity(){return capc;}
    int operator[](int i)
    {
        return a[i];
    }
};

int main()
{
    Vector v;
    for(int i=0; i<5; i++)
    {
        v.push_back(i+1);
        cout<<v.size()<<" "<<v.capacity()<<endl;
    }
    for(int i=0; i<5; i++)
    {
        cout<<v[i];
    }
}