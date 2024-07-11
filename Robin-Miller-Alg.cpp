#include <iostream>
#include <cstdlib>
#include <ctime>

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

bool millerTest(unsigned long long d, unsigned long long n) {
    unsigned long long a = 2 + rand() % (n - 4);

    unsigned long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    // Return composite
    return false;
}

bool isPrime(unsigned long long n, int k) {
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    unsigned long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {
    srand(time(0)); 
    unsigned long long n;
    int k = 4; 

    std::cout << "Enter the number to be tested for primality: ";
    std::cin >> n;

    if (isPrime(n, k))
        std::cout << n << " is probably a prime number." << std::endl;
    else
        std::cout << n << " is a composite number." << std::endl;
        std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;

    return 0;
}
