#pragma once
#include<string>
#include<iostream>
#include<cstdlib>
#include"ChessMan.h"

class ChessPad {
private:
	std::string rown;                                                               //棋盘行标记
	std::string chesspadbase;                                                       //棋盘网格
	std::string columnn;                                                            //棋盘列标记
	
	int lastrow;                                                                    //上一步落子所在行
	int lastcolumn;                                                                 //上一步落子所在列
	static const int ROWNUM = 15;                                                   //棋盘行数
	static const int COLNUM = 15;                                                   //棋盘列数
	int chesspadstate[ROWNUM][COLNUM];                                              //棋盘状态

public:
	std::string welcome = "┌―――――――――――――――――――――――――┐\n"
	                      "│               欢迎来到五子棋游戏!                │\n"
	                      "│[1]、人机对弈                                     │\n"
	                      "│                                                  │\n"
	                      "│[2]、双人对弈                                     │\n"
	                      "│                                                  │\n"
	                      "│[3]、关于作者                                     │\n"
	                      "│                                                  │\n"
	                      "│[4]、自相残杀                                     │\n"
	                      "│                                                  │\n"
						  "│[5]、退出游戏                                     │\n"
						  "│                                                  │\n"
	                      "└―――――――――――――――――――――――――┘\n";
	std::string info = "┌―――――――――――――――――――――――――┐\n"
		               "│                五子棋[基本信息介绍]              │\n"
	                   "│                                                  │\n"
	                   "│[作者]：陈鹏勇                                    │\n"
					   "│                                                  │\n"
					   "│[学号]: 201628014227050                           │\n"
					   "│                                                  │\n"
					   "│[单位]：西安光学精密机械研究所                    │\n"
					   "│                                                  │\n"
					   "│[编译环境]：Microsoft Visual Studio 2013          │\n"
					   "│                                                  │\n"
					   "│[1]：返回上一级菜单                               │\n"
					   "└―――――――――――――――――――――――――┘\n";
	
	
	ChessPad(){
		rown = "   a b c d e f g h i j k l m n o";
		columnn = "   A B C D E F G H I J K L M N O";
		chesspadbase = "┌┬┬┬┬┬┬┬┬┬┬┬┬┬┐"
					   "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
		               "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			           "└┴┴┴┴┴┴┴┴┴┴┴┴┴┘";
		lastrow = 0;
		lastcolumn = 0;
		
		for (int i = 0; i < ROWNUM; i++)
			for (int j = 0; j < COLNUM; j++)
				chesspadstate[i][j] = 0;
	}
	void display(const int chesspadstate[15][15], std::string msg);                  //刷新显示函数
	void display(std::string msg);                                                   //开始前输出提示信息
	void menudisplay(std::string msg);                                                   //菜单显示函数
	void finaldisplay(const int chesspadstate[15][15],std::string msg, int winColor);
	
    void putChessman(ChessMan chessman);                                              //添加棋子
	void getChesspadState(int chesspadstate[15][15]);                              //获取棋盘状态
	void clearChesspadState(int chesspadstate[15][15]);
};
