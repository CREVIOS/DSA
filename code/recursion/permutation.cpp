#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& nums, int l, int r, vector<vector<int>>& perms) {
    if (l == r) {
        perms.push_back(nums);
    } else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, l + 1, r, perms);
            swap(nums[l], nums[i]); // backtrack
        }
    }
}

int main() {
    vector<int> nums ;
     int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<vector<int>> perms;
    permute(nums, 0, nums.size() - 1, perms);

    for (auto& perm : perms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
