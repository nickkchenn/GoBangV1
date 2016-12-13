#include "stdafx.h"
#include "ChessPad.h"

using namespace std;

void ChessPad::display(string msg){
	int initialstate[15][15] = { 0 };
	display(initialstate, msg);
}

void ChessPad::display(const int chesspadstate[15][15], string msg) {
	system("color 6f");
    system("mode con cols=60 lines=27");                                       //设置窗口大小
	system("title 五子棋 By陈鹏勇 学号：201628014227050");
	system("cls");                                                             //先清屏
	cout << "           五子棋游戏" << endl;
	cout << columnn << endl;                                                   //显示列号
	for (int row = 0; row < 15; row++) {                                       //第row行
		cout << rown.at((row + 1) * 2 + 1) << " ";                             //显示行号
		for (int column = 0; column < 15; column++) {                          //第column列
			switch (chesspadstate[row][column]) {
			case 0:                                                           //空白
				cout << chesspadbase.at((row * 15 + column) * 2)
					<< chesspadbase.at((row * 15 + column) * 2 + 1);
				break;
			case 1:                                                          //黑棋
				cout << "●";
				break;
			case 2:                                                         //白棋
				cout << "○";
				break;
			case 3:                                                        //黑棋(lastmove)
				cout << "▼";
				break;
			case 4:                                                       //白棋(lastmove)
				cout << "▽";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	cout << msg;
}
void ChessPad::menudisplay(string msg){
	system("color 6f");
	system("mode con cols=60 lines=27");                                       //设置窗口大小
	system("title 五子棋 By陈鹏勇 学号：201628014227050");
	system("cls");
	cout << msg;
}
void ChessPad::finaldisplay(const int chesspadstate[15][15], string msg, int winColor){
	system("color 6f");
	system("mode con cols=60 lines=27");                                       //设置窗口大小
	system("title 五子棋 By陈鹏勇 学号：201628014227050");
	system("cls");                                                             //先清屏
	cout << "           五子棋游戏" << endl;
	cout << columnn << endl;                                                   //显示列号
	for (int row = 0; row < 15; row++) {                                       //第row行
		cout << rown.at((row + 1) * 2 + 1) << " ";                             //显示行号
		for (int column = 0; column < 15; column++) {                          //第column列
			switch (chesspadstate[row][column]) {
			case 0:                                                           //空白
				cout << chesspadbase.at((row * 15 + column) * 2)
					<< chesspadbase.at((row * 15 + column) * 2 + 1);
				break;
			case 1:                                                          //黑棋
				cout << "●";
				break;
			case 2:                                                         //白棋
				cout << "○";
				break;
			case 3:                                                        //黑棋(lastmove)
				cout << "▼";
				break;
			case 4:                                                       //白棋(lastmove)
				cout << "▽";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	switch (winColor){
	case 1:{
		cout << "┌―――――――――――――――――――――――――┐\n"
			    "│             恭喜" + msg + "获得胜利！              \n"
			    "│                                                  │\n"
			    "│[胜利玩家]：" + msg + "                             \n"
			    "│[棋子颜色]: 白色                                  │\n"
			    "│[1]：再来一局！                                   │\n"
			    "│[2]: 退出游戏                                     │\n"
			    "└―――――――――――――――――――――――――┘\n";
		break;
	}
	case 0:{
		cout << "┌―――――――――――――――――――――――――┐\n"
			    "│             恭喜" + msg + "获得胜利！              \n"
			    "│                                                  │\n"
			    "│[胜利玩家]：" + msg + "                             \n"
			    "│[棋子颜色]: 黑色                                  │\n"
			    "│[1]：再来一局！                                   │\n"
			    "│[2]: 退出游戏                                     │\n"
			    "└―――――――――――――――――――――――――┘\n";
		break;
	}
	case 2:{
		cout << "┌―――――――――――――――――――――――――┐\n"
			    "│             棋逢对手，平局！                     │\n"
			    "│                                                  │\n"
			    "│[1]：再来一局！                                   │\n"
			    "│[2]: 退出游戏                                     │\n"
			    "└―――――――――――――――――――――――――┘\n";
		break;
	}
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:{
		cout << "┌―――――――――――――――――――――――――┐\n"
			    "│        " + msg + "                                \n"
			    "│                                                  │\n"
			    "│[1]：再来一局！                                   │\n"
			    "│[2]: 退出游戏                                     │\n"
			    "└―――――――――――――――――――――――――┘\n";
		break;
	}
	}
	cout << endl;
}
void ChessPad::putChessman(ChessMan chessman) {

	if (chesspadstate[lastrow][lastcolumn])                                //该位置已有棋子
		chesspadstate[lastrow][lastcolumn] -= 2;                          //不是最后一步了

	chessman.GetPosition(lastrow, lastcolumn);                          //重新设置最后一步

	if (chessman.GetColor())                                           //GetColor结果为1，是白棋
		chesspadstate[lastrow][lastcolumn] = 4;
	else                                                               //GetColor结果为0，是黑棋
		chesspadstate[lastrow][lastcolumn] = 3;

}

void ChessPad::getChesspadState(int chesspadstate[ROWNUM][COLNUM]) {
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLNUM; j++)
			chesspadstate[i][j] = this->chesspadstate[i][j];
}
void ChessPad::clearChesspadState(int chesspadstate[ROWNUM][COLNUM]){
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLNUM; j++)
			this->chesspadstate[i][j] = 0;
}