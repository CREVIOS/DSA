#include <iostream>
#include <cmath>

double f(double x, double a, double b, double c, double d) {
    // Cubic equation
    return a*x*x*x + b*x*x + c*x + d;
}

double df(double x, double a, double b, double c) {
    // Derivative of the cubic equation
    return 3*a*x*x + 2*b*x + c;
}

double binarySearchForStartingPoint(double a, double b, double c, double d, double start, double end, double tolerance) {
    double mid;
    while (start <= end) {
        mid = (start + end) / 2;
        double value = f(mid, a, b, c, d);
        
        if (std::abs(value) < tolerance) {
            return mid;
        } else if (value > 0) {
            end = mid - tolerance;
        } else {
            start = mid + tolerance;
        }
    }
    return mid;
}

double newtonRaphson(double initialGuess, double a, double b, double c, double d, double tolerance) {
    double x = initialGuess;
    double h = f(x, a, b, c, d) / df(x, a, b, c);

    while (std::abs(h) >= tolerance) {
        h = f(x, a, b, c, d) / df(x, a, b, c);
        x = x - h;
    }

    return x;
}

int main() {
    double a, b, c, d;
    std::cout << "Enter coefficients a, b, c, and d: ";
    std::cin >> a >> b >> c >> d;

    double start = -100.0, end = 100.0; // Adjust these values as necessary.
    double tolerance = 0.0001; // Adjust the tolerance as needed.

    // First, use binary search to find a good starting point.
    double initialGuess = binarySearchForStartingPoint(a, b, c, d, start, end, tolerance);
    
    // Then, use Newton-Raphson method to refine the root.
    double root = newtonRaphson(initialGuess, a, b, c, d, tolerance);
    std::cout << "A root of the equation is approximately: " << root << std::endl;

    return 0;
}
