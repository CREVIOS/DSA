#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

// Function to convert a hexadecimal string to an integer
unsigned int hexToDec(const std::string& hexStr) {
    unsigned int result;
    std::stringstream ss;
    ss << std::hex << hexStr;
    ss >> result;
    return result;
}

int main() {
    // Vector of hexadecimal numbers as strings
    std::vector<std::string> hexNumbers = {"1A", "2F", "3E", "10", "B", "F"};

    // Sort using a custom comparator
    std::sort(hexNumbers.begin(), hexNumbers.end(), [](const std::string& a, const std::string& b) {
        return hexToDec(a) < hexToDec(b);
    });

    // Print the sorted hex numbers
    std::cout << "Sorted Hexadecimal Numbers:" << std::endl;
    for (const auto& num : hexNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
