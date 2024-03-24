#include <iostream>
#include <vector>
using namespace std;

int countLessEqual(const vector<vector<int>>& matrix, int mid) {
    int count = 0;
    int n = matrix.size(), i = n - 1, j = 0;
    while (i >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] <= mid) {
            count += i + 1;
            j++;
        } else {
            i--;
        }
    }
    return count;
}

int kthSmallest(const vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countLessEqual(matrix, mid);
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}
