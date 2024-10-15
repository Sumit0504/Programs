#include<iostream>
using namespace std;
class Queue
{
    int* a;
    int n;
    int cs;
    int f, e;
public:
    Queue(int s)
    {
        a = new int[s];
        n = s;
        cs=0;
        f=0;
        e=n-1;
    }
    void push(int d)
    {
        if(cs<n)
        {
            e = (e+1)%n;
            a[e] = d;
            cs++;
        }
        else{
            cout<<endl<<"overflow"<<endl;
        }
    }
    void pop()
    {
        if(cs>0)
        {
            f = (f+1)%n;
            cs--;
        }
        else{
            cout<<endl<<"underflow"<<endl;
        }
    }
    int front()
    {
        return a[f];
    }
    bool empty()
    {
        return cs==0;
    }
    int size()
    {
        return cs;
    }
};
int main()
{
    Queue q(4);

	q.push(6);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty()) {
		cout << q.front() << " ";

		q.pop();
	}
    
	cout << endl;
    return 0;
}