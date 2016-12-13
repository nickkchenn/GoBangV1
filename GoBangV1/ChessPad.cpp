#include "stdafx.h"
#include "ChessPad.h"

using namespace std;

void ChessPad::display(string msg){
	int initialstate[15][15] = { 0 };
	display(initialstate, msg);
}

void ChessPad::display(const int chesspadstate[15][15], string msg) {
	system("color 6f");
    system("mode con cols=60 lines=27");                                       //���ô��ڴ�С
	system("title ������ By������ ѧ�ţ�201628014227050");
	system("cls");                                                             //������
	cout << "           ��������Ϸ" << endl;
	cout << columnn << endl;                                                   //��ʾ�к�
	for (int row = 0; row < 15; row++) {                                       //��row��
		cout << rown.at((row + 1) * 2 + 1) << " ";                             //��ʾ�к�
		for (int column = 0; column < 15; column++) {                          //��column��
			switch (chesspadstate[row][column]) {
			case 0:                                                           //�հ�
				cout << chesspadbase.at((row * 15 + column) * 2)
					<< chesspadbase.at((row * 15 + column) * 2 + 1);
				break;
			case 1:                                                          //����
				cout << "��";
				break;
			case 2:                                                         //����
				cout << "��";
				break;
			case 3:                                                        //����(lastmove)
				cout << "��";
				break;
			case 4:                                                       //����(lastmove)
				cout << "��";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	cout << msg;
}
void ChessPad::menudisplay(string msg){
	system("color 6f");
	system("mode con cols=60 lines=27");                                       //���ô��ڴ�С
	system("title ������ By������ ѧ�ţ�201628014227050");
	system("cls");
	cout << msg;
}
void ChessPad::finaldisplay(const int chesspadstate[15][15], string msg, int winColor){
	system("color 6f");
	system("mode con cols=60 lines=27");                                       //���ô��ڴ�С
	system("title ������ By������ ѧ�ţ�201628014227050");
	system("cls");                                                             //������
	cout << "           ��������Ϸ" << endl;
	cout << columnn << endl;                                                   //��ʾ�к�
	for (int row = 0; row < 15; row++) {                                       //��row��
		cout << rown.at((row + 1) * 2 + 1) << " ";                             //��ʾ�к�
		for (int column = 0; column < 15; column++) {                          //��column��
			switch (chesspadstate[row][column]) {
			case 0:                                                           //�հ�
				cout << chesspadbase.at((row * 15 + column) * 2)
					<< chesspadbase.at((row * 15 + column) * 2 + 1);
				break;
			case 1:                                                          //����
				cout << "��";
				break;
			case 2:                                                         //����
				cout << "��";
				break;
			case 3:                                                        //����(lastmove)
				cout << "��";
				break;
			case 4:                                                       //����(lastmove)
				cout << "��";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	switch (winColor){
	case 1:{
		cout << "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
			    "��             ��ϲ" + msg + "���ʤ����              \n"
			    "��                                                  ��\n"
			    "��[ʤ�����]��" + msg + "                             \n"
			    "��[������ɫ]: ��ɫ                                  ��\n"
			    "��[1]������һ�֣�                                   ��\n"
			    "��[2]: �˳���Ϸ                                     ��\n"
			    "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
		break;
	}
	case 0:{
		cout << "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
			    "��             ��ϲ" + msg + "���ʤ����              \n"
			    "��                                                  ��\n"
			    "��[ʤ�����]��" + msg + "                             \n"
			    "��[������ɫ]: ��ɫ                                  ��\n"
			    "��[1]������һ�֣�                                   ��\n"
			    "��[2]: �˳���Ϸ                                     ��\n"
			    "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
		break;
	}
	case 2:{
		cout << "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
			    "��             �����֣�ƽ�֣�                     ��\n"
			    "��                                                  ��\n"
			    "��[1]������һ�֣�                                   ��\n"
			    "��[2]: �˳���Ϸ                                     ��\n"
			    "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
		break;
	}
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:{
		cout << "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n"
			    "��        " + msg + "                                \n"
			    "��                                                  ��\n"
			    "��[1]������һ�֣�                                   ��\n"
			    "��[2]: �˳���Ϸ                                     ��\n"
			    "���D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D�D��\n";
		break;
	}
	}
	cout << endl;
}
void ChessPad::putChessman(ChessMan chessman) {

	if (chesspadstate[lastrow][lastcolumn])                                //��λ����������
		chesspadstate[lastrow][lastcolumn] -= 2;                          //�������һ����

	chessman.GetPosition(lastrow, lastcolumn);                          //�����������һ��

	if (chessman.GetColor())                                           //GetColor���Ϊ1���ǰ���
		chesspadstate[lastrow][lastcolumn] = 4;
	else                                                               //GetColor���Ϊ0���Ǻ���
		chesspadstate[lastrow][lastcolumn] = 3;

}

void ChessPad::getChesspadState(int chesspadstate[ROWNUM][COLNUM]) {
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLNUM; j++)
			chesspadstate[i][j] = this->chesspadstate[i][j];
}
void ChessPad::clearChesspadState(int chesspadstate[ROWNUM][COLNUM]){
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLNUM; j++)
			this->chesspadstate[i][j] = 0;
}