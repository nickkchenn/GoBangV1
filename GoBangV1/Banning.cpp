#include "stdafx.h"
#include "Brain.h"

void Banning::getbanChess(int chess[9], const int state[15][15], int Px,int Py, int color, int direction) {
	int hiscolor;//�߽���������
	if (color == BLACKFLAG)
		hiscolor = WHITEFLAG;
	else
		hiscolor = BLACKFLAG;

	chess[4] = color;
	switch (direction) {
	case 0://����

		for (int i = Px, j = 1; j <= 4; j++) {//���󿽱��ĸ�
			int column = Py - j;
			if (column < 0) {
				for (; j <= 4; j++)
					chess[4 - j] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 - j] = state[i][column];//û���磬����state����
		}
		for (int i = Px, j = 1; j <= 4; j++) {//���ҿ����ĸ�
			int column = Py + j;
			if (column > 14) {
				for (; j <= 4; j++)
					chess[4 + j] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 + j] = state[i][column];//û���磬����state����
		}
		break;
	case 1://����
		for (int j = Py, i = 1; i <= 4; i++) {//���Ͽ����ĸ�
			int row = Px - i;
			if (row < 0) {
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 - i] = state[row][j];//û���磬����state����
		}
		for (int i = 1, j = Py; i <= 4; i++) {//���¿����ĸ�
			int row = Px + i;
			if (row > 14) {
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 + i] = state[row][j];//û���磬����state����
		}
		break;
	case 2://����
		for (int i = 1, j = 1; i <= 4; i++, j++) {//�����Ͽ����ĸ�
			int row = Px - i;
			int column = Py - j;
			if (row < 0 || column <0) {//����һ�����߽�
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 - i] = state[row][column];//û���磬����state����
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//�����¿����ĸ�
			int row = Px + i;
			int column = Py + j;
			if (row > 14 || column > 14) {//����һ�����߽�
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 + i] = state[row][column];//û���磬����state����
		}
		break;
	case 3://����
		for (int i = 1, j = 1; i <= 4; i++, j++) {//�����¿����ĸ�
			int row = Px + i;
			int column = Py - j;
			if (row > 14 || column <0) {//����һ�����߽�
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 - i] = state[row][column];//û���磬����state����
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//�����Ͽ����ĸ�
			int row = Px - i;
			int column = Py + j;
			if (row < 0 || column > 14) {//����һ�����߽�
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 + i] = state[row][column];//û���磬����state����
		}
		break;
	default:
		//������
		break;
	}
}
int Banning::BanningTypeJudge(const int chess[9]){
	int mycolor = chess[4];
	int hiscolor;

	int left, right;//��ʼ�������߶Ͽ���λ��
	int colorleft, colorright;//��ʼ�������߶Ͽ�����ɫ��NOTHING����hiscolor
	int count = 1;//�������ж��ٸ�����ʼ��

	if (mycolor == BLACKFLAG)
		hiscolor = WHITEFLAG;
	else
		hiscolor = BLACKFLAG;

	for (int i = 1; i <= 4; i++) {
		if (chess[4 - i] == mycolor)
			count++;//ͬɫ
		else {
			left = 4 - i;//����Ͽ�λ��
			colorleft = chess[4 - i];//����Ͽ���ɫ
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (chess[4 + i] == mycolor)
			count++;//ͬɫ
		else {
			right = 4 + i;//����Ͽ�λ��
			colorright = chess[4 + i];//����Ͽ���ɫ
			break;
		}
	}

	if (count == 1) {                                           //������1��
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];
		int colorleft3 = chess[left - 3];
		int colorright3 = chess[right + 3];

		if ((colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorright1 == mycolor && colorright2 == mycolor) ||
			(colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorleft1 == mycolor && colorleft2 == mycolor)
			)
			return BAN4;
	}

	if (count == 2) {                                          //������2��
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];
		
		if ((left == 3 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorleft1 == mycolor ) ||
			(left == 2 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorright1 == mycolor) 

			)
			return BAN1;
	}

	if (count == 3) {                                                //������3��
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		if ((left == 3 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorleft1 == mycolor) ||
			(left == 1 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorright1 == mycolor)
			)
			return BAN6;
		if ((left == 3 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG) ||
			(left == 1 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)
			)
			return BAN3;
		if (left == 2 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)
			return BAN2;
	}
	
	if (count == 4)                                                 //������4��
	{
		if ((left == 2 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG) ||
			(left == 1 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)
			)
			return BAN5;
	}

	
	if (count == 6){                                                  //������6��
		if ((left == 1 && right == 8) || (left==0 && right == 7) )
		return BAN7;
	}
	
	return NOBAN;                                                //����û����в

	}
	

int Banning::getBanningType(const int state[15][15], int Px,int Py, int color, int direction) {
	int banningtype;
	int chess[9] = { 0 };

	getbanChess(chess, state, Px,Py, color, direction);
	banningtype = BanningTypeJudge(chess);

	return banningtype;
}

int Banning::giveBanningSign(Situation situation) {

	int ban1 = situation.ban1 + situation.ban2;
	int ban2 = situation.ban3 + situation.ban4;
	int ban4 = situation.ban5 + situation.ban6;

	if (situation.ban7 >= 1)
		return BANSIGN6;                 //��������

	if (situation.ban5 == 2 )
		return BANSIGN5;                //�ڶ������Ľ���

	if (ban4 >= 2)
		return BANSIGN4;                //��һ�����Ľ���

	if (situation.ban2 == 2)
		return BANSIGN3;                //��������������

	if (ban2 >= 2)
		return BANSIGN2;               //�ڶ�����������

	if (ban1 >= 1)
		return BANSIGN1;               //��һ����������
	if (situation.noban >= 1)
		return NOBANSIGN;
	
	return NOBANSIGN;                        //û�н���
}


int Banning::judgeBanningSituation(const int state[15][15], int Px,int Py, int color) {

	Situation situation = { 0 };//��¼��ǰ���Ʊ���

	for (int direction = 0; direction < 4; direction++) {                //�ĸ�����,0�ᣬ1����2�������£�3��������
		int banningtype;
		banningtype = getBanningType(state, Px,Py, color, direction);//ȡ�ý�������

		switch (banningtype) {                                         //�������Ͷ�situation����
		case BAN1:
			situation.ban1++;
			break;
		case BAN2:
			situation.ban2++;
			break;
		case BAN3:
			situation.ban3++;
			break;
		case BAN4:
			situation.ban4++;
			break;
		case BAN5:
			situation.ban5++;
			break;
		case BAN6:
			situation.ban6++;
			break;
		case BAN7:
			situation.ban7++;
			break;
		case NOBAN:
			situation.noban++;
		
		default:
			//������
			break;
		}
	}

	return giveBanningSign(situation);                                      //�������Ƶó����ֱ�־
}
