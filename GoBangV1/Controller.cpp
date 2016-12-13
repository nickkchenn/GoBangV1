#include "stdafx.h"
#include <iostream>
#include "Controller.h"
#include"Brain.h"
#include "ChessPad.h"
#include "stdlib.h"

using namespace std;
ChessPad Display;
void Controller ::chooseMode() {
	                                                                             //ѡ��ģʽ
	do {
		displayresult.menudisplay(Display.welcome);
		cin.clear();
		cin.sync();
		cin >> mode;
	} while (4 < mode || mode < 1);
}

void Controller::initOrder() {
	//��ʼ��
	do {                                                                           //ѡ��˳��
		displayresult.display("��������������0��������������1(Ĭ��������Ϊ�ڷ�)��");
		cin.clear();
		cin.sync();
		cin >> order;
	} while (2 <= order || order < 0);
}
void Controller::initOrderAName() {

	if (mode) {                                                                   //���˶���ģʽ
		//��ʼ��
		displayresult.display("������ڷ���ҵ����֣�Ĭ�Ϻڷ����£���");
		cin.clear();
		cin.sync();
		getline(cin, blackname);
		displayresult.display("������׷���ҵ����֣�Ĭ�Ϻڷ����£���");
		cin.clear();
		cin.sync();
		getline(cin, whitename);
	}
	else {                                                                       //�˻�����ģʽ
		initOrder();                                                             //ѡ��˳��
		if (order) {
			blackname = "���";
			whitename = "����";
		}
		else {
			blackname = "����";
			whitename = "���";
		}
	}
}

void Controller::initGame(){
	chooseMode();                                                                //ѡ��ģʽ
}

void Controller::startGame() {
	int state[15][15] = { 0 };
	switch (mode){
	case 2:                                                                       //���˶���ģʽ
	{	initOrderAName();                                                            //ѡ������˳��ͳ�ʼ������
		//��ʼ�����
		HumanPlayer black(0, blackname);
		HumanPlayer white(1, whitename);
		judge.currentplayer = 1;
		//����
		playchess(black, white, judge, chesspad, displayresult, Check, state);
		break;
	}
	case 1:                                                                     //�˻�����ģʽ
	{	initOrder();                                                            //ѡ������˳��ͳ�ʼ������
		if (order) {                                                            //��������
		//��ʼ�����
		PCPlayer white(1, "����");
		HumanPlayer black(0, "���");
		judge.currentplayer = 1;
		//����
		playchess(black, white, judge, chesspad, displayresult, Check, state);
	    }

	    else {                                                                  //��������
		//��ʼ�����
		PCPlayer black(0, "����");
		HumanPlayer white(1, "���");
		judge.currentplayer = 1;
		//����
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
		PCPlayer white(1, "����1");
		PCPlayer black(0, "����2");
		judge.currentplayer = 1;
		playchess(black, white, judge, chesspad, displayresult, Check, state);
	}
	}
	

}

void Controller::playchess(Player &black, Player &white, Brain &judge, ChessPad &chesspad, ChessPad &displayresult, Banning Check,int state[15][15]) {
	int result;
	int choice;
	//int state[15][15] = { 0 };
	//����׶�
	while (!(result = judge.judgeResult(state))) {
		if (judge.nextPlayer()) {
			displayresult.display(state, " �׷�" + white.getName() + "���ӣ�\n");                         //����������ʾ����
			
			chesspad.putChessman(white.MakeMove(state));                                             //��������״̬
		}
		else {

			displayresult.display(state, " �ڷ�" + black.getName() + "���ӣ�\n");
			
			chesspad.putChessman(black.MakeMove(state));

		}
		chesspad.getChesspadState(state);
	}
	//��ʾ���
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
			displayresult.finaldisplay(state, "���ֵ�һ���������֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������", 11);
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
		displayresult.finaldisplay(state, "���ֵڶ����������֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������",12);
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
		displayresult.finaldisplay(state, "���ֵ������������֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������",13);
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
		displayresult.finaldisplay(state, "���ֵ�һ�����Ľ��֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������",14);
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
		displayresult.finaldisplay(state, "���ֵڶ������Ľ��֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������",15);
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
		displayresult.finaldisplay(state, "���ֳ������֣��ڷ�" + black.getName() + "����ʧ�ܡ�\n                   �׷�" + white.getName() + "�Զ���ʤ������",16);
		
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
	
