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
void break_cycle(node* head, node* f)
{
    node* s = head;
    node* fp = head;
    while(fp->next != f)
    {
        fp = fp->next;
    }
    while(f!=s)
    {
        fp = f;
        f = f->next;
        s= s->next;
    }
    fp->next = NULL;
}
bool is_cycle(node* head, node* tail)
{
    node* s = head, *f = head;
    while(f!= NULL && f->next!=NULL)
    {
        f = f->next->next;
        s = s->next;
        if(f==s)
        {
            break_cycle(head,f);
            return true;
        }
    }
    return false;
}
int main()
{
    node* h = NULL;
    node* t = NULL;
    Insert_at_end(h ,t , 3);
    Insert_at_end(h ,t , 4);
    Insert_at_end(h ,t , 6);
    Insert_at_end(h ,t , 7);
    
    Insert_at_start(h,t, 1);
    Insert_at_mid(h,t, 5, 3);
    t->next = h->next->next;
    print(h,t);
    
    if(is_cycle(h,t))
    {
        cout<<endl<<"cycle hai";
        print(h,t);
    }
}
    