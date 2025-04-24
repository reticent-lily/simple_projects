#include <iostream>
#include <string>

int main() {
    std::string line {};
    getline(std::cin, line);
    std::cout << (int)((unsigned char) 'h') << std::endl;
    
    for(int i = 0; i < line.length(); i++) { // iterates through every char
        int asci = (int)((unsigned char) line[i]);

        for(int j = 7; j >= 0; j--) { // prints the byte of char

            if((int)(1 << j) > asci) {
                std::cout << '0';
            }else{
                asci -= (int)(1 << j);
                std::cout << '1';
            }
            
        }

        std::cout << ' '; 
    }

    std::cout << '\n';
}