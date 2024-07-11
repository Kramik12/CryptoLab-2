#include <iostream>
#include <vector>
#include <cmath>
#include <set>

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
unsigned long long eulerTotient(unsigned long long n) {
    unsigned long long result = n;
    for (unsigned long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

std::set<unsigned long long> primeFactors(unsigned long long n) {
    std::set<unsigned long long> factors;
    for (unsigned long long p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            factors.insert(p);
            n /= p;
        }
    }
    if (n > 1)
        factors.insert(n);
    return factors;
}

bool isPrimitiveRoot(unsigned long long g, unsigned long long n) {
    unsigned long long phi = eulerTotient(n);
    std::set<unsigned long long> factors = primeFactors(phi);

    for (auto factor : factors) {
        if (power(g, phi / factor, n) == 1)
            return false;
    }
    return true;
}

int main() {
    unsigned long long n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Invalid input! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<unsigned long long> primitiveRoots;
    for (unsigned long long g = 2; g < n; ++g) {
        if (isPrimitiveRoot(g, n))
            primitiveRoots.push_back(g);
    }

    if (primitiveRoots.empty()) {
        std::cout << "No primitive roots found for " << n << "." << std::endl;
    } else {
        std::cout << "Primitive roots of " << n << " are: ";
        for (auto root : primitiveRoots)
            std::cout << root << " ";
        std::cout << std::endl;
    }
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;

    return 0;
}
