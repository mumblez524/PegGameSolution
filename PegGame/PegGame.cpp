#include "PegGame.h"
#include <iostream>

using namespace std;

PegGame::PegGame(int h) {
	hole = h;
	num = 12;
	for (int i = 0; i < 15; i++) {
		if (i == hole)
			pegs[i] = false;
		else
			pegs[i] = true;
	}

	moves(14);
}

bool PegGame::moves(int remaining) {
	bool success;
	int move[2];
	if (remaining == 1)
		return true;

	for (int i = 0; i < 18; i++) {

		if (pegs[board[i][0]] == false && pegs[board[i][1]] == true && pegs[board[i][2]] == true) {
			move[0] = board[i][2];
			move[1] = board[i][0];
			pegs[board[i][0]] = true;
			pegs[board[i][1]] = false;
			pegs[board[i][2]] = false;
			success = moves(remaining - 1);
			if (success) {
				moveslist[num][0] = move[0];
				moveslist[num][1] = move[1];
				num--;
				return true;
			}
			pegs[board[i][0]] = false;
			pegs[board[i][1]] = true;
			pegs[board[i][2]] = true;
		}
		if (pegs[board[i][0]] == true && pegs[board[i][1]] == true && pegs[board[i][2]] == false) {
			move[0] = board[i][0];
			move[1] = board[i][2];
			pegs[board[i][0]] = false;
			pegs[board[i][1]] = false;
			pegs[board[i][2]] = true;
			success = moves(remaining - 1);
			if (success) {
				moveslist[num][0] = move[0];
				moveslist[num][1] = move[1];
				num--;
				return true;
			}
			pegs[board[i][0]] = true;
			pegs[board[i][1]] = true;
			pegs[board[i][2]] = false;
		}
	}
	return false;
}

void PegGame::print() {
	for (int i = 0; i < 13; i++) {
		cout << "Jump from peg hole " << moveslist[i][0] << " to peg hole " << moveslist[i][1] << endl;
	}
}