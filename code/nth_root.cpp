#include <iostream>
#include <cmath>

double nthRoot(double x, int n, double precision = 1e-7) {
    double low, high;
    if (x >= 1) {
        low = 1;
        high = x;
    } else {
        low = x;
        high = 1;
    }

    while (high - low > precision) {
        double mid = (low + high) / 2;
        double midNthPower = pow(mid, n);

        if (midNthPower > x) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return (low + high) / 2;
}

int main() {
    double x;
    int n;

   
    std::cin >> x;
 
    std::cin >> n;

    double nth_root = nthRoot(x, n);
    std::cout << "The " << n << "th root of " << x << " is approximately: " << nth_root << std::endl;

    return 0;
}
