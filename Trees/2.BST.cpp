#include<iostream>
#include<queue>
using namespace std;
class node
{public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node* create_bst(node* root, int data)
{
    if(!root) 
    {
        root = new node(data);
        return root;
    }

    if(data<= root->data)
    {
        root->left = create_bst(root->left, data);
    }
    else
    {
        root->right = create_bst(root->right, data);
    }
    return root;
}
void level_order(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* x = q.front();
        q.pop();
        if(x!=NULL)
        {
            cout<< x->data <<" ";
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        else
        {
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
    }
}

int main()
{
    
}