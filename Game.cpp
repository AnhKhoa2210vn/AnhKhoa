#include"Game.h"

Game::Game(){
    _Board.resetData();
    _Board.drawBoard();
    _Board.userBoard_1();
    _Board.userBoard_2();
    left = _Board.getLeft();
    top = _Board.getTop();
    size = _Board.getSize();
    //center of __Board game
    xMidRect = _Board.getXAt(10, 10);
    yMidRect = _Board.getYAt(10, 10);
    _Common::gotoXY(xMidRect+2, yMidRect+1);
}

void Game::startGame() {
    while (true)
    {
    x:
        {
            while (true)
            {
                int p = _getch();
                if (p == 115)moveDown();
                if (p == 119)moveUp();
                if (p == 97)moveLeft();
                if (p == 100)moveRight();
                if (p == 27) {
                    system("cls");
                    break;
                }
                if (p == 13)
                    //when press "ENTER" check coordinate at rectangle was imported or wasn't imported
                    //if not printed (status at i,j)=0 else status = 1 or status=-1
                    if (_Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2) == 0)
                    {
                        //when status=0 then mark -1 at coordinate  when printing X
                        _Board.setStausAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2, -1);
                        SetColor(12);
                        cout << "X";               
                        Beep(885, 100);
                        if (checkWinRow()) {
                            cout << "WIN GAME";
                        }
                        _Common::gotoXY(xMidRect + 2, yMidRect + 1);
                         goto o;
                    }
            }
            break;
        }
    o:
        {
            while (true)
            {
                int p = _getch();
                if (p == 115)moveDown();
                if (p == 119)moveUp();
                if (p == 97)moveLeft();
                if (p == 100)moveRight();
                if (p == 27) {
                    system("cls");
                    break;
                }
                //when press "ENTER" check coordinate at rectangle was imported or wasn't imported
                //if not printed (status at i,j)=0 else status = 1 or status=-1
                if (p == 13) 
                    if (_Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2) == 0)
                    {
                        //when status=0 then mark -1 at coordinate  when printing X
                        _Board.setStausAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2, 1);
                        SetColor(16);
                        cout << "O";
                        Beep(990, 100);
                        if (checkWinRow()) { 
                            cout << "WIN GAME";
                        }
                        _Common::gotoXY(xMidRect + 2, yMidRect + 1);
                        goto x;
                    }
            }
            break;
        }
    }
}

void Game::moveDown() {
    //Pointer just move when isn't not move over border bottom
    if (yMidRect + 2 <= (size -1) * 2 + top + 2 ) {
        _Common::gotoXY(xMidRect + 2, yMidRect + 2 + 1);
        yMidRect += 2;
    }
}
void Game::moveUp() {
    //Pointer just move when isn't not move over border top
    if (yMidRect - 2 >= top + 2 ) {
        _Common::gotoXY(xMidRect + 2, yMidRect - 2 + 1);
        yMidRect -= 2;
    }
}
void Game::moveLeft() {
    //Pointer just move when isn't not move over border left
    if (xMidRect - 4 >= left + 4) {
        _Common::gotoXY(xMidRect - 4 + 2, yMidRect + 1);
        xMidRect -= 4;
    }
}
void Game::moveRight() {
    //Pointer just move when isn't not move over border right
    if (xMidRect + 4 <= (size -1) * 4 + left + 4) {
        _Common::gotoXY(xMidRect + 4 + 2, yMidRect + 1);
        xMidRect += 4;
    }
}
bool Game::checkWinRow() {
    int row = (yMidRect - top - 2) / 2;
    int r, l;
    l = r = (xMidRect - left - 4) / 4;
    int countL=0, countR=0;
    int status = _Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2);
    while (_Board.getStatusAt(l-1,row)==status)
    {
        ++countL;
        --l;
    }
    while (_Board.getStatusAt(r+1,row)==status)
    {
        ++countR;
        ++r;
    }
    if (countL + countR >= 4)return true;
    else return false;
}
Game::~Game()
{
}
