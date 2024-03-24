#include <iostream>
#include <vector>

using namespace std;

void findSubsets(int index, vector<int>& nums, vector<int>& current, int sum, vector<vector<int>>& result) {
    if (sum == 0) {
        result.push_back(current);
        return;
    }
    if (index == nums.size() || sum < 0) {
        return;
    }

    // Include the current element
    current.push_back(nums[index]);
    findSubsets(index + 1, nums, current, sum - nums[index], result);

    // Exclude the current element (backtrack by removing the last added element)
    current.pop_back();
    findSubsets(index + 1, nums, current, sum, result);
}

vector<vector<int>> subsetSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(0, nums, current, target, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int target = 5;
    vector<vector<int>> subsets = subsetSum(nums, target);

    cout << "Subsets with sum " << target << ":" << endl;
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;
 
// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
 
    vector<bool> prev(sum + 1);
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        prev[0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        prev[i] = false;
 
    // curr array to store the current row result generated
    // with help of prev array
    vector<bool> curr(sum + 1);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                curr[j] = prev[j];
            if (j >= set[i - 1])
                curr[j] = prev[j] || prev[j - set[i - 1]];
        }
        // now curr becomes prev for i+1 th element
        prev = curr;
    }
 
    return prev[sum];
}
 
// Driver code
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}


*/