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
// Pallindrome Partitioning
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

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    tdvec ds(n + 1, vector<int>(n + 1, -1));
    cout << mcm(arr, 1, n - 1, ds) << endl;
}