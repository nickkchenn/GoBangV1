#pragma once
#include "stdafx.h"
#include <string>
#include "ChessMan.h"
#include "Brain.h"

class Player {
protected:
	int color;                                                    //0�ڷ���1�׷�
	std::string name;                                            // ��������
public:
	virtual ChessMan MakeMove(const int chesspadstate[15][15]) = 0;      //���麯��
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
	Brain PCbrain;                                                  //�˹�������
public:
	PCPlayer(int color, std::string name);
	ChessMan MakeMove(const int chesspadstate[15][15]);             //�����²�����
};
