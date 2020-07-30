#include "Board.h"
#include<iostream>
using namespace std;

Board::Board() {
	size = 20;
	left = 0;
	top = 0;
	B = new Coordinate * [size];
	for (int i = 0; i < size; i++) B[i] = new Coordinate[size];
}
Board::Board(int pSize, int pX, int pY) {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
	size = pSize;
	left = pX;
	top = pY;
	B = new Coordinate * [pSize];
	for (int i = 0; i < pSize; i++) B[i] = new Coordinate[pSize];
}
Board& Board::operator=( Board& b) {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
	Board* btmp = new Board;
	btmp->size = b.size;
	btmp->left = b.left;
	btmp->top = b.top;
	btmp->B = new Coordinate * [size];
	for (int i = 0; i < size; i++) btmp->B[i] = new Coordinate[size];
	return *btmp;
}

void Board::setStausAt(int i, int j,int sta) {
	B[i][j].setStatus(sta);
}
void Board::resetData()
{
	if (size == 0) return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			B[i][j].setX(4 * j + left + 4);
			B[i][j].setY(2 * i + top + 2);
			B[i][j].setStatus(0);
		}
	}
}
int Board::getSize() { return size; }
int Board::getLeft() { return left; }
int Board::getTop() { return top; }
int Board::getXAt(int i, int j) {
	return B[i][j].getX();
}
int Board::getYAt(int i, int j) {
	return B[i][j].getY();
}

int Board::getStatusAt(int i, int j) {
	return B[i][j].getStatus();
}

void Board::drawBoard() {
	if (size == 0) return;
	//dong dau
	for (int i = 0; i < size * 4; i++)
	{
		//ki tu dau
		if (i == 0) {
			_Common::gotoXY(i + left + 4, 0 + top + 2);
			cout << char(201);
		}
		else
			//ki tu chia o
			if (i % 4 == 0 && (i != 0 || i != size * 4)) {
				_Common::gotoXY(i + left + 4, 0 + top + 2);
				cout << char(203);
			}
			else
				//ki tu thuong
			{
				_Common::gotoXY(i + left +4, 0 + top + 2);
				cout << char(205);
			}
		Sleep(5);
	}
	//ki tu cuoi
	{
		_Common::gotoXY(size * 4 + left + 4, 0 + top + 2);
		cout << char(187);
	}

	//dong thuong
	for (int j = 1; j < size*2; j++)
	{
		if (j % 2 == 0) {
			for (int i = 0; i < size * 4; i++)
			{
				//ki tu dau
				if (i == 0) {
					_Common::gotoXY(i + left + 4, j + top + 2);
					cout << char(204);
				}
				else
					//ki tu chia o
					if (i % 4 == 0 && (i != 0 || i != size * 4)) {
						_Common::gotoXY(i + left + 4, j + top + 2);
						cout << char(206);
					}
					else
						//ki tu thuong
					{
						_Common::gotoXY(i + left + 4, j + top + 2);
						cout << char(205);
					}
				Sleep(0.8);
			}
			//ki tu cuoi
			{
				_Common::gotoXY(size * 4 + left + 4, j + top + 2);
				cout << char(185);
			}
			Sleep(5);
		}
		else {
			for (int i = 0; i < size * 4; i++)
			{
				//ki tu chia o
				if (i % 4 == 0) {
					_Common::gotoXY(i + left + 4, j + top + 2);
					cout << char(186);
				}
				Sleep(0.8);
			}
			//ki tu cuoi
			{
				_Common::gotoXY(size * 4 + left + 4, j + top + 2);
				cout << char(186);
			}
			Sleep(5);
		}
		Sleep(5);
	}
	
	//dong cuoi
	for (int i = 0; i < size * 4; i++)
	{
		//ki tu dau
		if (i == 0) {
			_Common::gotoXY(i + left + 4, size*2 + top + 2);
			cout << char(200);
		}
		else
			//ki tu chia o
			if (i % 4 == 0 && (i != 0 || i != size * 4)) {
				_Common::gotoXY(i + left + 4, size*2 + top + 2);
				cout << char(202);
			}

			else
				//ki tu thuong
			{
				_Common::gotoXY(i + left + 4, size*2 + top + 2);
				cout << char(205);
			}
		Sleep(10);
	}
	//ki tu cuoi
	{
		_Common::gotoXY(size*4 + left + 4, size*2 + top + 2);
		cout << char(188);
	}

	
	//_Common::gotoXY((size/2) * 4 + left + 4+50,  top + 2);
	//cout << "sjdfsdjflkdsfhlsj";
}
void Board::userBoard_1()
{
	SetColor(22);
	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 200; j++)
	{
		_Common::gotoXY(j, top + 2);
		cout << char(36);
		_Common::gotoXY(j, size - 4 + top + 2);
		cout << char(36);
	}

	for (int i = top + 2; i < size + top - 2; i++)
	{
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50, i + top );
		cout << char(36);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, i + top );
		cout << char(36);
	}
	
	// 4 corner
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 );
	cout << char(36);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, top + 2);
	cout << char(36);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 16);
	cout << char(36);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, top + 2 + 16);
	cout << char(36);

	// Player info
	SetColor(12);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 3);
	cout << "Player 1: ";
	string name;
	cin >> name;

	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 6);
	int turn = 0, win = 0, lose = 0;
	cout << "Turn:\t" << turn;
	
	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 9);
	cout << "Win:\t" << win;

	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 12);
	cout << "Lose:\t" << lose;
	Sleep(10);

	// Draw X
	SetColor(12);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 26, top + 2 + 18);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "        " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 28, top + 2 + 19);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "    " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 30, top + 2 + 20);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 28, top + 2 + 21);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "    " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 26, top + 2 + 22);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "        " << char(220) << char(220) << char(220) << char(220) << char(220);
}

