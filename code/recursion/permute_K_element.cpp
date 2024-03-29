#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

void generatePermutations(vector<int>& nums, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        vector<int> temp = current; // Make a copy of current to permute
        sort(temp.begin(), temp.end()); // Ensure it's sorted before generating permutations
        do {
            result.push_back(temp);
        } while (next_permutation(temp.begin(), temp.end()));
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        generatePermutations(nums, k, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationsPermutations(vector<int>& nums, int k) {
    vector<vector<int>> result;
    vector<int> current;
    generatePermutations(nums, k, 0, current, result);
    // Sort the entire result to ensure permutations are in ascending order
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4}; // Ensure nums is sorted
    int k = 3;

    vector<vector<int>> result = combinationsPermutations(nums, k);

    for (const auto& perm : result) {
        printVector(perm);
    }

    return 0;
}
