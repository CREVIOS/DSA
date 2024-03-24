#include<bits/stdc++.h>

const int MAX = 10000; // maximum value after adjusting for precision

std::vector<float> countingSortFloating(std::vector<float>& arr) {
    // Convert to positive and scale up float numbers for counting sort
    std::vector<int> scaledNumbers(arr.size());
    int minVal = INT_MAX;

    for (int i = 0; i < arr.size(); ++i) {
        scaledNumbers[i] = static_cast<int>((arr[i] + 1.0) * MAX); // +1.0 to handle negative numbers
        minVal = std::min(minVal, scaledNumbers[i]);
    }
    

    // Apply counting sort on scaled numbers
    std::vector<int> count(2 * MAX + 1, 0); // Count array to cover negative values

    for (int num : scaledNumbers) {
        count[num - minVal]++; // Normalize to start at index 0
    }

    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1]; // Cumulative count
    }

    std::vector<int> output(scaledNumbers.size());
    for (int i = scaledNumbers.size() - 1; i >= 0; --i) {
        output[--count[scaledNumbers[i] - minVal]] = scaledNumbers[i];
    }

    // Convert back to original scale
    std::vector<float> sortedArr(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        sortedArr[i] = static_cast<float>(output[i]) / MAX - 1.0; // Revert scaling and offset
    }

    return sortedArr;
}

int main() {
    std::vector<float> numbers = {0.4458, -0.6651, 0.2222, 0.919, -0.4651, 0.4534};

    std::vector<float> sortedNumbers = countingSortFloating(numbers);

    for (float num : sortedNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
