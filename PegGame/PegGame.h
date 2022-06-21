#ifndef PEGGAME_H
#define PEGGAME_H

class PegGame {
private:
	int hole;
	bool pegs[15];
	int moveslist[13][2];
	int board[18][3] =
	{ {0,1,3},
	{0,2,5},
	{1,3,6},
	{1,4,8},
	{2,4,7},
	{2,5,9},
	{3,4,5},
	{3,6,10},
	{3,7,12},
	{4,7,11},
	{4,8,13},
	{5,8,12},
	{5,9,14},
	{6,7,8},
	{7,8,9},
	{10,11,12},
	{11,12,13},
	{12,13,14} };
	int num;
public:
	PegGame(int);
	bool moves(int);
	void print();
};

#endif