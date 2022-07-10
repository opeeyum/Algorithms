#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void Print_Graph(int *, int);
void BFS(int *, int);
void DFS(int *, int);

int main()
{
    // Graph
    int graph[][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0},
    };

    // Type casting the pointer to pointer to just pointer
    Print_Graph((int *)graph, 8);
    BFS((int *)graph, 8);
    cout << endl;
    DFS((int *)graph, 8);
    cout << endl;
    return 0;
}

void Print_Graph(int *graph, int n)
{
    // Going with Row major order
    // Here graph is pointer pointing the first element of fist row of the 2D array
    cout << "The adjacency matrix for given graph:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << *(graph + i * n + j) << " ";
        cout << "\n";
    }
}

void BFS(int *graph, int n)
{
    bool visited[n];
    // Initializing visited array to false
    for (int i = 0; i < n; i++)
        visited[i] = false;
    queue<int> s;
    // Push down the first vertex
    s.push(0);
    // Mark the vertex as visited if vertex has been added to the queue
    visited[0] = true;
    cout << "\nBreadth First Traversal: ";
    while (!s.empty())
    {
        int temp = s.front();
        s.pop();
        for (int i = 0; i < n; i++)
        {
            if (*(graph + temp * n + i) == 1 && !visited[i])
            {
                // Added the adjacent vertex to the array and mark the vertex as visited
                s.push(i);
                visited[i] = true;
            }
        }
        // Print the vertex, since first index is zero hence adding 1 to all vertices's
        cout << temp + 1 << " ";
    }
}
void DFS(int *graph, int n)
{
    bool visited[n];
    // Initializing visited array to false
    for (int i = 0; i < n; i++)
        visited[i] = false;
    stack<int> s;
    // Push down the first vertex into the stack
    s.push(0);
    visited[0] = true;
    cout << "\nDepth First Traversal: ";
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            if (*(graph + temp * n + i) == 1 && !visited[i])
            {
                // Push all the adjacent vertex into the stack
                s.push(i);
                // Mark the vertex as visited if its all adjacent vertex has been pushed to the stack
                visited[i] = true;
            }
        }

        cout << temp + 1 << " ";
    }
}
