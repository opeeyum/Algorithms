// In 0/1 knapsack problem, we have only two choices
// either pick the element or not pick the element and element can only be picked once.
// But in unbonded knapsack, when we pick the element there is no such reistriction of picking element once.

// Problems under unbounded knapsack:-
//  1. Rod cutting Problem.
//  2. Coin change, Maximum number of coins to get given sum.
//  3. Coin change, Minimum number of coins to get given sum.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int ccm_helper(vector<int> &coins, int amt, int n, vector<vector<int>> &ds)
{
    if (amt == 0)
        return 0;
    if (n == 0)
        return INT_MAX - 1;

    if (ds[n - 1][amt] != -1)
        return ds[n - 1][amt];

    int pick = INT_MAX;
    if (amt >= coins[n - 1])
        pick = 1 + ccm_helper(coins, amt - coins[n - 1], n, ds);

    return ds[n - 1][amt] = min(ccm_helper(coins, amt, n - 1, ds), pick);
}
int coin_change_memoized(vector<int> &coins, int amount)
{
    vector<vector<int>> ds(coins.size(), vector<int>(amount + 1, -1));
    int res = ccm_helper(coins, amount, coins.size(), ds);
    if (res == INT_MAX - 1)
        return -1;
    return res;
}

int coin_change_tabulated(vector<int> &coins, int amount)
{
    int row = coins.size() + 1;
    int col = amount + 1;
    vector<vector<int>> ds(row, vector<int>(col, -1));

    // Intialisation
    for (int j = 1; j < col; j++)
        ds[0][j] = INT_MAX - 1;

    for (int i = 0; i < row; i++)
        ds[i][0] = 0;

    // Tabulation
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            ds[i][j] = min(ds[i - 1][j], (j - coins[i - 1] >= 0 ? 1 + ds[i][j - coins[i - 1]] : INT_MAX));
        }
    }
    if (ds[row - 1][col - 1] == INT_MAX - 1)
        return -1;
    return ds[row - 1][col - 1];
}