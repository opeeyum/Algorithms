#include<iostream>
#include<stack>
using namespace std;

void Print_Graph(int*, int);
void DFS(int*, int);

int main()
{
    //Graph
    int graph[][8]= { {0, 1, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 1, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                     };
    //Type casting the pointer to pointer to just pointer
    Print_Graph((int*)graph, 8);
    DFS((int*)graph, 8);
    cout<<endl;
    return 0;
}

void Print_Graph(int *graph, int n)
{
    //Going with Row major order
    //Here graph points to first element of fist row of the 2D array
    cout<<"The adjacency matrix for given graph:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        cout<<*(graph+i*n+j)<<" ";
        cout<<"\n";
    }
}

void DFS(int *graph, int n)
{
    bool visited[n];
    //Initializing visited array to false
    for(int i=0; i<n; i++)
        visited[i]=false;
    stack <int> s;
    //Push down the first vertex into the stack
    s.push(0);
    cout<<"\nDepth First Traversal: ";
    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        for(int i=n-1; i>=0; i--)
        {
            if(*(graph+temp*n+i)==1 && !visited[i])
                //Push all the adjacent vertex into the stack
                s.push(i);
        }
        //Mark the vertex as visited if its all adjacent vertex has been pushed to the stack
        visited[temp] = true;
        cout<<temp+1<<" ";
    }
}
