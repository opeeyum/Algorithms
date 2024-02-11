def LCSubsequence_recursive(string_one, string_two, n, m, memo):
    # Base Condition
    if n == 0 or m == 0:
        return 0
    if memo[n][m] != -1:
        return memo[n][m]
    # Choice diagram
    if string_one[n - 1] == string_two[m - 1]:
        # PICK
        memo[n][m] = 1 + LCSubsequence_recursive(
            string_one, string_two, n - 1, m - 1, memo
        )
    else:
        # NOT PICK
        memo[n][m] = max(
            LCSubsequence_recursive(string_one, string_two, n - 1, m, memo),
            LCSubsequence_recursive(string_one, string_two, n, m - 1, memo),
        )
    return memo[n][m]


def LCSubsequence_tabulated(first, second):
    n = len(first)
    m = len(second)
    memo = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if first[i - 1] == second[j - 1]:
                memo[i][j] = 1 + memo[i - 1][j - 1]
            else:
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1])
    return memo[n][m]


# -------------Problem Variations-----------------------


# 1. Print LCS -> Backtrack the sequence
def LCSubsequence(first, second):
    n = len(first)
    m = len(second)
    memo = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if first[i - 1] == second[j - 1]:
                memo[i][j] = 1 + memo[i - 1][j - 1]
            else:
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1])
    ans = ""
    while n > 0 and m > 0:
        if first[n - 1] == second[m - 1]:
            ans += first[n - 1]
            n -= 1
            m -= 1
        elif memo[n - 1][m] > memo[n][m - 1]:
            n -= 1
        else:
            m -= 1
    return ans[::-1]


# 2. Largest Pallindromic Subsequence -> find lcs(str, reverse(str));
# 3. Subsequence Pattern Matching | Check whether given string "a" is subseqence of "b" or not
# -> len(lcs(a, b)) == len(a);
# 4. Min number of insertion and deletion to make string a == string b.
# -> deletion = str1.length - lcs.length, insertion = str2.length - lcs.length
# 5. Min number of deletion in a string to make it a pallindrome.
# -> str.length - lcs(str, reverse(str));
# 6. Min number of insertion in a string to make it a pallindrome.
# -> str.length - lcs(str, reverse(str));

# 7. Length Shortest Common SuperSequence
# -> str1.length + str2.length - lcs.length;
# 8. Print SCS
# -> While printing the lcs we only involve charactre present in both string here we also take characters when doesn't match.


# 9. Largest common Substring
def LCSubstring(first, second):
    n = len(first)
    m = len(second)
    memo = [[0] * (m + 1) for _ in range(n + 1)]
    max_len = 0
    end_index = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if first[i - 1] == second[j - 1]:
                memo[i][j] = 1 + memo[i - 1][j - 1]
                if memo[i][j] > max_len:
                    max_len = memo[i][j]
                    end_index = i - 1

    ans = first[end_index - max_len + 1 : end_index + 1]
    return ans


# 10. Largest repeating subsequence
# lcs(str, str) where memo[i-1] == memo[j-1] && i != j
# 11. Length of largest subsequence of a which is a substring is b.

# 12. Count How many times a appear as subsequence in b.
# 13. Largest Pallindromic Substring
# lcs(str, str[::-1])


def longest_pallindromic_subtring(one):
    n = len(one)
    memo = [[0] * n for _ in range(n)]
    start_ind = 0
    max_len = 1
    for r in range(n):
        memo[r][r] = 1
    for r in range(n - 1):
        if one[r] == one[r + 1]:
            memo[r][r + 1] = 1
            start_ind = r
            max_len = 2
    for k in range(3, n + 1):
        for r in range(n - k + 1):
            c = r + k - 1
            if one[r] == one[c] and memo[r + 1][c - 1] == 1:
                memo[r][c] = 1
                if k > max_len:
                    start_ind = r
                    max_len = k
    ans = one[start_ind : start_ind + max_len]
    return ans


# 14. Count Pallindromic Substring

if __name__ == "__main__":
    one = "1235986"
    two = "12345986"
    # print(longest_pallindromic_subtring(one))
    print("one:", one)
    print("two:", two)
    print(LCSubstring(one, two))
