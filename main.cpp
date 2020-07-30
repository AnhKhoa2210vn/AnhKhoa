#include"Board.h"
#include"Common.h"
#include"coordinate.h"
#include"Game.h"
#include"function.h"
using namespace std;


int main() {
	
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1500, 800, TRUE);
    _Common::fixConsoleWindow();
    system("color F0");
    
    int r = 15;

    while (true)
    {
        for (int i = 0; i < 3; i++)
        {   
            SetColor(i+10);
            _Common::gotoXY(65, 5);
            cout << "  " << char(219) << char(219) << char(219) << char(219) << "      " << char(178) << char(178) << char(178) << "       " << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << "        " << char(176) << char(176) << char(176) << char(176) << "   ";
            _Common::gotoXY(65, 6);
            SetColor(i+1);
            cout << "" << char(219) << char(219) << "         " << char(178) << char(178) << " " << char(178) << char(178) << "      " << char(177) << char(177) << "   " << char(177) << char(177) << "     " << char(176) << char(176) << "    " << char(176) << char(176) << "  ";
            _Common::gotoXY(65, 7);
            SetColor(i+3);
            cout << "" << char(219) << char(219) << "        " << char(178) << char(178) << "   " << char(178) << char(178) << "     " << char(177) << char(177) << char(177) << char(177) << char(177) << "      " << char(176) << char(176) << "      " << char(176) << char(176) << " ";
            _Common::gotoXY(65, 8);
            SetColor(i+5);
            cout << "" << char(219) << char(219) << "       " << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "    " << char(177) << char(177) << "  " << char(177) << char(177) << "      " << char(176) << char(176) << "    " << char(176) << char(176) << " ";
            _Common::gotoXY(65, 9);
            SetColor(i+4);
            cout << "  " << char(219) << char(219) << char(219) << char(219) << "  " << char(178) << char(178) << "       " << char(178) << char(178) << "   " << char(177) << char(177) << "   " << char(177) << char(177) << "       " << char(176) << char(176) << char(176) << char(176) << "   ";
            Sleep(50);
        }
       
        SetColor(5);
        //menu
        _Common::gotoXY(80, 15);
        cout << "1. Start game";
        _Common::gotoXY(80, 16);
        cout << "2. Load game" << endl;
        _Common::gotoXY(80, 17);
        cout << "3. About" << endl;
        _Common::gotoXY(80, 18);
        cout << "4. Help" << endl;
        _Common::gotoXY(80, 19);
        cout << "5. Exit" << endl;

        SetColor(9);
        //key
        _Common::gotoXY(60, 30);
        cout << "TAB: " << char(174) << " " << char(175);
        _Common::gotoXY(90, 30);
        cout << "ENTER: choose";
        _Common::gotoXY(120, 30);
        cout << "ESC: exit";

        _Common::gotoXY(80, r);
       
            int key = _getch();
            if (key == 9) {
                r++;
                if (r == 20) r = 15;
                _Common::gotoXY(80, r);
            }
            if (key == 13 && r == 15) {
                system("cls");
                Game GAME;
                GAME.startGame();
            }
            if(key==13&&r==19) {
                system("cls");
                break;
            }
            if (key == 13 && r == 17) {
                system("cls");
                system("color 0E");
                SetColor(6);
                _Common::gotoXY(88, 7);
                cout << "   ABOUT:   ";
                _Common::gotoXY(84, 10);
                cout << "CARO PROJECT BY TEAM 4";
                _Common::gotoXY(80, 12);
                cout << "19127161 - Nguyen Quang Huy";
                _Common::gotoXY(80, 13);
                cout << "19127103 - Nguyen Thai Binh";
                _Common::gotoXY(80, 14);
                cout << "19127011 - Nguyen Quoc Bao";
                _Common::gotoXY(80, 15);
                cout << "19127033 - Trinh Anh Khoa";
                _Common::gotoXY(80, r);
                while (true)
                {
                    system("pause");
                    system("cls");
                    system("color F0");
                    break;
                }
            }
            if (key == 13 && r == 18) {
                system("cls");
                _Common::gotoXY(88, 7);
                cout << "   HELP   ";
                _Common::gotoXY(80, 10);
                cout << "\"A\"/Left key:\tMOVE LEFT";
                _Common::gotoXY(80, 12);
                cout << "\"D\"/Right key:\tMOVE RIGHT";
                _Common::gotoXY(80, 14);
                cout << "\"W\"/Top key:\tMOVE UP";
                _Common::gotoXY(80, 16);
                cout << "\"S\"/Bottom key:\tMOVE DOWN";
                _Common::gotoXY(80, 18);
                cout << "\"ENTER\":\tCHOOSE";
                _Common::gotoXY(80, r);
                while (true)
                {
                    system("pause");
                    system("cls");
                    break;
                }
            }
            if (key == 13 && r == 19) {
                system("cls");
                _Common::gotoXY(80, 12);
                cout << "THANKS FOR USED <3";
                _Common::gotoXY(80, r);
                break;
            }
    }
    
    SetColor(0);
	return 0;
}
