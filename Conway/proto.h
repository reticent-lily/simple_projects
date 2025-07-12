#ifndef CONWAY_SIGNATURES
#define CONWAY_SIGNATURES
#include <iostream>
#include <vector>
#include <cmath>

void print_game_state(std::vector<int> x, std::vector<int> y, int lip); // prints game board

void update_game_state(std::vector<int> x, std::vector<int> y);
// deletes dead vectors then add new ones
// use temp vector?
void check_if_dead(std::vector<int> x, std::vector<int> y); // self-explanatory

int average_vector(std::vector<int> numbers);

int max(std::vector<int> vec);
int min(std::vector<int> vec);

#endif