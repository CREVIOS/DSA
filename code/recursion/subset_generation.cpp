#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& set, int index, vector<int>& current, vector<vector<int>>& subsets) {
    if (index >= set.size()) {
        subsets.push_back(current);
        return;
    }
    // Include the current index
    current.push_back(set[index]);
    generateSubsets(set, index + 1, current, subsets);
    // Exclude the current index
    current.pop_back();
    generateSubsets(set, index + 1, current, subsets);
}

int main() {
    vector<int> set;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        set.push_back(a);
    }
    vector<vector<int>> subsets;
    vector<int> current;
    generateSubsets(set, 0, current, subsets);

    for (auto& subset : subsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
