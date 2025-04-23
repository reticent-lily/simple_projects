// a program to format plain text files w/ whole text blocks
#include <iostream>
#include <string>
#include <fstream>

int check_ellipses(std::string str, int period);
int main() {
    //[[maybe_unused]] const double gravity {9.6};

    std::ifstream infile;
    std::ofstream outfile("form_text.txt");
    std::string form_str {}; // holds all of infile
    std::string temp{}; // holds infile text to be pushed

    infile.open("bee_movie_script.txt");
    std::getline(infile, form_str);

    while(!form_str.empty()) {
        int period = form_str.find('.');
        int question = form_str.find('?');
        int exclamation = form_str.find('!');

        if(question != std::string::npos || exclamation != std::string::npos) {
            if(question < period && question < exclamation) {
                temp = form_str.substr(0, question + 2);
                form_str.erase(0, question + 2);
                outfile << temp << '\n';
                continue;
            }
            if(exclamation < period && exclamation < question) {
                temp = form_str.substr(0, exclamation + 2);
                form_str.erase(0, exclamation + 2);
                outfile << temp << '\n';
                continue;
            }
        }

        temp = form_str.substr(0, period + check_ellipses(form_str, period) + 1);
        form_str.erase(0, period + check_ellipses(form_str, period) + 1);
        outfile << temp << '\n';
        std::cout << temp << std::endl;
    }

    //std::cout << form_str.length() << std::endl;
    //std::cout << check_ellipses(form_str, 0) << std::endl;

    infile.close();
    outfile.close();
}

// a function to check for ellipses
int check_ellipses(std::string str, int period) {
    int end {1};
    while(str.length()  >= (period + end) && str[period + end] == '.'){
        if(str[period + end] == '.')
            end++;
    }
    
    return end;
    //d
}



/*
find
substr
erase, erase(pos, n)
empty ?
swap
insert(pos, str)
*/
