#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& answer) {
    answer.push_back(current);
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i-1]) continue; // skip duplicates
        current.push_back(nums[i]);
        findSubsets(i + 1, nums, current, answer);
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sort to handle duplicates
    vector<vector<int>> answer;
    vector<int> current;
    findSubsets(0, nums, current, answer);
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 2};
    auto result = subsetsWithDup(nums);
    for (auto& subset : result) {
        for (int elem : subset) {
            cout << elem << " ";
        }
        cout << "\n";
    }
    return 0;
}
