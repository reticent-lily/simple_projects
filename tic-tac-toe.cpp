//tic-tac-toe2.cpp
#include <iostream>
#include <array>
#include <string>

#include <cstdlib>


//returns array index given a move
// rework into take_space function --> will be used to check if the space is available, and take it
int get_move();
//self-explanatory
void print_board(std::array<int,9> ar);

bool validMove(std::array<int, 9>& ar, int move, bool turn);
bool check_gaming(std::array<int, 9> ar, bool turn);

/*
ply1 - bool representing the turn
true = player 1 turn (x)
false = player 2 turn (o)


*/

int main() {
    bool gaming = true, ply1;
    srand(0);
    ply1 = rand() %2 == 0;
    std::array<int, 9> game_state = {0, 0, 0,
                                    0, 0, 0,
                                    0, 0, 0};
    //print game board
    std::cout << " tl | tm | tr" << std::endl
              << "=============" << std::endl
              << " ml | mm | mr" << std::endl
              << "=============" << std::endl
              << " bl | bm | br" << std::endl;
    
    int move;
    while(gaming) {
        move = get_move();
        if(validMove(game_state, move, ply1)) {
            gaming = check_gaming(game_state,ply1);
            print_board(game_state);
            ply1 = !ply1;
        }else {
            std::cout << "space is occupied" << std::endl;
        }

        //std::cout << move << '\n';
        
    }

    std::cout << "game over, ";
    if(ply1) {
        std::cout << "player 1(X) wins!" << std::endl;
    }else{
        std::cout << "player 2(O) wins!" << std::endl;
    }
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
        default:
            std::cout << "invalid move" << '\n';
            return -1;
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
        default:
            std::cout << "invalid move" << '\n';
            return -1;
        break;
    }
    /*
    if ar[move] == 1 || 2 return invalid
    else if move == 0
     ar[move] = ply1 ? 1 : 2
    */

    return index;
}

bool validMove(std::array<int, 9>& ar, int move, bool turn) {
    if(ar[move] == 0) {
        if(turn) {
            ar[move] = 1;
        }else{
            ar[move] = 2;
        }
        return true;
    }else{
        
        return false;
    }
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

//true = game over, false = game ongoing
bool check_gaming(std::array<int, 9> ar, bool turn) {
    int bit = turn ? 1 : 2;

    // check horizontal
    for(int i = 0; i <= 6; i+=3) {
        if(ar[i] == bit && ar[i+1] == bit && ar[i+2] == bit)
            return false;
    }

    //check vertical
    for(int i = 0; i <= 2; i++) {
        if(ar[i] == bit && ar[i+3] == bit && ar[i+6] == bit)
            return false;
    }

    // check diagonal
    if(ar[0] == bit && ar[4] == bit && ar[8] == bit)
        return false;

    if(ar[2] == bit && ar[4] == bit && ar[6] == bit)
        return false;

    return true;
}

/*
2 players

 0 | 1 | 2
===========
 3 | 4 | 5
===========
 6 | 7 | 8

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
