#pragma once
#include "Board.h"
#include "Common.h"
#include "function.h"
class Game
{
public:
	Game();
	~Game();
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();
	void startGame();
	bool checkWinRow();
	bool checkWinCol();
	bool checkDiagonal();
private:
	int xMidRect,yMidRect;
    Board _Board;
    int top, left, size;
};
