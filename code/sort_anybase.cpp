#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

// Function to convert a number from any base to decimal
unsigned long long baseToDec(const std::string& number, int base) {
    unsigned long long value = 0;
    int length = number.length();

    for (int i = 0; i < length; i++) {
        char digit = number[i];
        int digitValue;

        if (digit >= '0' && digit <= '9') {
            digitValue = digit - '0';
        } else if (digit >= 'A' && digit <= 'Z') {
            digitValue = 10 + digit - 'A';
        } else if (digit >= 'a' && digit <= 'z') {
            digitValue = 10 + digit - 'a';
        } else {
            continue; // Skip invalid characters
        }

        if (digitValue >= base) {
            throw std::invalid_argument("Invalid number for the specified base");
        }

        value += digitValue * std::pow(base, length - i - 1);
    }

    return value;
}

int main() {
    // Vector of numbers as strings along with their base
    std::vector<std::pair<std::string, int>> numbers = {
        {"1010", 2},  // Binary
        {"F", 16},    // Hexadecimal
        {"10", 10},   // Decimal
        {"7", 8},     // Octal
        {"Z", 36}     // Base36
    };

    // Sort using a custom comparator
    std::sort(numbers.begin(), numbers.end(), [](const auto& a, const auto& b) {
        return baseToDec(a.first, a.second) < baseToDec(b.first, b.second);
    });

    // Print the sorted numbers
    std::cout << "Sorted Numbers:" << std::endl;
    for (const auto& pair : numbers) {
        std::cout << "Base " << pair.second << ": " << pair.first << std::endl;
    }

    return 0;
}
