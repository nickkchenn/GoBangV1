#include "stdafx.h"
#include"Player.h"
#include"Brain.h"
PCPlayer::PCPlayer(int color, std::string name) {
	this->color = color;
	this->name = name;
}
ChessMan PCPlayer::MakeMove(const int chesspadstate[15][15]) {
	Position position;

	position = PCbrain.getPosition(chesspadstate, color);//����λ��

	return ChessMan(color, position.x, position.y);//�������Ӷ���
}