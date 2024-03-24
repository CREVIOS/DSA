#include <iostream>
#include <vector>

std::vector<int> mergeSortedArrays(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C) {
    std::vector<int> result;
    int i = 0, j = 0, k = 0;

    while (i < A.size() && j < B.size() && k < C.size()) {
        if (A[i] <= B[j] && A[i] <= C[k]) {
            result.push_back(A[i++]);
        } else if (B[j] <= A[i] && B[j] <= C[k]) {
            result.push_back(B[j++]);
        } else {
            result.push_back(C[k++]);
        }
    }

    while (i < A.size()) {
        result.push_back(A[i++]);
    }

    while (j < B.size()) {
        result.push_back(B[j++]);
    }

    while (k < C.size()) {
        result.push_back(C[k++]);
    }

    return result;
}

int main() {
    // Example usage:
    // Assume A, B, C are already sorted
    std::vector<int> A = {1, 3, 3,5,5,11,15};
    std::vector<int> B = {2, 4, 6, 9};
    std::vector<int> C = {0, 1, 2, 3};

    std::vector<int> combined = mergeSortedArrays(A, B, C);

    for (int num : combined) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
