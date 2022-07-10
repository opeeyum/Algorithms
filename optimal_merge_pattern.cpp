/*
Algorithm-

Step 1: Build a min heap with given array.
Step 2: Extract two minimum from the heap.
Step 3: Store the sum of two minimums.
Step 4: Add the sum of two minimum's into heap.
        Repeat all four steps above until there is only one element left in heap.
Step 5: Print the sum of minimums.
*/

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void Print(int *, int);
int main()
{
    int n = 5;
    int arr[] = {5, 10, 20, 30, 30};
    Print(arr, n);
    // Creating a min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n; i++)
        min_heap.push(arr[i]);

    int total_cost = 0;
    while (min_heap.size() != 1)
    {
        int top1 = min_heap.top();
        min_heap.pop();
        int top2 = min_heap.top();
        min_heap.pop();

        total_cost += (top1 + top2);
        cout << total_cost << "\n";
        min_heap.push(top1 + top2);
    }
    cout << "Total Cost: " << total_cost << "\n";
}

void Print(int *arr, int n)
{
    cout << ">>> ";
    for (int i = 0; i < n; i++)
        cout << setw(3) << arr[i] << " ";
    cout << endl;
}
