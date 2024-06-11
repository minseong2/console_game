#pragma once
#include "Yut.h"
#include <iostream>

class Stone :public Yut
{
public:
	Stone();
	~Stone();
	void SetTogether(bool together);
	int move_piece(Yut* yut);
public:
	int location;
	int x, y = 10;
	int _area=0;
	int _number=0;
	int pre_x = 10;
	int pre_y = 10;
	std::string shape;
private:
	bool isTogether; // 함께 이동하는지 여부
};