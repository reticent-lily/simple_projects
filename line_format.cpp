#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile;
    std::ofstream outfile("piss.txt");

    std::string piss;
    int period = 100000, question = 100000, exclamation = 100000;

    infile.open("rep/bee_movie_script.txt");
    //infile.open("blargh.txt");

    std::getline(infile, piss);
    std::cout << piss.length() << std::endl;
    
    while(!piss.empty()) {
        period = piss.find('.');
        question = piss.find('?');
        exclamation = piss.find('!');
        
        
        if(period < question && period < exclamation) {
            std::cout << piss.substr(0,period+2) << std::endl;
            outfile << piss.substr(0,period+2);
            outfile << '\n';
            piss.erase(0,period+2);
        }else if(question < exclamation) {
            std::cout << piss.substr(0,question+2) << std::endl;
            outfile << piss.substr(0,question+2);
            outfile << '\n';
            piss.erase(0,question+2);
        }else{
            std::cout << piss.substr(0,exclamation+2) << std::endl;
            outfile << piss.substr(0,exclamation+2);
            outfile << '\n';
            piss.erase(0,exclamation+2);
        }
    }
        
    std::cout << std::string::npos;
    
    infile.close();
    outfile.close();
}
/*
read the text
separate after each '.'
*/