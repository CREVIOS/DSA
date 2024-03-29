#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &temp)
{
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}

void makePermutationUtil(
    vector<int> &nums, vector<int> &temp, vector<bool> &used, int k)
{
    if (temp.size() == k)
    {
        print(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!used[i])
        {
            temp.push_back(nums[i]);
            used[i] = true;
            makePermutationUtil(nums, temp, used, k);
            temp.pop_back();
            used[i] = false;
        }
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<bool> used(n, false);
    vector<int> temp;

    for (int i = 0; i < n; ++i)
    {
        nums[i] = i + 1;
    }
    makePermutationUtil(nums, temp, used, k);

    return 0;
}
