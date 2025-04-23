//string-to-binary.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <array>

std::array<int, 8> char2Byte(char c);
void printByte(std::array<int, 8> byt);

int main() {
    std::string line {};
    getline(std::cin, line);

    for(int i = 0; i < line.length(); i++) {
        printByte(char2Byte(line[i]));
        std::cout << ' ';
    }
    
    std::cout << '\n';
}

std::array<int, 8> char2Byte(char c) {
    std::array<int, 8> byt {};
    int dec {static_cast<int>(c)};
    for(int i = 0; i < 8; i++) {
        int power = 7 - i;
        if(pow(2, power) <= dec) {
            dec -= pow(2, power);
            byt[i] = 1;
        }else{
            byt[i] = 0;
        }
    }
    return byt;
}

void printByte(std::array<int, 8> byt) {
    std::string out {};
    for(int i = 0; i < byt.size(); i++) { 
        int bit = byt[i];
        if(bit == 1)
            out += '1';
        else
            out += '0';
    }
    std::cout << out;
}
