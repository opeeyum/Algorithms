#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void Merge_sort(int *, int);
void quick_sort(int *, int, int);
int Partition(int *, int, int);
void Merge(int *, int *, int *, int, int);

void heap_sort(int *, int);

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int a[n], i = 0;
    cout << "Enter numbers: ";
    for (; i < n; ++i)
        cin >> a[i];

    heap_sort(a, n);

    for (i = 0; i < 50; ++i)
        cout << "-";
    cout << endl;

    cout << "Final result: ";
    for (i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
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
        cout << "After pass " << i << ": ";
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "; Total Swaps so far: " << count << endl;

        if (flag == 0)
            break;
    }
}
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
