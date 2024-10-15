#include<iostream>
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
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main()
{
    node* root = build_tree();
    cout<<"pre: ";pre_order(root);
    cout<<endl;
    cout<<"in: ";in_order(root);
    cout<<endl;
    cout<<"post: "; post_order(root);
    cout<<endl;
    cout<<"height tree: "<<height(root);
    cout<<endl;
    cout<<"Number of nodes: "<<count_node(root);
    cout<<endl;
    cout<<"Diameter: "<<diameter(root);

}