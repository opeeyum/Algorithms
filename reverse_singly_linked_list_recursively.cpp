#include <iostream>
using namespace std;

class node
{
    int data = 0;
    node *next = NULL;
    public:
    node* create_linked_list(int*, int);
    node* create_node(int);
    node* reverse_ll_two_ptr(node*, node*);
    node* reverse_ll_single_ptr(node*);
    void Print(node*);
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, len = 5;
    node obj, *head = NULL;
    head = obj.create_linked_list(arr, len);
    obj.Print(head);
    head = obj.reverse_ll_two_ptr(head, NULL);
    obj.Print(head);
}

node* node::reverse_ll_two_ptr(node* head, node* prev)
{
    node *temp = head->next;
    head->next = prev;
    if(temp)
    return reverse_ll_two_ptr(temp, head);
    return head;
}

node* node::reverse_ll_single_ptr(node* head)
{
    node *rear = NULL;
    if(!head->next)
    {
        rear = head;
        return head;
    }    
    node* temp = reverse_ll_single_ptr(head->next);
    temp->next = head;
    head->next = NULL;
    return head;
}

node* node::create_linked_list(int* arr, int len)
{
    node *temp_head = NULL;
    for(int i=0; i<len; i++)
    {
        node *temp = this->create_node(arr[i]);
        if(!temp_head)
        temp_head = temp;
        else
        {            
            temp->next = temp_head;
            temp_head = temp;
        }
    }
    return temp_head;
}

node* node::create_node(int val)
{
    node *temp = new node();
    temp->data = val;
    return temp;
}

void node::Print(node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";        
        head = head->next;
    }
    cout<<endl;
}