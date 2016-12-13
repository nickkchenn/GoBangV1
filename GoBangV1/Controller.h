#pragma once
#include "stdafx.h"
#include <iostream>
#include "ChessMan.h"
#include "ChessPad.h"
#include "Player.h"
#include"Brain.h"

using namespace std;

class Controller{
private:
		int mode;
		int order;
		std::string blackname, whitename;
		ChessPad displayresult;
		ChessPad chesspad;
		Brain judge;
		Banning Check;

		void chooseMode();
		void initOrderAName();
		void initOrder();
		void playchess(Player &black, Player &white, Brain &judge, ChessPad &chesspad, ChessPad &displayresult, Banning Check, int chesspadstate[15][15]);
public:
	Controller() {
		mode = -1;
	}
	void initGame();
	void startGame();
	void exitGame(int end);

	
};