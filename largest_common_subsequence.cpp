// Actual Problem: Longest Common Subsequence

// If We have a option to choose, think of recursion.
// Any recursive function will have three parts:
//  1. Base condition
//  2. Choice diagram / computation
//  3. Function call with reduced input.

#include <iostream>
#include <vector>
#include <climits>
#include <string.h>
#include <algorithm>

using namespace std;

int LCSubsequence_recursive(string x, string y, int n, int m, vector<vector<int>> &ds)
{
    // Base Condition
    if (n == 0 || m == 0)
        return 0;

    if (ds[n][m] != -1)
        return ds[n][m];

    // Choice diagram
    int pick = INT_MIN;
    if (x[n - 1] == y[m - 1])
        return ds[n][m] = 1 + LCSubsequence_recursive(x, y, n - 1, m - 1, ds);
    else
        return ds[n][m] = max(LCSubsequence_recursive(x, y, n - 1, m, ds), LCSubsequence_recursive(x, y, n, m - 1, ds));
}

int LCSubsequence_tabulated(string first, string second)
{
    int n = first.length(), m = second.length();
    int ds[n + 1][m + 1];

    memset(ds, 0, sizeof(ds));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (first[i - 1] == second[j - 1])
                ds[i][j] = 1 + ds[i - 1][j - 1];

            else
                ds[i][j] = max(ds[i - 1][j], ds[i][j - 1]);
        }
    }
    return ds[n][m];
}

// -------------Problem Variations-----------------------

// 1. Print LCS -> Backtrack the sequence
string LCSubsequence(string first, string second)
{
    int n = first.length(), m = second.length();
    int ds[n + 1][m + 1];

    memset(ds, 0, sizeof(ds));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (first[i - 1] == second[j - 1])
                ds[i][j] = 1 + ds[i - 1][j - 1];

            else
                ds[i][j] = max(ds[i - 1][j], ds[i][j - 1]);
        }
    }

    string ans = "";

    while (n > 0 && m > 0)
    {
        if (first[n - 1] == second[m - 1])
        {
            ans += first[n - 1];
            n--;
            m--;
        }
        else if (ds[n - 1][m] > ds[n][m - 1])
            n--;
        else
            m--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// 2. Largest Pallindromic Subsequence -> find lcs(str, reverse(str));
// 3. Subsequence Pattern Matching | Check whether given string "a" is subseqence of "b" or not
// -> len(lcs(a, b)) == len(a);
// 4. Min number of insertion and deletion to make string a == string b.
// -> deletion = str1.length - lec.length, insertion = str2.length - lcs.length
// 5. Min number of deletion in a string to make it a pallindrome.
// -> str.length - lcs(str, reverse(str));
// 6. Min number of insertion in a string to make it a pallindrome.
// -> str.length - lcs(str, reverse(str));

// 7. Length Shortest Common SuperSequence
// -> str1.length + str2.length - lcs.length;
// 8. Print SCS
// -> While printing the lcs we only involve charactre present in both string here we also take characters when doesn't match.

// 9. Largest common Substring
string LCSubstring(string first, string second)
{
    int n = first.length(), m = second.length();
    int ds[n + 1][m + 1];

    memset(ds, 0, sizeof(ds));

    int arr[3] = {0, 0, 0};

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (first[i - 1] == second[j - 1])
                ds[i][j] = 1 + ds[i - 1][j - 1];
            if (ds[i][j] > arr[0])
            {
                arr[0] = ds[i][j];
                arr[1] = i;
                arr[2] = j;
            }
            cout << ds[i][j] << " ";
        }
        cout << endl;
    }

    string ans = "";

    while (arr[1] > 0 && arr[2] > 0)
    {
        if (first[arr[1] - 1] == second[arr[2] - 1])
        {
            ans += first[arr[1] - 1];
            arr[1]--;
            arr[2]--;
        }
        else
            break;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 10. Largest repeating subsequence
// lcs(str, str) where ds[i-1] == ds[j-1] && i != j
// 11. Length of largest subsequence of a which is a substring is b.

// 12. Count How many times a appear as subsequence in b.
// 13. Largest Pallindromic Substring
string longest_pallindromic_subtring(string one)
{
    int n = one.length();
    int ds[n][n];

    memset(ds, 0, sizeof(ds));

    int start_ind = 0;
    int max_len = 1;

    for (int r = 0; r < n; r++)
        ds[r][r] = 1;

    for (int r = 0; r < n - 1; r++)
    {
        if (one[r] == one[r + 1])
        {
            ds[r][r + 1] = 1;
            start_ind = r;
            max_len = 2;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int r = 0; r < n - k + 1; r++)
        {
            int c = r + k - 1;

            if (one[r] == one[c] && ds[r + 1][c - 1] == 1)
            {
                ds[r][c] = 1;
                if (k > max_len)
                {
                    start_ind = r;
                    max_len = k;
                }
            }
        }
    }

    string ans = "";
    for (int i = start_ind; i < start_ind + max_len; i++)
        ans += one[i];

    return ans;
}
// 14. Count Pallindromic Substring

int main()
{
    string one = "1235986";
    string two = "12345986";

    // cout << longest_pallindromic_subtring(one) << endl;
    cout << "one:" << one << "\n"
         << "two:" << two << endl;
    cout << LCSubstring(one, two) << endl;
}
