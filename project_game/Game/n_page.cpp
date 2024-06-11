#include "n_page.h"
#include<iostream>
#include<Windows.h>
#include"setting.h"
#include<iomanip>

std::string board[11][11];//���� �迭 
int ctn = 48;//�ӽ� ��
int pre_x = 0;//���� ��ġ ����� ����
int pre_y = 0;
#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void set_board()//�� ���� 
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if ((i % 2 == 0) && (j % 2 == 0))//�ش�����
			{
				board[i][j] = "��";
			}
			if (i == 5 && j == 5)
			{
				board[i][j] = "��";
			}
		}
		cout << endl;
	}
	board[2][4] = "";
	board[2][6] = "";
	board[4][2] = "";
	board[6][2] = "";
	board[8][4] = "";
	board[8][6] = "";
	board[4][8] = "";
	board[6][8] = "";

}
void print_board()//�� ��� �ϴ� �Ź� �ϴ���
{
	for (int i = 0; i < 11; i++)
	{
		gotoxy(40, 15 + i);
		for (int j = 0; j < 11; j++)
		{
			if (board[i][j]=="")
			{
				cout << "  ";
			}
			else
			{
				cout << board[i][j];
			}
		}
		cout << "\n\n";
	}
}

void game_start()
{
	system("cls");
	cout << "���ӽ���";
	set_board();
	print_board();
	Sleep(30000);
	return;
}
void game_info()
{
	system("cls");
	cout << "���� ���� : ������ ����";
	Sleep(3000);
	return;
}
void game_exit()
{
	system("cls");
	cout << "���� ����";
	Sleep(3000);
	return;
}


void piece_location(Stone* s,string arr[][11])
{
	if(ctn>48)	arr[pre_x][pre_y] = "��";//���� �� ����
	switch (s->_area)
	{
	case 0://�� ���̽��� �°� x,y ����
	{
		s->x = 10 - (2 * (s->_number));
		s->y = 10;
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;//���� �� ����ϱ� ����
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	case 1:
	{
		s->x = 0;
		s->y = 10 - (2 * (s->_number));
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 2:
	{
		s->x = (2 * (s->_number));
		s->y = 0;
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 3:
	{
		s->x = 10;
		s->y = (2 * (s->_number));
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 4:
	{
		s->x = (2 * (s->_number));
		s->y = (2 * (s->_number));
		if (s->_number > 3)
		{
			s->x = s->x - 2;
			s->y = s->y - 2;
		}
		else if (s->_number == 3)
		{
			s->x = s->x - 1;
			s->y = s->y - 1;
		}
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 5:
	{
		s->x = (2 * (s->_number));
		s->y = 10 - (2 * (s->_number));
		if (s->_number > 3)
		{
			s->x = s->x - 2;
			s->y = s->y + 2;
		}
		arr[s->x][s->y] = ++ctn;
		pre_x = s->x;
		pre_y = s->y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	default:
		break;
	}
	print_board();
	
}