#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class BST
{
    int data=0;
    BST *left = NULL;
    BST *right = NULL;
    public:

        BST* create_node(int);
        BST* insert_(BST*, BST*);
        void pre_order_traversal(BST*);
        void BFS_traversal(BST*);
        void DFS_traversal(BST*);

};

int main()
{
    int arr[] = {14, 10, 17, 12, 11, 20, 18, 25, 8, 22, 23};
    BST *head = NULL;
    BST obj;
    for(int i=0; i<11; i++)
    {
        BST* temp = obj.create_node(arr[i]);
        head = obj.insert_(head, temp);
    }
    cout<<"Pre-order traversal: ";
    obj.pre_order_traversal(head);
    cout<<"\n\nBreadth First Traversal: ";
    obj.BFS_traversal(head);
    cout<<"\n\nDepth First Traversal: ";
    obj.DFS_traversal(head);
    cout<<"\n\n";
}

BST* BST::create_node(int val)
{
    BST* temp_head = new BST();
    temp_head->data = val;
    return temp_head;
}
BST* BST::insert_(BST* head, BST* temp_head)
{
    if(head == NULL)
        head = temp_head;
    else if(head->data >= temp_head->data)
        head->left = insert_(head->left, temp_head);
    else
        head->right = insert_(head->right, temp_head);
    return head;
}

void BST::pre_order_traversal(BST* head)
{
    if(head != NULL)
    {
        cout<<head->data<<" ";
        pre_order_traversal(head->left);
        pre_order_traversal(head->right);
    }
}

void BST::BFS_traversal(BST *head)
{
    if(!head)
        return;
    queue <BST*> q;
    q.push(head);
    while(!q.empty())
    {
        BST* temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        cout<<temp->data<<" ";
    }
}

void BST::DFS_traversal(BST *head)
{
    if(!head)
        return;
    stack <BST*> s;
    s.push(head);
    while(!s.empty())
    {
        BST* temp = s.top();
        s.pop();
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
        cout<<temp->data<<" ";
    }
}
