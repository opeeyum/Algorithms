# Sorting Algorithms

## What is Sorting?
 Arranging all the elements of a given array / list in an ascending order is termed as sorting.
 
 There are various Sorting techinques as following:
 
 - **Selection Sort**
 
 - **Insertion Sort**
 
 - **Bubble Sort**
 
 - **Merge Sort**
 
 - **Quick Sort**

 - **Heap Sort**

Each of these are different sorting algorithm with - varing time and space complexity.

**`In sorting algorithms time complexity signifies the number of comparision that are performed to find the correct position of an element in an array.`**

## Selection Sort
- It is one of the Greedy algorithm, in which we find minimum element in every swap.

- *Algorithm*:
    1. Start iterating through the given array form Zero to last index.
    2. In each iteration find the minimum element between **index < iteration number <= last index**.
    3. Swap the minimum with element at index == iteration number. 

- `After first iteration smallest element will be at its correct position (i.e index = 0). `

    ```cpp
    void selection_sort(int a[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            int index = 0;
            int temp = a[i];
            for (int j = i + 1; j < n; ++j)
            {
                if (temp > a[j])
                {
                    index = j;
                    temp = a[j];
                }
            }
            if (index != 0)
                swap(a[i], a[index]);
        }
    }
    ```

- Time complexity: 
    ```cpp
    o(n*n) - for all best, average and worst case.
    ```
- Space complexity: **o(1)**

- `Selection sort performs Maximum Comparisons and Minimum Swaps to sort a given array. (n-1) swaps that is o(n).`
 
## Insertion Sort
- *Algorithm*:
    1. Start iterating through the given array from index 1 to last index.
    2. In each iteration check whether there exists a smaller element at **index < iteration number** or not.
    3. If **YES** swap the elements and repeat step 2.
    4. If **NO** continue iteration.

- Time complexity: 

    ```cpp
    o(n) - For Best case, that is given array is already sorted in ascending order. 
    o(n*n) - For Average and worst case.
    ```
- Space complexity: **o(1)**

- ``Preferred when given array is partially sorted.``
    ```cpp
    void insertion_sort(int a[], int n)
    {
        for (int i = 1; i < n; ++i)
        {
            int j = i;
            while (j-- && a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
            cout << "Pass " << i << " result: ";
            for (int i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    ```
## Bubble Sort
- *Algorithm*:

    1. Start iterating through the given array form Zero to one less last index.
    2. For each iteration, start second iteration form Zero to one less last index.
    3. Keep swaping the elements **if array\[i] > array\[i+1]** in second iteration.

- `After first iteration largest element will be at its correct position (i.e index = n-1). `

- Time complexity: 

    ```cpp
    o(n) -- For Best case, that is give array is already sorted in ascending order. 
    o(n*n) -- For Average and worst case.
    ```
- Space complexity: **o(1)**
    ```cpp
    void bubble_sort(int a[], int n)
    {
        int count = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int flag = 0;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j + 1], a[j]);
                    flag++;
                    count++;
                }
            }
            if (flag == 0)
                break;
        }
    }
    ```
## Merge Sort
- Merge sort follows divide and conquer strategy, in which first we divide the array into smaller array's, sort those smaller arrays and finally merge them together to get our original array in ascending order.

- Time complexity: 
    ```cpp
    o(n*logn) - For Best, Average and worst case.
    ```

- Space complexity: **o(n)**

    ![Merge Sort](https://github.com/opeeyum/CS_subjects/blob/6814fbabf2a7a0ea111a50a3e9f2202651dc777a/Images/merge_sort_image.png)
 
- ``Preferred to used when order of incoming (intial ordering) elements is unknown.``
    ```cpp
    void Merge_sort(int *a, int size)
    {
        if (size < 2)
            return;
        // Find the mid point the given array
        int mid = size / 2;

        // Create two additional arrays to store left and right part respectively, of given array
        int left[mid], right[size - mid];
        for (int i = 0; i < mid; i++)
            left[i] = a[i];

        for (int j = 0, i = mid; i < size; i++, j++)
            right[j] = a[i];

        // Call Merge sort on left and right array
        Merge_sort(left, mid);
        Merge_sort(right, size - mid);

        // Finally merge  the left and right array
        Merge(a, left, right, mid, size - mid);
        return;
    }

    void Merge(int *a, int *left, int *right, int ll, int rl)
    {
        int i, j, k;
        i = j = k = 0;
        while (i < ll && j < rl)
        {
            if (left[i] < right[j])
                a[k++] = left[i++];

            else
                a[k++] = right[j++];
        }
        while (i < ll)
            a[k++] = left[i++];

        while (j < rl)
            a[k++] = right[j++];

        return;
    }
    ```
## Quick Sort
- Quick sort is also an one of the divide and conquer strategy.
    1. First we select an element, called as pivot element.
    2. Find the correct position of pivot element by positioning all the smaller and larger elements to pivot's left and right side repectively.
    3. Now, Repeat Step-1 and Step-2 for array elements at left and right to the pivot.

- Time complexity: 

    ```cpp
    o(n*logn) -- For Best, Average.
    o(n*n) -- For worst case, when array is already sorted, reversed sorted or all elements are same.
    ```

- Space complexity: **o(1)**

    > In quick sort when **Pivot** is selected at the middle index then it gives best case time complexity.
    ```cpp
    void quick_sort(int *a, int start, int End)
    {
        if (start < End)
        {
            int p_index = Partition(a, start, End);
            quick_sort(a, start, p_index - 1);
            quick_sort(a, p_index + 1, End);
        }
    }

    int Partition(int *a, int Front, int tail)
    {
        // Selecting last element as Pivot
        int pivot = a[tail];

        int j = Front, k = Front - 1;
        for (; j < tail; ++j)
        {
            if (pivot > a[j])
                swap(a[j], a[++k]);
        }

        // Placing Pivot in its Correct Position
        swap(a[++k], a[tail]);

        cout << "Intermediate answer: ";
        for (int i = Front; i <= tail; ++i)
            cout << a[i] << " ";

        cout << endl;
        return k;
    }
    ```
## Heap Sort
- Heap is a special type data structure where Root node can have either highest or lowest value among its children.
- Now if root has the higest value then we call heap as "MAX heap" other wise "MIN heap". 
- Max heap will always have highest value at root node for given array.
- We can use priority queue for implementing heap.
- *Algorithm*:
    1. Insert all the element of given array into the heap.
    2. Now till heap becomes empty pop element from the heap and swap with the last element of the array.

- Time complexity
    ```cpp
    nlog(n)
    ```
    and, 
- Space complexity: o(n)
```cpp
#include<queue>
void heap_sort(int *arr, int n)
{
    priority_queue<int> max_heap(arr, arr + n);
    while (!max_heap.empty())
    {
        int temp = max_heap.top();
        swap(arr[--n], temp);
        max_heap.pop();
    }
}
```

## Stable / UnStable sorting algorithm
- A Sorting algorithm is said to be ***stable*** if it maintains the relative ordering of non-distinct(same) elements, if not so algorithm is ***unstable***.
