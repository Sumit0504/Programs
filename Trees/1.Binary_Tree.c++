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
node* build_tree()
{
    int data;
    cin>>data;
    if(data == -1) return NULL;
    node* n = new node(data);
    n->left = build_tree();
    n->right = build_tree();
    return n; //vapis jate hue address(n) return krna hai 
};

// *-*-*-*-*-*-*-*-*-print-*-*-*-*-*-*-*-*-*
void pre_order(node* root)
{
    if(!root) return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(node* root)
{
    if(!root) return;
    pre_order(root->left);
    cout<<root->data<<" ";
    pre_order(root->right);
}
void post_order(node* root)
{
    if(!root) return;
    pre_order(root->left);
    pre_order(root->right);
    cout<<root->data<<" ";
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
// *-*-*-*-*-*-*-*-*-height-*-*-*-*-*-*-*-*-*
int height(node* root)
{
    if(!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return(max(left,right)+1);
}
// *-*-*-*-*-*-*-*-*-No. of Nodes -*-*-*-*-*-*-*-*-*
int count_node(node* root)
{
    if(!root) return 0;
    return count_node(root->left) + count_node(root->right)+1;
}
// *-*-*-*-*-*-*-*-*-Diameter-*-*-*-*-*-*-*-*-*
int diameter(node* root)
{
    int op1 = height(root->left) + height(root->right);
    int op2 = height(root->left);
    int op3 = height(root->right);

    return(max(op1, max(op2, op3)));
}
// *-*-*-*-*-*-*-*-*-Fast Diameter-*-*-*-*-*-*-*-*-*
class Pair
{
public:
    int height;
    int diameter;
};
Pair fast_diameter(node* root)
{
    Pair p;
    if(!root)
    {
        p.height = p.diameter = 0;
        return p;
    }

    Pair left = fast_diameter(root->left);
    Pair right = fast_diameter(root->right);
    
    int op1 = left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    p.diameter = max(op1, max(op2, op3));
    p.height = max(left.height , right.height)+1;
    return p;
}

// *-*-*-*-*-*-*-*-*-Mirror Tree-*-*-*-*-*-*-*-*-*
void mirror(node* root)
{
    if(!root)
    {
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}
int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int k=0;
node* crete_tree(int *in, int s, int e)
{
    if(s>e) return NULL;

    node* root = new node(pre[k]);
    k++;
    int i;
    for(int j=s; j<=e; j++)
    {
        if(in[j] == root->data)
        {
            i=j;
            break;
        }
    }
    root->left = crete_tree(in,s,i-1);
    root->right = crete_tree(in,i+1,e);
    return root;
}
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main()
{
    // node* root = build_tree();
    // cout<<"pre: ";pre_order(root);
    // cout<<endl;
    // cout<<"in: ";in_order(root);
    // cout<<endl;
    // cout<<"post: "; post_order(root);
    // cout<<endl;
    // cout<<"height tree: "<<height(root);
    // cout<<endl;
    // cout<<"Number of nodes: "<<count_node(root);
    // cout<<endl;
    // cout<<"Diameter: "<<diameter(root);
    // cout<<endl;
    // cout<<"level order print: "; level_order(root);
    
    // Pair ans = fast_diameter(root);
    // cout<<"Fast_diameter: "<<ans.diameter;
    // cout<<endl<<"Fast_height: "<<ans.height;
    int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
	int n = sizeof(in) / sizeof(int);
    node* root = crete_tree(in,0,n-1);
    cout<<"tree: ";
    level_order(root);
}