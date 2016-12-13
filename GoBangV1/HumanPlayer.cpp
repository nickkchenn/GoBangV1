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
			std::cout << "�������²��壬(��a��B��,������aB����,�����ִ�Сд)\n:";
			std::cin.clear();
			std::cin.sync();
			std::cin >> a;
			std::cin >> b;
		} while (!('a' <= a && a <= 'o') || !('A' <= b && b <= 'O'));         //check ���������̷�Χ�ڷ��ɼ���

		x = a - 'a';                                                         //check �ж�����λ���Ƿ���������
		y = b - 'A';
		if (chesspadstate[x][y]) {                                          //����λ����������
			std::cout << "��λ���������ӣ�����������\n";
			continue;
		}
		else                                                                  //��������Ҫ��
			break;

	}
	return ChessMan(color, x, y);
}
