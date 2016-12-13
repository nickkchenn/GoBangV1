#pragma once
#include "stdafx.h"
#include <string>
#include "ChessMan.h"
#include "Brain.h"

class Player {
protected:
	int color;                                                    //0黑方，1白方
	std::string name;                                            // 棋手名字
public:
	virtual ChessMan MakeMove(const int chesspadstate[15][15]) = 0;      //纯虚函数
	std::string getName() {
		return name;
	}
};

class HumanPlayer :public Player {
public:
	HumanPlayer(int color, std::string name);
	ChessMan MakeMove(const int chesspadstate[15][15]);

};

class PCPlayer :public Player {
private:
	Brain PCbrain;                                                  //人工智能类
public:
	PCPlayer(int color, std::string name);
	ChessMan MakeMove(const int chesspadstate[15][15]);             //计算下步棋子
};
