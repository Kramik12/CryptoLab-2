#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void encrypt(int plaintext, int p, int g, int y, int& c1, int& c2) {
    int k = rand() % (p - 1) + 1; 
    c1 = modExp(g, k, p);
    c2 = (modExp(y, k, p) * plaintext) % p;
}
int decrypt(int c1, int c2, int p, int x) {
    int s = modExp(c1, x, p);
    int s_inv = modExp(s, p - 2, p); 
    return (c2 * s_inv) % p;
}
int main() {
    int p, g, x, y;
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter a base g (generator): ";
    cin >> g;
    cout << "Enter your private key x (1 < x < p): ";
    cin >> x;
    y = modExp(g, x, p);
    cout << "Public Key: (p, g, y) = (" << p << ", " << g << ", " << y << ")" << endl;
    cout << "Private Key: x = " << x << endl;
    int plaintext;
    cout << "Enter an integer plaintext message (0 < plaintext < p): ";
    cin >> plaintext;
    int c1, c2;
    encrypt(plaintext, p, g, y, c1, c2);
    cout << "Encrypted message: (c1, c2) = (" << c1 << ", " << c2 << ")" << endl;
    int decryptedMessage = decrypt(c1, c2, p, x);
    cout << "Decrypted message: " << decryptedMessage << endl;
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;
    return 0;
}
