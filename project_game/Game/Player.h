#pragma once
#include <vector>
#include <iostream>
#include "Stone.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void Make_stone(Stone* stone);
	void Together();
	int Eat(Player* opponent);
	void Location_share(int num);
public:
	vector<Stone*> life; // ���;ȿ� �� ������ ����
	string _name;
	vector<bool> isTogether; // ��ġ�� ������ �����ϴ� ���� trur��� ��ġ�� ����
	int check; // ������ ���� ��ġ�� ���ٸ� ��ȯ�� ����
};

