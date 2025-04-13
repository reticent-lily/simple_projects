#include <iostream>
using namespace std;

void print_gstate();

int game_state[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};

int main() {	
	print_gstate();
}

//0 for nil 1 for O 2 for X
// game_state[i][j]

void print_gstate() {
	cout << endl << "=============" <<  endl;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			
			if(game_state[i][j] == 0) {
				//prinnt dir.
				if(i == 0) {
					cout << 't';
				}else if(i == 1) {
					cout << 'm';
				}else if(i == 2) {
					cout << 'b';
				}
				
				if(j == 0) {
					cout << 'l';
				}else if(j == 1) {
					cout << 'm';
				}else if(j == 2) {
					cout << 'r';
				}
				cout << ' ';
				
			}else if(game_state[i][j] == 1) {
				//print O
			}else if(game_state[i][j] == 2) {
				//print X
			}
			if(j != 2) {
				cout << "| ";	
			}
		}
		//next line
		cout << endl;
	}
	cout << "=============" << endl;
}

/*
 * Directions
 *	tl | tm | tr
 *	ml | mm | mr
 *	bl | bm | br
 *
 *	t - top
 *	m - middle
 *	b - bottom
 *	l/m/r = left/middle/right
 */
