#include <iostream>
#include <bitset>

int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int getSBoxOutput(int input) {
    int row = ((input & 0x20) >> 4) | (input & 0x01);  
    int col = (input & 0x1E) >> 1;  
    
    return S1[row][col];
}

int main() {
    int input;
    
    std::cout << "Enter a 6-bit input (0-63): ";
    std::cin >> input;
    
    if (input < 0 || input > 63) {
        std::cerr << "Invalid input! Please enter a value between 0 and 63." << std::endl;
        return 1;
    }
    
    int output = getSBoxOutput(input);
    
    std::cout << "Input: " << std::bitset<6>(input) << std::endl;
    std::cout << "S-Box Output: " << std::bitset<4>(output) << " (" << output << ")" << std::endl;
    std::cout<<"Name: Kramik Kafle \nRoll No: 104 \nSection: C"<<std::endl;
    
    return 0;
}
