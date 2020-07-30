#pragma once
#include"coordinate.h"
#include"function.h"
#include"Common.h"
class Board
{
private:
	int size;
	int left, top;
	Coordinate** B;
public:
	Board();
	Board& operator =(Board&);
	Board(int, int, int);
	~Board();
	void setStausAt(int, int, int);
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	int getStatusAt(int, int);
	void resetData();
	int testBoard(int, int);
	void drawBoard();
	void userBoard_1();
	void userBoard_2();
};

