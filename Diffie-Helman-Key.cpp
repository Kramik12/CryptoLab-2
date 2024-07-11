#include <iostream>
#include <cmath>
#include <cstdlib>
unsigned long long power(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
    unsigned long long p, g, a, b;
    std::cout << "Enter a large prime number (p): ";
    std::cin >> p;
    std::cout << "Enter a primitive root modulo p (g): ";
    std::cin >> g;
    std::cout << "Enter Alice's private key (a): ";
    std::cin >> a;
    std::cout << "Enter Bob's private key (b): ";
    std::cin >> b;
    unsigned long long A = power(g, a, p);
    unsigned long long B = power(g, b, p);
    std::cout << "Alice's public key (A) is: " << A << std::endl;
    std::cout << "Bob's public key (B) is: " << B << std::endl;
    unsigned long long S_Alice = power(B, a, p);
    unsigned long long S_Bob = power(A, b, p);
    std::cout << "Alice's computed shared secret (S) is: " << S_Alice << std::endl;
    std::cout << "Bob's computed shared secret (S) is: " << S_Bob << std::endl;
    if (S_Alice == S_Bob) {
        std::cout << "Key exchange successful. Shared secret is: " << S_Alice << std::endl;
    } else {
        std::cout << "Key exchange failed. Shared secrets do not match." << std::endl;
    }
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;
    return 0;
}
