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

//콘솔 창의 크기와 제목을 지정하는 함수
void set_console() {
	system("title 윷놀이 게임"); // 콘솔창 이름 설정
	system("mode con:cols=100 lines=40"); // 콘솔창 크기설정;

}
//제목 그리기
void title_draw()
{
	
	set_color(white, brown);
	cout << "□□□■■■■■■■□□□□□■□□□□□□□□□□□□□□□□□□□■□\n";
	cout << "□□■■□□□□□■■□□□□■□□□□□□□□□□□■■■■□□□□■□\n";
	cout << "□□■■□□□□□■■□□□□■□□□□□□□□□□■■□□■■□□□■□\n";
	cout << "□□□■■■■■■■□□□□□■■■■■■■■■□□■□□□□■□□□■□\n";
	cout << "□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□□■□□□■□\n";
	cout << "■■■■■■■■■■■■■□■■■■■■■■■■■□■□□□□■□□□■□\n";
	cout << "□□□■■□□□■■□□□□□□□□□□□□□□□□■□□□□■□□□■□\n";
	cout << "□□□□■□■□■□□□□□□■■■■■■■■□□□■■□□■■□□□■□\n";
	cout << "□□■■■■■■■■■□□□□□□□□□□□■□□□□■■■■□□□□■□\n";
	cout << "□□□□□■■■□□□□□□□■■■■■■■■□□□□□□□□□□□□■□\n";
	cout << "□□□□■■□■■□□□□□□■□□□□□□□□□□□□□□□□□□□■□\n";
	cout << "□□■■■□□□■■■□□□□■■■■■■■■■□□□□□□□□□□□■□\n";
	set_color(white, black);

}


//커서 이동
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur{};
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(consoleHandle, Cur);
}

//메뉴 그리기 1.게임시작 2.게임정보 3.게임종료
int menu_draw()
{
	int x = (MAP_X_MAX / 2) - 7;
	int y = (MAP_Y_MAX / 2) + 2;
	int temp;
	gotoxy(x - 2, y);
	cout << "> 1. 게임 시작";
	gotoxy(x, y + 1);
	cout << "2. 게임 정보";
	gotoxy(x, y + 2);
	cout << "0. 게임 종료  \n";
	cin >> temp;
	return temp;
}

void set_color(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}
