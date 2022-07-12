#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_all_subsequence(vector<int> &nums, vector<int> &temp, int ind = 0)
{
    if (ind == nums.size())
    {
        for (auto val : temp)
            cout << val << " ";
        cout << endl;
        return;
    }
    // Pick the element
    temp.push_back(nums[ind]);
    print_all_subsequence(nums, temp, ind + 1);

    // Not pick the element
    temp.pop_back();
    print_all_subsequence(nums, temp, ind + 1);
}
void subsequence_with_given_sum(vector<int> &nums, vector<int> &temp, int target, int ind = 0)
{
    if (target == 0)
    {
        for (auto val : temp)
            cout << val << " ";
        cout << endl;
        return;
    }
    if (ind == nums.size())
        return;
    // Pick the element
    temp.push_back(nums[ind]);
    subsequence_with_given_sum(nums, temp, target - nums[ind], ind + 1);

    // Not pick the element
    temp.pop_back();
    subsequence_with_given_sum(nums, temp, target, ind + 1);
}
void get_all_sub_set_sum(vector<int> &nums, multiset<int> &ans, int sum = 0, int ind = 0)
{
    if (ind == nums.size())
    {
        ans.insert(sum);
        return;
    }

    get_all_sub_set_sum(nums, ans, sum + nums[ind], ind + 1);
    get_all_sub_set_sum(nums, ans, sum, ind + 1);
}
void get_all_permutation_using_map(vector<int> &nums, vector<vector<int>> &ans2, vector<int> &map, vector<int> &ds, int ind = 0)
{
    if (ind == nums.size())
    {
        ans2.push_back(ds);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        map[i] = 1;
        for (int j = ind; j < map.size(); j++)
        {
            if (map[j])
                ds.push_back(nums[j]);
        }
        get_all_permutation_using_map(nums, ans2, map, ds, ind + 1);
        map[i] = 0;
    }
}
void get_all_permutations(vector<int> &nums, vector<vector<int>> &ans2, int ind = 0)
{
    if (ind == nums.size())
    {
        ans2.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[i], nums[ind]);
        get_all_permutations(nums, ans2, ind + 1);
        swap(nums[i], nums[ind]);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> temp;
    multiset<int> ans;
    // print_all_subsequence(nums, temp);
    // subsequence_with_given_sum(nums, temp, 5);
    // get_all_sub_set_sum(nums, ans);
    // for (auto i : ans)
    //     cout << i << " ";
    // cout << "\n";
    vector<vector<int>> ans2;
    get_all_permutations(nums, ans2);
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[i].size(); j++)
            cout << ans2[i][j] << " ";
        cout << endl;
    }

    return 0;
}