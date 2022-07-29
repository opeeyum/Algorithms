// MCM -> Recursive
//  -> Recursive memomized
// No Top down appraoch, it doesn't help.

// FORMAT
// 1. -> Decide i and j
// 2. -> Set range of K
// 3. -> Find funtion/operation to apply on temp_val

// Printing MCM
// Evaluate Expression to True or Boolean Parenthesis
// Min/Max value of an expression
// Palindrome Partitioning
// Scramble string
// Egg Droping Problem

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef vector<vector<int>> tdvec;

int mcm(int *arr, int i, int j, tdvec &ds)
{
    // Base condition
    if (i >= j)
        return 0;

    // Memomisation
    if (ds[i][j] != -1)
        return ds[i][j];

    int cost = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = mcm(arr, i, k, ds) + mcm(arr, k + 1, j, ds);
        temp += (arr[i - 1] * arr[k] * arr[j]);

        cost = cost > temp ? temp : cost;
    }

    return ds[i][j] = cost;
}

bool is_palindrome(string str, int left, int right)
{
    while (left < right)
    {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }
    return true;
}
int palindrominc_partioning(string str, int left, int right)
{
    // Base condtion
    // 1. Length of string either 0 or 1
    if (left >= right)
        return 0;

    // 2. Given string is palindrome
    if (is_palindrome(str, left, right))
        return 0;

    int ans = 1000001;
    // Computation
    for (int k = left; k < right; k++)
    {
        int temp_cost = palindrominc_partioning(str, left, k) + palindrominc_partioning(str, k + 1, right);
        temp_cost += 1;

        ans = temp_cost < ans ? temp_cost : ans;
    }
    return ans;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    tdvec ds(n + 1, vector<int>(n + 1, -1));
    cout << mcm(arr, 1, n - 1, ds) << endl;

    cout << palindrominc_partioning("abcde", 0, 4) << endl;
}