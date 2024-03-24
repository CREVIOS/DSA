#include <iostream>
#include <vector>
using namespace std;
int findRotationCount(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findRotationCount(nums) << endl;
    return 0;
}
