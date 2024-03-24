#include <iostream>
#include <cmath>
using namespace std;

double nthRoot(int n, double x, double tol = 1e-6) {
    double low, high, guess;
    
    if (x >= 1) {
        low = 0;
        high = x;
    } else {
        low = x;
        high = 1;
    }

    while (high - low > tol) {
        guess = low + (high - low) / 2;
        if (pow(guess, n) < x) {
            low = guess;
        } else {
            high = guess;
        }
    }
    
    return (low + high) / 2;
}

int main() {
    int n = 3; 
    double x = 8; 
    cout.precision(12); 
    cout <<  nthRoot(n, x) << "." << endl;
    return 0;
}
