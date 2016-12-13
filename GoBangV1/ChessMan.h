#pragma once
#include "stdafx.h"
class ChessMan{
private:
	int color;          //0�����ɫ��1�����ɫ
	int row;            //������������
	int column;         //�������µ�����

public:
	ChessMan(int color, int row, int column){
		this->color = color;
		this->column = column;
		this->row = row;
	}

	int GetColor(){
		return color;
	}
	
	void SetColor(int color){
		this->color = color;
	}

	void GetPosition(int &row, int &column){
		row = this->row;
		column = this->column;
	}

	void SetPositon(int row, int column){
		this->row = row;
		this->column = column;
	}
};