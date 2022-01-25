# Heap Sort

Heap sort is an inplace sorting algotrithm with;
>Time complexity
```
nlog(n)
```
and, 
>Space complexity
```
o(1)
```
## What is heap?
Heap is a user defined tree type data structure where Root node can have either highest or lowest value among its children.
Now if root has the higest value then we call heap as "MAX heap" other wise "MIN heap". 
>We insert data in heap by completely filling up the level in left to right fashion.

A heap can be n-ary, that is internal nodes can have atmost n-children. For now, lets talk about Binary-heap.
## Building a max heap?
While creating a max-heap the only thing we have to ensure is root node must have highest value among its children.
Generally we take heap in the form of **array** as input and arrange its element such a way that for each 
> arr\[ i ]; 

> arr\[ i\*2+1 ] and arr\[ i\*2+2 ] 

acts its left and right child.

But, not all the element in heap can have children; hence, elements from index 
>0 to n/2

are treated as internal nodes. Whereas elements from index
>(n/2)+1 to n-1 

are treated as leaf nodes.

Now, we start heapifying \(*Setting root value as highest*), from last internal node to the root node.
```
void Build_max_heap(int* arr, int len)
{
    for(int i=len/2; i>=0; i--)
        max_heapify(arr, len, i);
}
```
### The heapify algorithm
1. Store the index of root element\(i.e ***i*** ) in a temporary variable \(i.e ***max_ind*** ).
2. Check whether value at index **max_ind** is highest or not among the elements at index **i\*2+1** and **i\*2+2**.
3. If the value at **max_ind* not the highest, store the index of highest value at **max_ind**.
4. If the value of **max_ind** is changed, Swap the value of root node with node at index == **max_ind**.
5. If root value of certain heap is changed apply **heapify** to its child heap.
```
void max_heapify(int* arr, int len, int i)
{
    //index of left and right child
    int left = i*2+1, right = i*2+2;
    
    // Index of largest element
    int max_ind = i;
    
    // If left child greater than element at max_ind
    if(left < len && arr[max_ind] < arr[left])
        max_ind = left;
        
    // If right child greater than element at max_ind
    if(right < len && arr[max_ind] < arr[right])
        max_ind = right;

    /*If root is the max element return
    Else swap the max element with root, and apply the max_heapify in respective sub-heap
    */
    if(max_ind == i)
        return;

    swap(arr+max_ind, arr+i);
    max_heapify(arr, len, max_ind);
}
```
## How to use heap for sorting?
Max heap will always have highest value at root node for given array.
Now if we 
1. Swap root node with last child node.
> Node at index == n-1

2. And build a heap for elements from index
> 0 to n-1

Now we can Keep extracting maximum element from the heap, until only one element left in the max heap.
At last we will left with sorted array.
```
void max_heap_sort(int* arr, int len)
{
    while(len>1)
    {
        /*Swap the last element of heap with first element.
        And decrement the size of heap by 1.
        */
        swap(arr, arr+--len);
        max_heapify(arr, len, 0);
        cout<<"Max Heap: ";
        PRINT(arr, len);
    }
}
```
