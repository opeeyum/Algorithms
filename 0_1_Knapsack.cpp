// Best thing is to write recursive code following the pick and not-pick technique.
// Then, convert that recursion to tabulation.

// Problems with minute variation with 0/1 knapsack.
// 1. Subset Sum - Done
// 2. Equal Sum Partition - Done
// 3. Count of Subset sum - Done
// 4. Minimum Subset Sum Diff
// 5. Target Sum by assigning +/- operators
// 6. Number of subset with given difference

#include <iostream>
#include <vector>
using namespace std;

// Problem statement:-
//      Given an array, and the target, check whether there exists any subset with sum equal given target.
// Algortihm:-
//      Find all the subsets and their respective sum and return True if any sum eqaul to target, else return false.
// Likeness to 0/1 knapsack is that,
//      We can treat given array as weight array, each weight also represents its value,
//      and the quantity of knapsack is equal to target.
bool subset_sum(int *arr, int n, int target)
{
    // Recursion:-
    // if (target == 0)
    //     return true;
    // else if (n == 0)
    //     return false;
    vector<vector<bool>> helper(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < helper.size(); i++)
    {
        for (int j = 0; j < helper[0].size(); j++)
        {
            if (j == 0)
                helper[i][j] = true;
        }
    }

    // bool pick = false;
    // if (target >= arr[n - 1])
    //     pick = subset_sum(arr, n - 1, target - arr[n - 1]);
    // return subset_sum(arr, n - 1, target) || pick;
    for (int i = 1; i < helper.size(); i++)
    {
        for (int j = 1; j < helper[0].size(); j++)
        {
            helper[i][j] = helper[i - 1][j] || (j - arr[i - 1] >= 0 ? helper[i - 1][j - arr[i - 1]] : false);
        }
    }
    return helper[n][target];
}

// Algorithm, Equal sum partition:-
// 1. Find the sum of all the elements of the given array.
// 2. If sum is odd, we can't equally part it.
// 3. If sum is even, we can reduce our problem to subset_sum,
//    with given array and target as half of the sum from step 1.
bool equal_sum_partition(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (!(sum / 2))
        return false;

    else
        return subset_sum(arr, n, sum / 2);
}

// Algorithm, Count subset sum:-
// 1.
int count_subset_sum(int *arr, int n, int target)
{
    vector<vector<int>> helper(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < helper.size(); i++)
    {
        for (int j = 0; j < helper[0].size(); j++)
        {
            if (j == 0)
                helper[i][j] = 1;
        }
    }
    for (int i = 1; i < helper.size(); i++)
    {
        for (int j = 1; j < helper[0].size(); j++)
        {
            helper[i][j] = helper[i - 1][j] + (j - arr[i - 1] >= 0 ? helper[i - 1][j - arr[i - 1]] : 0);
        }
    }

    return helper[n][target];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5, target = 11;
    cout << "Is subset present with sum = " << target << ", " << subset_sum(arr, n, target) << ".\n";
    cout << "Is equal sum partition possible " << equal_sum_partition(arr, n) << ".\n";
    cout << "Count subset(s) sum equal " << target << ", " << count_subset_sum(arr, n, target) << ".\n";
    return 0;
}