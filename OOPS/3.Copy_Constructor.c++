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

    //1. Default Constructor
    Car(){ // has no data type coz it don't return anything
        cout<<"Insie default Constructor"<<endl;
    }

    // 2.Parameterized Constructor
    Car(char *n, int m, int p, int s){
        cout<<"Inside Parameterized constructor"<<endl;
        strcpy(name,n);
        modle = m;
        price = p;
        seats = s;
    }

    // 3. Copy Constructor
    Car(Car &X)
    {
        cout<<endl<<"Inside copy constructor"<<endl;
        strcpy(name,X.name);
        modle = X.modle;
        price = X.price;
        seats = X.seats;
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

    // cout<<"A Name   :"<<A.name<<endl;
    // cout<<"A Modle  :"<<A.modle<<endl;
    // cout<<"A Price  :"<<A.price<<endl;
    // cout<<"A Seats  :"<<A.seats<<endl;
    //or
    A.print();
    Car B("Maruti", 2015, 80000, 4);
    B.print();


    //calling a copy constructor
    Car D = A; //or Car D(A) jo object create ho vo constructor ko call krega and A is passed as an argument
    D.print();
    Car E(D);
    D.print();
}