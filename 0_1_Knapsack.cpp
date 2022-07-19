// Best thing is to write recursive code following the pick and not-pick technique.
// Then, convert that recursion to tabulation.

// Problems with minute variation with 0/1 knapsack.
// 1. Subset Sum
// 2. Equal Sum Partition
// 3. Count of Subset sum
// 4. Minimum Subset Sum Diff
// 5. Number of subset with given difference
// 6. Target Sum by assigning +/- operators
// -> For each element take its positive value and negative value.

// NOTE: If all the elements of given array needs to be present in the answer in certain orientation,
// better to check for success when index reaches out of range.

#include <iostream>
#include <string.h>
using namespace std;

// 1. Problem statement:-
//      Given an array and the target, check whether there exists any subset with sum equal given target.
// Algortihm:-
//      Find all the subsets and their respective sum and return True if any sum eqaul to target, else return false.
// Likeness to 0/1 knapsack is that,
//      We can treat given array as weight array, each weight also represents its value,
//      and the quantity of knapsack is equal to target.
bool recursive_subset_sum(int *arr, int n, int target)
{
    // Base Condition
    if (target == 0)
        return true;
    else if (n == 0)
        return false;

    // Pick condition
    bool pick = false;
    if (target >= arr[n - 1])
        pick = recursive_subset_sum(arr, n - 1, target - arr[n - 1]);

    // Non Pick condition
    return recursive_subset_sum(arr, n - 1, target) || pick;
}

bool tabulated_subset_sum(int *arr, int n, int target)
{
    int ds[n + 1][target + 1];

    memset(ds, 0, sizeof(ds));

    for (int i = 0; i <= n; i++)
        ds[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            ds[i][j] = ds[i - 1][j] || (j - arr[i - 1] >= 0 ? ds[i - 1][j - arr[i - 1]] : false);
        }
    }
    return ds[n][target];
}

// 2. Problem statement:-
//      For a given array creates ite two subsets such that their sum of elements is equal.
// Algorithm, Equal sum partition:-
//      1. Find the sum of all the elements in the given array.
//      2. If sum is odd, we can't equally part it.
//      3. If sum is even, we can reduce our problem to subset_sum,
//         with given array and target as half of the sum from Step 1.
bool equal_sum_partition(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (!(sum / 2))
        return false;

    else
        return tabulated_subset_sum(arr, n, sum / 2);
}

// 3. Problem statement:-
//      Count the number of subset(s), such that their sum equal to target.
// Algorithm, Count subset sum:-
//      In subset set sum we check whether subset exists or not.
//      While counting we to add 1 if sum exists.
int recursive_count_subset_sum(int *arr, int n, int target)
{
    if (target == 0)
        return 1;
    if (n == 0)
        return 0;
    int pick = 0;
    if (target >= arr[n - 1])
        pick = recursive_count_subset_sum(arr, n - 1, target - arr[n - 1]);

    return recursive_count_subset_sum(arr, n - 1, target) + pick;
}
int tabulated_count_subset_sum(int *arr, int n, int target)
{
    int ds[n + 1][target + 1];
    memset(ds, 0, sizeof(ds));

    for (int i = 0; i <= n; i++)
        ds[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            ds[i][j] = ds[i - 1][j] + (j - arr[i - 1] >= 0 ? ds[i - 1][j - arr[i - 1]] : 0);
        }
    }

    return ds[n][target];
}

// Driver Code
int main()
{
    int arr[] = {2, 3, 6, 8, 10};
    int n = 5, target = 11;
    cout << "Is subset present with sum = " << target << ", " << tabulated_subset_sum(arr, n, target) << ".\n";
    cout << "Is equal sum partition possible " << equal_sum_partition(arr, n) << ".\n";
    cout << "Count subset(s) - Recursivly sum equal " << target << ", " << recursive_count_subset_sum(arr, n, target) << ".\n";
    cout << "Count subset(s) sum equal " << target << ", " << tabulated_count_subset_sum(arr, n, target) << ".\n";
    return 0;
}