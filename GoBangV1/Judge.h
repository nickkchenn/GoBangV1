#pragma once
#include "stdafx.h"
class Judge {
private:
	int currentplayer;//0黑方，1白方

public:
	Judge() {
		currentplayer = 1;
	}
	int judgeResult(const int chesspadstate[15][15]);     //判断比赛结果：0为还未能判定胜负，1为黑方胜，2为白方胜，3为和棋

	int  nextPlayer() {//下一个棋手
		if (currentplayer)
			currentplayer = 0;
		else
			currentplayer = 1;
		return currentplayer;
	}
};