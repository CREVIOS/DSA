#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;
    return 0;
}
