#include <iostream>
#include <unordered_map>
#include <cmath>
unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p) {
    unsigned long long res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long a, unsigned long long p) {
    return power(a, p - 2, p);
}
unsigned long long discreteLogarithm(unsigned long long g, unsigned long long h, unsigned long long p) {
    unsigned long long n = (unsigned long long) sqrt(p) + 1;
    std::unordered_map<unsigned long long, unsigned long long> value;
    for (unsigned long long j = 0; j < n; ++j) {
        value[power(g, j, p)] = j;
    }
    unsigned long long g_inv_n = power(modInverse(g, p), n, p);
    for (unsigned long long i = 0; i < n; ++i) {
        unsigned long long cur = (h * power(g_inv_n, i, p)) % p;
        if (value.count(cur)) {
            return i * n + value[cur];
        }
    }
    return -1; 
}
int main() {
    unsigned long long g, h, p;
    std::cout << "Enter the primitive root (g): ";
    std::cin >> g;
    std::cout << "Enter the number (h): ";
    std::cin >> h;
    std::cout << "Enter the modulo (p): ";
    std::cin >> p;
    if (p <= 0 || g <= 0 || h <= 0) {
        std::cerr << "Invalid input! All values must be positive integers." << std::endl;
        return 1;
    }
    unsigned long long result = discreteLogarithm(g, h, p);
    if (result != -1) {
        std::cout << "The discrete logarithm of " << h << " to the base " << g << " modulo " << p << " is " << result << "." << std::endl;
    } else {
        std::cout << "No discrete logarithm found." << std::endl;
    }
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;
    return 0;
}
