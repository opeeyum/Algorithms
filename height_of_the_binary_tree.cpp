#include<iostream>
#include<stdlib.h>
#include<stack>
#include<cmath>

using namespace std;

class node
{
    int data = 0;
    node *left = NULL, *right = NULL;
    public:
        node* create_node(int);
        node* insert_node(node*, int);
        int find_height(node*);
        void Print(node*);
};

int main()
{
    srand(time(0));
    int n = 10, i=0;
    int arr[n] = {42, 23, 74, 11, 65, 58, 94, 36, 99, 85};

    //Array of random numbers to create a binary tree
    /*for(; i<n; i++)
    arr[i] = rand()%100;*/

    node obj, *root=NULL;
    for(i=0; i<n; i++)
    root = obj.insert_node(root, arr[i]);

    obj.Print(root);
    cout<<endl;
    cout<<obj.find_height(root)<<endl;
    }

int node::find_height(node *root)
{
    if(!root)
    return -1;
    if(!root->left && !root->right)
    return 0;
    return max(find_height(root->left), find_height(root->right))+1;    
}

node* node::create_node(int val)
{
    node* temp = new node();
    temp->data = val;
    return temp;
}

node* node::insert_node(node* root, int data)
{
    if(!root)
    return create_node(data);

    else if(root->data < data)
    root->right = insert_node(root->right, data);

    else
    root->left = insert_node(root->left, data);

    return root;
}

void node::Print(node* root)
{
    stack <node*> st;
    st.push(root);
    while(!st.empty())
    {
        node* temp = st.top();
        st.pop();
        if(temp->right)
        st.push(temp->right);
        if(temp->left)
        st.push(temp->left);

        cout<<temp->data<<" ";
    }
}