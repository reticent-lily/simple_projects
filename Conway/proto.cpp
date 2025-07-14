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
    
    int start_row {total_row + lip};
    int end_row {min(y) - lip};
    
    int start_column {min(x) - lip};
    int end_column {total_column + lip};

    std::cout << total_column << '\t' << total_row << std::endl;
    for(int r = start_row; r >= end_row; r--) {
        for(int c = start_column; c <= end_column; c++) {

            for(int i = 0; i < x.size(); i++) { // checks if position is in vector
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
