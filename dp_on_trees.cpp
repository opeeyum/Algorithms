// Problems on DP on trees

// Format of any tree solution will be as follows:
// 1. Base case
// 2. Hypothesis Part -> calling function for left and right subtrees.
// 3. Induction Part -> calculation at the node and the return statement.

// 1. Diameter of a Binary Tree
// 2. Maximum path sum from any node to any node
// 3. Maximum Path sum from leaf to leaf
// 4. Diamerter of N-ary tree.

#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = NULL;
    Node *right = NULL;
};

// Problem statement:
//      For any give tree find its diameter.
//      Diameter -> length of longest path, path may not pass through root
// Algorithm:
//     1. At every node we have to decide whether path with node is answer or the path with its parent is answer.
//     2. We will maintain two variables, res storing the actual answer, and temp whose value will be returned if parent will be the answer.

// Brute Force approach
int heightBT(Node *root)
{
    //  Base case
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 0;

    int h_l = heightBT(root->left);
    int h_r = heightBT(root->right);

    return 1 + max(h_l, h_r);
}

int binary_tree_diameter_brute(Node *root)
{
    // Base case: root is None
    if (!root)
        return 0;

    int curr_max = 0, h_l = 0, h_r = 0;
    if (root->left)
        curr_max += (heightBT(root->left) + 1);
    if (root->right)
        curr_max += (heightBT(root->right) + 1);

    h_l = binary_tree_diameter_brute(root->left);
    h_r = binary_tree_diameter_brute(root->right);
    return max(curr_max, h_l, h_r);
}

int binary_tree_diameter(Node *root, int &res)
{
    // Base case
    if (!root)
        return 0;

    // Hypothesis
    int ld = binary_tree_diameter(root->left, res);
    int rd = binary_tree_diameter(root->right, res);

    // Induction

    // 1. If current node is the answer
    int ans = ld + rd + 1;
    res = max(ans, res);

    // 2. If Parent is the answer
    int temp = max(ld, rd) + 1;
    return temp;
}

// Problem statement:
//      For any give tree find maximum path sum,
//      Path may not pass from root and node may have negative value.
// Algorithm:
//      At every sub tree we have two possibilities, Whether path involves parent or not.
//      For two possibilities we have 1 and 3 cases respectively.
//      Val of node is max.
//      Val of node + val of left child is max.
//      Val of node + val of right child is max.
//      Val of node + val of left + right child is max.
int valueBt(Node *root)
{
    if (!root)
        return INT_MIN;

    int lv = INT_MIN;
    if (root->left)
        lv = valueBt(root->left);
    int rv = INT_MIN;
    if (root->right)
        rv = valueBt(root->right);

    return max(max(lv, rv) + root->val, root->val, lv + rv + root->val);
}
int max_path_sum_brute(Node *root)
{
    // Base case: root is None
    if (!root)
        return 0;

    int h_l = INT_MIN, h_r = INT_MIN;
    h_l = binary_tree_diameter_brute(root->left);
    h_r = binary_tree_diameter_brute(root->right);

    int curr_max = valueBt(root);
    return max(curr_max, h_l, h_r);
}
int solve(Node *root, int &res)
{
    // Base case
    if (!root)
        return 0;

    // Hypothesis
    int lv = solve(root->left, res);
    int rv = solve(root->right, res);

    // Induction
    int topa = max(max(lv, rv) + root->val, root->val);
    int ans = max(topa, lv + rv + root->val);
    res = max(ans, res);
    return topa;
}
int max_path_sum(Node *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}
int main()
{
}
