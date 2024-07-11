#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}
int encrypt(int plaintext, int e, int n) {
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}
int decrypt(int ciphertext, int d, int n) {
    int plaintext = 1;
    for (int i = 0; i < d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    int p, q, n, phi, e, d;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    cout << "Enter an integer e such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
    cin >> e;
    while (gcd(e, phi) != 1) {
        cout << "Invalid e. Enter another integer e: ";
        cin >> e;
    }
    d = modInverse(e, phi);
    if (d == -1) {
        cout << "No modular inverse found. Exiting.";
        return 1;
    }
    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;
    int plaintext;
    cout << "Enter an integer plaintext (0 < plaintext < " << n << "): ";
    cin >> plaintext;
    while (plaintext <= 0 || plaintext >= n) {
        cout << "Invalid plaintext. Enter another integer plaintext: ";
        cin >> plaintext;
    }
    int ciphertext = encrypt(plaintext, e, n);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    int decryptedText = decrypt(ciphertext, d, n);
    cout << "Decrypted plaintext: " << decryptedText << endl;
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;
    return 0;
}
