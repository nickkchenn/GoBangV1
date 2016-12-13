#include "stdafx.h"
#include <iostream>
#include "Controller.h"
#include"Brain.h"
#include "ChessPad.h"
#include "stdlib.h"

using namespace std;
ChessPad Display;
void Controller ::chooseMode() {
	                                                                             //选择模式
	do {
		displayresult.menudisplay(Display.welcome);
		cin.clear();
		cin.sync();
		cin >> mode;
	} while (4 < mode || mode < 1);
}

void Controller::initOrder() {
	//初始化
	do {                                                                           //选择顺序
		displayresult.display("电脑先下请输入0，您先下请输入1(默认先下者为黑方)：");
		cin.clear();
		cin.sync();
		cin >> order;
	} while (2 <= order || order < 0);
}
void Controller::initOrderAName() {

	if (mode) {                                                                   //人人对弈模式
		//初始化
		displayresult.display("请输入黑方玩家的名字（默认黑方先下）：");
		cin.clear();
		cin.sync();
		getline(cin, blackname);
		displayresult.display("请输入白方玩家的名字（默认黑方先下）：");
		cin.clear();
		cin.sync();
		getline(cin, whitename);
	}
	else {                                                                       //人机对弈模式
		initOrder();                                                             //选择顺序
		if (order) {
			blackname = "玩家";
			whitename = "电脑";
		}
		else {
			blackname = "电脑";
			whitename = "玩家";
		}
	}
}

void Controller::initGame(){
	chooseMode();                                                                //选择模式
}

void Controller::startGame() {
	int state[15][15] = { 0 };
	switch (mode){
	case 2:                                                                       //人人对弈模式
	{	initOrderAName();                                                            //选择下棋顺序和初始化名字
		//初始化玩家
		HumanPlayer black(0, blackname);
		HumanPlayer white(1, whitename);
		judge.currentplayer = 1;
		//下棋
		playchess(black, white, judge, chesspad, displayresult, Check, state);
		break;
	}
	case 1:                                                                     //人机对弈模式
	{	initOrder();                                                            //选择下棋顺序和初始化名字
		if (order) {                                                            //机器后下
		//初始化玩家
		PCPlayer white(1, "电脑");
		HumanPlayer black(0, "玩家");
		judge.currentplayer = 1;
		//下棋
		playchess(black, white, judge, chesspad, displayresult, Check, state);
	    }

	    else {                                                                  //机器先下
		//初始化玩家
		PCPlayer black(0, "电脑");
		HumanPlayer white(1, "玩家");
		judge.currentplayer = 1;
		//下棋
		playchess(black, white, judge, chesspad, displayresult, Check, state);
	    }
		break;
	}
	case 3:{
		int back = 0;
		
		do{
			displayresult.menudisplay(Display.info);
			cin.clear();
			cin.sync();
			cin >> back;
		} while (back != 1);
		if (back){
			chooseMode();
			startGame();
		}
		break;
	}
	case 5:
		exit(0);
		break;
	case 4:{
		PCPlayer white(1, "电脑1");
		PCPlayer black(0, "电脑2");
		judge.currentplayer = 1;
		playchess(black, white, judge, chesspad, displayresult, Check, state);
	}
	}
	

}

void Controller::playchess(Player &black, Player &white, Brain &judge, ChessPad &chesspad, ChessPad &displayresult, Banning Check,int state[15][15]) {
	int result;
	int choice;
	//int state[15][15] = { 0 };
	//下棋阶段
	while (!(result = judge.judgeResult(state))) {
		if (judge.nextPlayer()) {
			displayresult.display(state, " 白方" + white.getName() + "落子：\n");                         //在棋盘中显示棋子
			
			chesspad.putChessman(white.MakeMove(state));                                             //更新落子状态
		}
		else {

			displayresult.display(state, " 黑方" + black.getName() + "落子：\n");
			
			chesspad.putChessman(black.MakeMove(state));

		}
		chesspad.getChesspadState(state);
	}
	//显示结果
	switch (result) {
	case 1:{
		do {
			displayresult.finaldisplay(state, black.getName(), 0);
			cin.clear();
			cin.sync();
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	case 2:
	{
		do {
			displayresult.finaldisplay(state, white.getName(), 1);
			cin.clear();
			cin.sync();
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	case 3:
	{
		do {
			displayresult.finaldisplay(state, black.getName(), 2);
			cin.clear();
			cin.sync();
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	case 11:{
		do{
			displayresult.finaldisplay(state, "出现第一类三三禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！", 11);
			cin.clear();
			cin.sync();
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break; 
	}
	case 12:{
		do{
		displayresult.finaldisplay(state, "出现第二类三三禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！",12);
		cin.clear();
		cin.sync();
		cin >> choice;
	} while (choice != 1 && choice != 2);
	if (choice == 1){
		chesspad.clearChesspadState(state);
		chooseMode();
		startGame();
	}
	else if (choice == 2){
		exit(0);
	}
	break;
}
	case 13:{
		do{
		displayresult.finaldisplay(state, "出现第三类三三禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！",13);
		cin.clear();
		cin.sync();
		cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	case 14:{
		do{
		displayresult.finaldisplay(state, "出现第一类四四禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！",14);
		cin.clear();
		cin.sync();
		cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	};
	case 15:{
		do{
		displayresult.finaldisplay(state, "出现第二类四四禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！",15);
		cin.clear();
		cin.sync();
		cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	case 16:{
		do{
		displayresult.finaldisplay(state, "出现长连禁手，黑方" + black.getName() + "犯规失败。\n                   白方" + white.getName() + "自动获胜！！！",16);
		
		cin.clear();
		cin.sync();
		cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1){
			chesspad.clearChesspadState(state);
			chooseMode();
			startGame();
		}
		else if (choice == 2){
			exit(0);
		}
		break;
	}
	default:
		break;
	}
	chesspad.clearChesspadState(state);

	}
	
