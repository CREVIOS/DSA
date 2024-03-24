#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid1 = (low + high) / 2;
        int mid2 = mid1 + 1;
        if (nums[mid1] < nums[mid2]) {
            low = mid2;
        } else {
            high = mid1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout <<findPeakElement(nums) << endl;
    return 0;
}
