#include<iostream>
using namespace std;

class node
{public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*- Creation Functions -*-*-*-*-*-*-*-*-*-*-*-*-*-*

int lengthLL(node* &head, node* &tail)
{
    int count =0;
    node* temp = head;
    while(temp!=tail)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Insert_at_end(node* &head, node* &tail, int d)
{
    if(head == NULL)
    {
        // create new node 
        node* n = new node(d);
        head = n;
        tail = n;
    }
    else{
        node* n = new node(d);
        tail->next = n;
        tail = n;
    }
}
void Insert_at_start(node* &head, node* &tail, int d)
{
    node*n = new node(d);
    n->next = head;
    head = n;
}

void print(node* head, node* tail)
{
    node* temp = head;
    while(temp!= tail)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<temp->data;
}
void Insert_at_mid(node* &head, node* &tail, int d , int pos)
{
    if(pos>=lengthLL(head,tail))
    {
        Insert_at_end(head,tail,d);
    }
    else if(pos==0)
    {
        Insert_at_start(head,tail,d);
    }
    else{
        node* n = new node(d);
    node* temp = head;
    for(int i=1; i<pos; i++)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    }
}

void ReverseLL(node* &head, node* &tail)
{
    node* c = head;
    node* p = NULL;
    node* n = NULL;
    while(c!=NULL)
    {
        n = c-> next;
        c ->next = p;
        p = c;
        c = n;
    }
    swap(head, tail);
}
int main()
{
    node* h = NULL;
    node* t = NULL;
    Insert_at_end(h ,t , 3);
    Insert_at_end(h ,t , 4);
    Insert_at_end(h ,t , 6);
    Insert_at_end(h ,t , 7);
    print(h,t);
    Insert_at_start(h,t, 1);
    cout<<endl<<"Inserting 1 at start:"<<endl;
    print(h,t);
    Insert_at_mid(h,t, 5, 3);
    cout<<endl<<"Inserting 5 at mid:"<<endl;
    print(h,t);
    cout<<endl<<lengthLL(h,t);

    ReverseLL(h, t);
    cout<<endl;
    print(h,t);
}

    