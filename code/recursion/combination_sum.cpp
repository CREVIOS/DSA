#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& results) {
    if (target == 0) {
        results.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
        current.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], i, current, results);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<vector<int>> results;
    vector<int> current;
    combinationSumHelper(candidates, target, 0, current, results);
    return results;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto combinations = combinationSum(candidates, target);

    // Display the combinations
    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
