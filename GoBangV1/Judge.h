#pragma once
#include "stdafx.h"
class Judge {
private:
	int currentplayer;//0�ڷ���1�׷�

public:
	Judge() {
		currentplayer = 1;
	}
	int judgeResult(const int chesspadstate[15][15]);     //�жϱ��������0Ϊ��δ���ж�ʤ����1Ϊ�ڷ�ʤ��2Ϊ�׷�ʤ��3Ϊ����

	int  nextPlayer() {//��һ������
		if (currentplayer)
			currentplayer = 0;
		else
			currentplayer = 1;
		return currentplayer;
	}
};