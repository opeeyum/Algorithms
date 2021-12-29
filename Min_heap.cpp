#include<iostream>
using namespace std;

void build_min_heap(int*, int);
//heapify will take array, array length and index to start heapify
void heapify(int*, int, int);
void Print(int*, int);

int main()
{
    //number of elements
    int len=6;
    int heap[] = {6, 5, 4, 3, 2, 1};
    build_min_heap(heap, len);
    Print(heap, len);
}

void build_min_heap(int *arr, int len)
{
    /*If array has n elements than last non-leaf member will be at index = n/2.
    Start heapifying from last non-leaf to the root.*/
    for(int i=len/2; i>=0; i--)
        heapify(arr, len, i);
}

void heapify(int *arr, int len, int i)
{
    //Index of left and right children
    int left=i*2+1, right=i*2+2;

    //Index too point minimum among -- root, left and right children
    int min_ind = i;
    if(left < len && arr[min_ind] > arr[left])
        min_ind = left;
    if(right < len && arr[min_ind] > arr[right])
        min_ind = right;

    //Root is minimum return
    if(min_ind == i)
        return;

    //Else swap the root and minimum element
    swap(arr[i], arr[min_ind]);
    //Swapping may distort the left or right sub-heap, heapify it
    heapify(arr, len, min_ind);
}

void Print(int *arr, int len)
{
    for(int i=0; i<len; i++)
        cout<<arr[i]<<" ";
}
