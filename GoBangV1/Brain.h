#pragma once
#include "stdafx.h"
struct Position{
	int x;                                                   //0到14，行
	int y;                                                   //0到14，列
};
struct Situation {                                          //当前位置的形式，打分根据这个来打
	int win5;                                               //5连珠
	int alive4;                                             //活4
	int die4;                                               //死4
	int lowdie4;                                            //死4低级版本
	int alive3;                                             //活3
	int tiao3;                                              //跳3
	int die3;                                               //死3
	int alive2;                                             //活2
	int lowalive2;                                          //低级活2
	int die2;                                               //死2
	int nothreat;                                           //没有威胁
    
	int ban1;
	int ban2;
	int ban3;
	int ban4;
	int ban5;
	int ban6;
	int ban7;
	int noban;
};

class Brain {
public:
	//0黑方，1白方
	int currentplayer;       
	//棋盘状态标志
	static const int WHITEFLAG = 2;
	static const int BLACKFLAG = 1;
	static const int NOTHINGFLAG = 0;

	//棋局类型   
	static const int WIN5 = 0;                          //0->5连珠
	static const int ALIVE4 = 1;                        //1->活4
	static const int DIE4 = 2;                         //2->死4
	static const int LOWDIE4 = 3;                     //3->死4的低级版本
	static const int ALIVE3 = 4;                       //3->活3
	static const int TIAO3 = 5;                       //5->跳3
	static const int DIE3 = 6;                         //6->死3
	static const int ALIVE2 = 7;                      //7->活2
	static const int LOWALIVE2 = 8;                  //8->低级活2
	static const int DIE2 = 9;                      //9->死2
	static const int NOTHREAT = 10;                //10->没有威胁

	static const int BAN1 = 11;
	static const int BAN2 = 12;
	static const int BAN3 = 13;
	static const int BAN4 = 14;
	static const int BAN5 = 15;
	static const int BAN6 = 16;
	static const int BAN7 = 17;
	static const int NOBAN = 18;


	//打分等级
	static const int LevelOne = 100000;               //成五
	static const int Leveltwo = 10000;                //成活4 或 双死4 或 死4活3
	static const int Levelthree = 5000;              //双活3
	static const int Levelfour = 1000;               //死3高级活3
	static const int Levelfive = 500;                //死四
	static const int Levelsix = 400;				//低级死四
	static const int Levelseven = 100;				//单活3
	static const int LevelEight = 90;				//跳活3
	static const int LevelNight = 50;				//双活2
	static const int LevelTen = 10;					//活2
	static const int LevelEleven = 9;				//低级活2
	static const int LevelTwelve = 5;              //死3
	static const int LevelThirteen = 2;            //死2
	static const int LevelFourteen = 1;           //没有威胁
	static const int LevelFiveteen = 0;          //不能下

	static const int BANSIGN1 = 11;
	static const int BANSIGN2 = 12;
	static const int BANSIGN3 = 13;
	static const int BANSIGN4 = 14;
	static const int BANSIGN5 = 15;
	static const int BANSIGN6 = 16;
	static const int NOBANSIGN = 17;

	int judgeType(const int chess[9]);//判断当前方向棋局类型
	void getChess(int chess[9], const int state[15][15], Position position, int color, int direction);//获得当前方向棋局数组chess
	int getType(const int state[15][15], Position position, int color, int direction);//获得当前方向棋局类型
	int judgeChessSituation(const int state[15][15], Position position, int color);//综合4个方向评判当前位置棋局形势的分数
	int giveScore(Situation situation);//根据形势，给分
	Position maxScore(const int myscore[15][15], const int hisscore[15][15]);//根据我的分数和对手的分数，选取最大利益的位置

public:
	Position getPosition(const int chesspadstate[15][15], int color);//根据当前形势，计算下步棋的位置
	int Judge() {
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

class Banning :public Brain {
private:
	int bansign;                                         //禁手的标识符
public:
	void getbanChess(int chess[9], const int state[15][15], int Px, int Py, int color, int direction);
	int BanningTypeJudge(const int chess[9]);
	int getBanningType(const int state[15][15], int Px,int Py, int color, int direction);
	int judgeBanningSituation(const int state[15][15], int Px,int Py, int color);
	int giveBanningSign(Situation situation);
};