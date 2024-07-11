#include <iostream>
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

int main() {
    unsigned long long n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Invalid input! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::cout << "The Euler's Totient value of " << n << " is " << eulerTotient(n) << std::endl;
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;

    return 0;
}
