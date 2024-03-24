#include <iostream>
#include <vector>
#include <algorithm>

double findMedian(const std::vector<int>& arr, int X, int Y) {
    std::vector<int> subArray(arr.begin() + X, arr.begin() + Y + 1);
    std::sort(subArray.begin(), subArray.end());
    int n = subArray.size();
    if (n % 2 == 0) {
        return (subArray[n/2 - 1] + subArray[n/2]) / 2.0;
    } else {
        return subArray[n/2];
    }
}

int main() {
    // Example array
    std::vector<int> A = {2, 1, 5, 7, 2, 0, 5}; // The array of integers

    // Example queries
    std::vector<std::pair<int, int>> queries = {{1, 3}, {2, 5}, {0, 6}};

    // Process queries
    for (const auto& query : queries) {
        int X = query.first;
        int Y = query.second;
        std::cout << "The median of the sub-array from " << X << " to " << Y << " is: " << findMedian(A, X, Y) << std::endl;
    }

    return 0;
}
