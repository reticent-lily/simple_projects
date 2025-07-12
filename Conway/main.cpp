#include <iostream>
#include <vector>
#include <cmath>
#include "proto.h"


int main() {
    enum game_state {
        PLAYING,
        ENDED
    } state;
    state = ENDED;


    //x = rows, y = columns
    std::vector<int> x;
    std::vector<int> y;

    /* basic diagonal movement downwards
    0 1 0
    0 0 1
    1 1 1
    
    how to organize arrays
    list based on x

    */
   std::cout << "hello" << '\n';
    x = {0, 1, 2, 2, 1}; //bottom up, left to right
    y = {0, 0, 0, 1, 2};
    
    print_game_state(x, y, 1);

    return 0;
}

int average_vector(std::vector<int> numbers) {
    int total = {0};
    for(int i = 0; i < numbers.size(); i++)
        total = numbers[i] + total;
    total /= numbers.size();
    return total;
}
// make separate functions for each rule?