#include "stdafx.h"
#include "Brain.h"

void Banning::getbanChess(int chess[9], const int state[15][15], int Px,int Py, int color, int direction) {
	int hiscolor;//边界出界填充用
	if (color == BLACKFLAG)
		hiscolor = WHITEFLAG;
	else
		hiscolor = BLACKFLAG;

	chess[4] = color;
	switch (direction) {
	case 0://横向

		for (int i = Px, j = 1; j <= 4; j++) {//往左拷贝四个
			int column = Py - j;
			if (column < 0) {
				for (; j <= 4; j++)
					chess[4 - j] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 - j] = state[i][column];//没出界，复制state数组
		}
		for (int i = Px, j = 1; j <= 4; j++) {//往右拷贝四个
			int column = Py + j;
			if (column > 14) {
				for (; j <= 4; j++)
					chess[4 + j] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 + j] = state[i][column];//没出界，复制state数组
		}
		break;
	case 1://纵向
		for (int j = Py, i = 1; i <= 4; i++) {//往上拷贝四个
			int row = Px - i;
			if (row < 0) {
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 - i] = state[row][j];//没出界，复制state数组
		}
		for (int i = 1, j = Py; i <= 4; i++) {//往下拷贝四个
			int row = Px + i;
			if (row > 14) {
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 + i] = state[row][j];//没出界，复制state数组
		}
		break;
	case 2://左上
		for (int i = 1, j = 1; i <= 4; i++, j++) {//往左上拷贝四个
			int row = Px - i;
			int column = Py - j;
			if (row < 0 || column <0) {//其中一个出边界
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 - i] = state[row][column];//没出界，复制state数组
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//往右下拷贝四个
			int row = Px + i;
			int column = Py + j;
			if (row > 14 || column > 14) {//其中一个出边界
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 + i] = state[row][column];//没出界，复制state数组
		}
		break;
	case 3://右上
		for (int i = 1, j = 1; i <= 4; i++, j++) {//往左下拷贝四个
			int row = Px + i;
			int column = Py - j;
			if (row > 14 || column <0) {//其中一个出边界
				for (; i <= 4; i++)
					chess[4 - i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 - i] = state[row][column];//没出界，复制state数组
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//往右上拷贝四个
			int row = Px - i;
			int column = Py + j;
			if (row < 0 || column > 14) {//其中一个出边界
				for (; i <= 4; i++)
					chess[4 + i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 + i] = state[row][column];//没出界，复制state数组
		}
		break;
	default:
		//差错控制
		break;
	}
}
int Banning::BanningTypeJudge(const int chess[9]){
	int mycolor = chess[4];
	int hiscolor;

	int left, right;//开始和中心线断开的位置
	int colorleft, colorright;//开始和中心线断开的颜色，NOTHING或者hiscolor
	int count = 1;//中心线有多少个，初始化

	if (mycolor == BLACKFLAG)
		hiscolor = WHITEFLAG;
	else
		hiscolor = BLACKFLAG;

	for (int i = 1; i <= 4; i++) {
		if (chess[4 - i] == mycolor)
			count++;//同色
		else {
			left = 4 - i;//保存断开位置
			colorleft = chess[4 - i];//保存断开颜色
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (chess[4 + i] == mycolor)
			count++;//同色
		else {
			right = 4 + i;//保存断开位置
			colorright = chess[4 + i];//保存断开颜色
			break;
		}
	}

	if (count == 1) {                                           //中心线1连
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

	if (count == 2) {                                          //中心线2连
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];
		
		if ((left == 3 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorleft1 == mycolor ) ||
			(left == 2 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG && colorright1 == mycolor) 

			)
			return BAN1;
	}

	if (count == 3) {                                                //中心线3连
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
	
	if (count == 4)                                                 //中心线4连
	{
		if ((left == 2 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG) ||
			(left == 1 && colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)
			)
			return BAN5;
	}

	
	if (count == 6){                                                  //中心线6连
		if ((left == 1 && right == 8) || (left==0 && right == 7) )
		return BAN7;
	}
	
	return NOBAN;                                                //返回没有威胁

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
		return BANSIGN6;                 //长连禁手

	if (situation.ban5 == 2 )
		return BANSIGN5;                //第二类四四禁手

	if (ban4 >= 2)
		return BANSIGN4;                //第一类四四禁手

	if (situation.ban2 == 2)
		return BANSIGN3;                //第三类三三禁手

	if (ban2 >= 2)
		return BANSIGN2;               //第二类三三禁手

	if (ban1 >= 1)
		return BANSIGN1;               //第一类三三禁手
	if (situation.noban >= 1)
		return NOBANSIGN;
	
	return NOBANSIGN;                        //没有禁手
}


int Banning::judgeBanningSituation(const int state[15][15], int Px,int Py, int color) {

	Situation situation = { 0 };//记录当前形势变量

	for (int direction = 0; direction < 4; direction++) {                //四个方向,0横，1竖，2左上右下，3右上左下
		int banningtype;
		banningtype = getBanningType(state, Px,Py, color, direction);//取得禁手棋型

		switch (banningtype) {                                         //根据类型对situation设置
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
			//差错控制
			break;
		}
	}

	return giveBanningSign(situation);                                      //根据形势得出禁手标志
}