void Board::userBoard_2()
{
	SetColor(13);
	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 200; j++)
	{
		_Common::gotoXY(j, top + 2 + 24);
		cout << char(156);
		_Common::gotoXY(j, size - 4 + top + 2 + 24);
		cout << char(156);
	}
	
	for (int i = top + 2; i < size + top - 3; i++)
	{
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50 , i + top + 25);
		cout << char(156);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106 , i + top + 25);
		cout << char(156);

	}

	// 4 corner
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 24);
	cout << char(156);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, top + 2 + 24);
	cout << char(156);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 40);
	cout << char(156);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, top + 2 + 40);
	cout << char(156);

	// Player info
	SetColor(10);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 27);
	cout << "Player 2: ";
	string name;
	cin >> name;

	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 30);
	int turn = 0;
	cout << "Turn:\t" << turn;
	

	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 33);
	int win = 0, lose = 0;
	cout << "Win:\t" << win;

	_Common::gotoXY((size / 2) * 4 + left + 4 + 60, top + 2 + 36);
	cout << "Lose:\t" << lose;
	Sleep(10);

	// Draw O
	SetColor(10);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 72, top + 2 + 18);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 70, top + 2 + 19);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "        " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 68, top + 2 + 20);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "            " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 70, top + 2 + 21);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "        " << char(220) << char(220) << char(220) << char(220) << char(220);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 72, top + 2 + 22);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
}
int Board::testBoard(int pX, int pY) {
	bool check = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (B[4 * j + left + 4][2 * i + top + 2].getStatus() == 0)
			{
				check = false;
				break;
			}
		}
	}
	if (check) return 0;
	int x, y = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (B[4 * j + left + 4][2 * i + top + 2].getX() == pX && B[4 * j + left + 4][2 * i + top + 2].getY() == pY)
			{
				x = 4 * j + left + 4;
				y = 2 * i + top + 2;
				break;
			}
		}
	}
	int res = 0;
	int xStart = (x - 4 * 4 > left + 4) ? x - 4 * 4 : left + 4;
	int yStart = (y - 4 * 2 > top + 2) ? y - 4 * 2 : top + 2;
	int xEnd = (x + 4 * 4 >= left + 4 + 4 * size) ? left + 4 + 4 * (size - 1) : x + 4 * 4;
	int yEnd = (y + 4 * 2 >= top + 2 + 2 * size) ? top + 2 + 2 * (size - 1) : y + 4 * 2;
	int x1, x2, y1, y2;
	for (int i = xStart; i <= x; i + 4)
	{
		if (i + 4 * 4 < left + 4 + 4 * size)
		{
			res = B[i][y].getStatus() + B[i + 4][y].getStatus() + B[i + 4 * 2][y].getStatus()
				+ B[i + 4 * 3][y].getStatus() + B[i + 4 * 4][y].getStatus();
			x1 = i - 4 >= left + 4 ? i - 4 : xStart;
			y1 = y;
			x2 = i + 5 * 4 >= left + 4 + 4 * size ? x + 4 * 4 : i + 4 * 5;
			y2 = y;
		}
		if (res == 5 && (B[x1][y1].getStatus() != -1 || B[x2][y2].getStatus() != -1))
		{
			pX = i;
			pY = y;
			return 1;
		}
		if (res == -5 && (B[x1][y1].getStatus() != 1 || B[x2][y2].getStatus() != 1))
		{
			pX = i;
			pY = y;
			return -1;
		}
	}
}
Board::~Board() {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
}
