#include "stdafx.h"
#include <iostream>

#include"Player.h"

HumanPlayer::HumanPlayer(int color, std::string name) {
	this->color = color;
	this->name = name;
}
ChessMan HumanPlayer::MakeMove(const int chesspadstate[15][15]) {
	int x, y;
	char a, b;

	while (1) {

		do {
			std::cout << "请输入下步棋，(如a行B列,则输入aB即可,请区分大小写)\n:";
			std::cin.clear();
			std::cin.sync();
			std::cin >> a;
			std::cin >> b;
		} while (!('a' <= a && a <= 'o') || !('A' <= b && b <= 'O'));         //check 输入在棋盘范围内方可继续

		x = a - 'a';                                                         //check 判断落子位置是否已有棋子
		y = b - 'A';
		if (chesspadstate[x][y]) {                                          //落子位置已有棋子
			std::cout << "该位置已有棋子，请重新落子\n";
			continue;
		}
		else                                                                  //符合落子要求
			break;

	}
	return ChessMan(color, x, y);
}
