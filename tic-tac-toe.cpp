//tic-tac-toe2.cpp
#include <iostream>
#include <array>
#include <string>

//returns array index given a move
int get_move();
//self-explanatory
void print_board(std::array<int,9> ar);

/*
ply1 - bool representing the turn
true = player 1 turn (x)
false = player 2 turn (o)


*/

int main() {
    bool gaming = true, ply1 = true;

    std::array<int, 9> game_state = {0, 0, 0,
                                    0, 0, 0,
                                    0, 0, 0};
    
    int d;
    while(gaming) {
        d = get_move();
        std::cout << d << '\n';
    }

    std::cout << '\n';
    print_board(game_state);
}

//change to take_space
int get_move() {
    int index = 0;
    char row, col;
    std::string move;
    std::cin >> move;

    if(move.size() != 2) {
        std::cout << "invalid move" << '\n';
        return -1;
    }else if(move[0] != 't' && move[0] != 'm' && move[0] != 'b') {
        std::cout << "invalid move" << '\n';
        return -1;
    }else if(move[1] != 'l' && move[1] != 'm' && move[1] != 'r') {
        std::cout << "invalid move" << '\n';
        return -1;
    }
    switch (move[0]) {
        case 't':
        break;
        case 'm':
        index+=3;
        break;
        case 'b':
        index+=6;
        break;
    }

    switch (move[1]) {
        case 'l':
        break;
        case 'm':
        index+=1;
        break;
        case 'r':
        index+=2;
        break;
    }
    /*
    if ar[move] == 1 || 2 return invalid
    else if move == 0
     ar[move] = ply1 ? 1 : 2
    */

    return index;
}

void print_board(std::array<int,9> ar) {
    char pl;
    for(int i = 0;i < ar.size(); i++) {
        if(ar[i] == 0)
            pl = '_';
        else if(ar[i] == 1)
            pl = 'X';
        else if(ar[i] == 2)
            pl = 'O';
        
        std::cout << ' ' << pl << ' ';
        if(i % 3 == 2) {
            std::cout << std::endl;
        }else{
            std::cout << '|';
        }
    }
}
/*
2 players



 0 | 0 | 0
===========
 0 | 0 | 0
===========
 0 | 0 | 0

 tl | tm | tr
=============
 ml | mm | mr
=============
 bl | bm | br
*/
