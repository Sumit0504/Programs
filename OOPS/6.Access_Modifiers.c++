#include<iostream>
using namespace std;
///////////////Blue print///////////////
class Car
{
private:
int price;
public:
    // data menmbers
    char name[10];
    int modle;
    int seats;

    //Member funcion
    void print()
    {
        cout<<" Name   :"<<name<<endl;
        cout<<" Modle  :"<<modle<<endl;
        cout<<" Price  :"<<price<<endl;
        cout<<" Seats  :"<<seats<<endl;
    }

    void setprice(int &p)
    {
        price = p;
    }
    int getprice()
    {
        return price;
    }

    //1. Default Constructor
    Car(){ // has no data type coz it don't return anything
        cout<<"Insie default Constructor"<<endl;
    }

    // 2.Parameterized Constructor
    Car(char*n, int m, int p, int s){
        cout<<"Inside Parameterized constructor"<<endl;
        strcpy(name,n);
        modle = m;
        price = p;
        seats = s;
    }
};
///////////////Blue print///////////////
int main()
{
    Car A;  //A is object of Car
            // to use the variables of A we use dot(.) operator 
    strcpy(A.name,"AUDI");
    A.modle = 2020;
    
    A.seats = 5;

    // cout<<"A Name   :"<<A.name<<endl;
    // cout<<"A Modle  :"<<A.modle<<endl;
    // cout<<"A Price  :"<<A.price<<endl;
    // cout<<"A Seats  :"<<A.seats<<endl;
    //or
    A.print();
    Car B("Maruti", 2015, 80000, 4);
    B.print();

}