#include <iostream>
#include <vector>
using namespace std;

void combineHelper(vector<int>& nums, int start, int k, vector<int>& current, vector<vector<int>>& results) {
    if (k == 0) {
        results.push_back(current);
        return;
    }
    for (int i = start; i <= nums.size() - k; ++i) {
        current.push_back(nums[i]);
        combineHelper(nums, i + 1, k - 1, current, results);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);
    vector<vector<int>> results;
    vector<int> current;
    combineHelper(nums, 0, k, current, results);
    return results;
}

int main() {
    int n = 4, k = 2;
    auto combinations = combine(n, k);
    for (auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
