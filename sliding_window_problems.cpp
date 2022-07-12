// Sliding Windows Problems
// Sliding Window works when problem(s) is about subarrays.

// 1. Sum of all the subarrays of given size

#include <iostream>
using namespace std;

void sum_of_subarrays_of_given_size(int *arr, int n, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    cout << "Sum of all subarray(s) given size " << k << " : " << sum << " ";
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        cout << sum << " ";
    }
    cout << "\n";
}

int main()
{
    int n = 5, k = 2;
    int arr[] = {1, 2, 3, 4, 5};
    sum_of_subarrays_of_given_size(arr, n, k);
}
