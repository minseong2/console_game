#pragma once
#include"setting.h"
#include<iostream>
#include<cstdlib>
#include<windows.h>
#include <conio.h>

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


int MAP_X_MAX = 100;
int MAP_Y_MAX = 40;

//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void set_console() {
	system("title ������ ����"); // �ܼ�â �̸� ����
	system("mode con:cols=100 lines=40"); // �ܼ�â ũ�⼳��;

}
//���� �׸���
void title_draw()
{
	
	set_color(white, brown);
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	cout << "��������������������������������������\n";
	set_color(white, black);

}


//Ŀ�� �̵�
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur{};
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(consoleHandle, Cur);
}

//�޴� �׸��� 1.���ӽ��� 2.�������� 3.��������
int menu_draw()
{
	int x = (MAP_X_MAX / 2) - 7;
	int y = (MAP_Y_MAX / 2) + 2;
	int temp;
	gotoxy(x - 2, y);
	cout << "> 1. ���� ����";
	gotoxy(x, y + 1);
	cout << "2. ���� ����";
	gotoxy(x, y + 2);
	cout << "0. ���� ����  \n";
	cin >> temp;
	return temp;
}

void set_color(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}
