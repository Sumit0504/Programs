#include<iostream>
using namespace std;
///////////////Blue print///////////////
class Car
{
public:
    // data menmbers
    char name[10];
    int modle;
    int price;
    int seats;

    //Member funcion
    void print()
    {
        cout<<" Name   :"<<name<<endl;
        cout<<" Modle  :"<<modle<<endl;
        cout<<" Price  :"<<price<<endl;
        cout<<" Seats  :"<<seats<<endl;
    }
};
///////////////Blue print///////////////
int main()
{
    Car A;  //A is object of Car
            // to use the variables of A we use dot(.) operator 
    strcpy(A.name,"AUDI");
    A.modle = 2020;
    A.price = 100000;
    A.seats = 5;
    cout<<"A Name   :"<<A.name<<endl;
    cout<<"A Modle  :"<<A.modle<<endl;
    cout<<"A Price  :"<<A.price<<endl;
    cout<<"A Seats  :"<<A.seats<<endl;
    //or
    A.print();

}