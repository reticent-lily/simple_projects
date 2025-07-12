
#include "proto.h"

int min(std::vector<int> vec) {
    int min = {vec[0]};
    for(int i = 0; i < vec.size(); i++) {
        if(min > vec[i])
            min = vec[i];
    }
    return min;
}

int max(std::vector<int> vec) {
    int max = {vec[0]};
    for(int i = 0; i < vec.size(); i++) {
        if(max < vec[i])
            max = vec[i];
    }
    return max;
}


void print_game_state(std::vector<int> x, std::vector<int> y, int lip) {
    int total_column { abs(max(x) - min(x)) };
    int total_row { abs(max(y) - min(y)) };
    
    std::cout << total_column << '\t' << total_row << std::endl;
    for(int r = total_row; r >= min(y); r--) {
        for(int c = min(x); c <= total_column; c++) {

            for(int i = 0; i < x.size(); i++) {
                if(x[i] == c && y[i] == r) {
                    std::cout << "X" << ' ';
                    //std::cout << "X" << '[' << c << r << ']' << '\t';
                    break;
                }
                if(i == x.size() - 1) {
                    std::cout << "O" << ' ';
                    //std::cout << "O" << '[' << c << r << ']' << '\t';
                }
            }
            
        }
        std::cout << '\n';
    }

    // printing order, left to right, top to bottom
    // x - column |
    // y - row ---
    // x should be increasing from the minimum
    // y should be decreasing for its maximum
}