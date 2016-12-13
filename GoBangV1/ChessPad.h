#pragma once
#include<string>
#include<iostream>
#include<cstdlib>
#include"ChessMan.h"

class ChessPad {
private:
	std::string rown;                                                               //�����б��
	std::string chesspadbase;                                                       //��������
	std::string columnn;                                                            //�����б��
	
	int lastrow;                                                                    //��һ������������
	int lastcolumn;                                                                 //��һ������������
	static const int ROWNUM = 15;                                                   //��������
	static const int COLNUM = 15;                                                   //��������
	int chesspadstate[ROWNUM][COLNUM];                                              //����״̬

public:
	std::string welcome = "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
	                      "��               ��ӭ������������Ϸ!                ��\n"
	                      "��[1]���˻�����                                     ��\n"
	                      "��                                                  ��\n"
	                      "��[2]��˫�˶���                                     ��\n"
	                      "��                                                  ��\n"
	                      "��[3]����������                                     ��\n"
	                      "��                                                  ��\n"
	                      "��[4]�������ɱ                                     ��\n"
	                      "��                                                  ��\n"
						  "��[5]���˳���Ϸ                                     ��\n"
						  "��                                                  ��\n"
	                      "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
	std::string info = "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
		               "��                ������[������Ϣ����]              ��\n"
	                   "��                                                  ��\n"
	                   "��[����]��������                                    ��\n"
					   "��                                                  ��\n"
					   "��[ѧ��]: 201628014227050                           ��\n"
					   "��                                                  ��\n"
					   "��[��λ]��������ѧ���ܻ�е�о���                    ��\n"
					   "��                                                  ��\n"
					   "��[���뻷��]��Microsoft Visual Studio 2013          ��\n"
					   "��                                                  ��\n"
					   "��[1]��������һ���˵�                               ��\n"
					   "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
	
	
	ChessPad(){
		rown = "   a b c d e f g h i j k l m n o";
		columnn = "   A B C D E F G H I J K L M N O";
		chesspadbase = "���ЩЩЩЩЩЩЩЩЩЩЩЩЩ�"
					   "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
			           "�����������������"
		               "�����������������"
			           "�����������������"
			           "���ةةةةةةةةةةةةة�";
		lastrow = 0;
		lastcolumn = 0;
		
		for (int i = 0; i < ROWNUM; i++)
			for (int j = 0; j < COLNUM; j++)
				chesspadstate[i][j] = 0;
	}
	void display(const int chesspadstate[15][15], std::string msg);                  //ˢ����ʾ����
	void display(std::string msg);                                                   //��ʼǰ�����ʾ��Ϣ
	void menudisplay(std::string msg);                                                   //�˵���ʾ����
	void finaldisplay(const int chesspadstate[15][15],std::string msg, int winColor);
	
    void putChessman(ChessMan chessman);                                              //�������
	void getChesspadState(int chesspadstate[15][15]);                              //��ȡ����״̬
	void clearChesspadState(int chesspadstate[15][15]);
};
