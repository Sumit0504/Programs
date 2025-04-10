#include<iostream>
using namespace std;
class node
{
    public:
    string key;
    int value;
    node* next;

    node(string &s, int d)
    {
        key=s;
        value = d;
        next = NULL;
    }
};
class hashmap
{   private:
    int hashfunc(string key)
    {
        int ans =0;
        int mul = 1;
        /*  i we apply the followig loop error occurance is key[i]*mul may be more then range of integer
            so we do % ts to each term 
        for(int i=0; i< key.size(); i++)
        {
            ans += key[i]*mul;
            mul *= 37; 
        } */

        for(int i=0; i< key.size(); i++)
        {
            ans += (key[i]%ts)* (mul%ts);
            mul *= 37; 
            ans %= ts;
            mul %= ts;
        } 
        return ans%ts;
    }
    void rehashing()
    {
        node** old_a = a;
        int old_ts = ts;
        a = new node*[2*ts];
        cs= 0;
        ts = 2*ts;
        for(int i=0; i<ts; i++)
        {
            a[i]=NULL;
        }
        //now we will iterate on old array to insert its value in new array
        for(int i=0; i<old_ts; i++)
        {
            node* head = old_a[i];
            if(!head) continue;

            while(head)
            {
                string key = head->key;
                int value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        delete []old_a;
    }
    public:
    node** a;
    int ts;
    int cs;
    hashmap(int s =5)
    {
        ts = s;
        a = new node* [ts];
        for(int i=0; i<ts; i++)
        {
            a[i] = NULL;
        }
        cs = 0;
    }
    
    void insert(string key, int value)
    {
        // here we will change the string to the inde using hash function
        int index = hashfunc(key);

        node* n = new node(key, value);
        n->next = a[index];
        a[index] = n;
        cs++;

        float load_factor = (cs*1.0)/ts; // it is used to check how much the table is filled 

        if(load_factor >= 0.6)
        {
            rehashing();
        }
    }
    void print()
    {
        for(int i=0; i<ts; i++)
        {
            node* head = a[i];
            cout<<i<<"-->";
            while(head)
            {
                string key = head->key;
                int value = head->value;
                cout<<"("<<key<<", "<<value<<")";
                head = head->next;
            }
            cout<<endl;
        }
    }

    node* search(string &key)
    {
        int hashindex = hashfunc(key);
        node* head = a[hashindex];
        while(head)
        {
            if(head->key==key)
            {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }

    int& operator[](string key)
    {
        node* x = search(key);
        if(x == NULL)
        {
            int random;
            insert(key, random);
            x = search(key);
            return x->value;
        }
        return x->value;
    }

};

int main()
{
    hashmap h;
    h.insert("Mango",100);
    h.insert("Kiwi",20);
    h.insert("Banana",50);
    h.insert("Pineapple",150);
    h.insert("Guava",1500);
    // to do something like below we need to create a function using operator
    h["orange"] = 100; // insert
    cout<<h["orange"]<<endl; // read

    h.print();
    return 0;
}