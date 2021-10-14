#include <iostream>
#include <queue>
using namespace std;

class node
    {
        int data;
        node* left = NULL;
        node* right = NULL;
    public:
        node* Create_node(int);
        node* Insert(node* , int);
        void print(node*);
    };
node* node::Create_node(int a)
{
    node* temp = new node();
    temp->data = a;
    return temp;
}

node* node::Insert(node* root, int a)
{
    if(root == NULL)
    {
        root = Create_node(a);
        return root;
    }
    else if(root->data >= a)
        root->left = Insert(root->left, a);
    else
        root->right = Insert(root->right, a);
    return root;
}

void node::print(node* root)
{
    if(root == NULL)
        return;
    queue <node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
int main()
{
    node obj;
    node *head = NULL;
    int n;
    cin>>n;
    int a;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        head = obj.Insert(head, a);
    }
    cout<<"Breadth first traversal : ";
    obj.print(head);
    return 0;
}
