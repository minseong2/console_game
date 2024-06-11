#include "Stone.h"
#include <iostream>

using namespace std;;

Stone::Stone() : location(0),_area(0),_number(0), isTogether(false) {}

Stone::~Stone() {}


int Stone::move_piece(Yut* yut)
{
	int next = 0;
	int value = 0;
	if (_area == 6)//���Ƿ� ���� ����
	{
		cout << "���� ��¼��� ���!";
		return 1;
	}
	/*dice(value);*/
	next = yut->Result() + _number;//���� ��ġ�� �� ���� �� ���� ��(���Ե� ��)

	switch (_area)
	{
	case 0://0 �ܰ�
	{
		if (next == 5)//���� ��ġ�� 0�ܰ� 5��°(�ڳ�)
		{
			//std::cout << "5�ܰ��";
			_area = 5;
			_number = 0;

			break;
		}
		else if (next > 5)//5 �ʰ��� 1�ܰ�
		{
			//std::cout << "1�ܰ��";
			_area = 1;
			_number = next - 5;

			break;
		}
		else // 5 �̸��� 0�ܰ� �ܷ�
		{
			//std::cout << "0�ܰ��ܷ�";
			_number = next;
			break;
		}
	}
	case 1:
	{
		if (next == 5)//���� ��ġ�� 1�ܰ� 5��°(�ڳ�)
		{
			//std::cout << "4�ܰ��";
			_area = 4;
			_number = 0;
			break;
		}
		else if (next > 5)//5 �ʰ��� 2�ܰ�
		{
			//std::cout << "2�ܰ��";
			_area = 2;
			_number = next - 5;
			break;
		}
		else // 5 �̸��� 0�ܰ� �ܷ�
		{
			//std::cout << "1�ܰ��ܷ�";
			_number = next;
			break;
		}
	}
	case 2:
	{
		if (next >= 5)//5 �ʰ��� 3�ܰ�
		{
			//std::cout << "3�ܰ��";
			_area = 3;
			_number = next - 5;
			break;
		}
		else // 5 �̸��� 2�ܰ� �ܷ�
		{
			//std::cout << "2�ܰ��ܷ�";
			_number = next;
			break;
		}
	}
	case 3:
	{
		if (next > 5)//5 �ʰ��� ����
		{
			//std::cout << "����";
			_area = 6;
			break;
		}
		else // 5 ���Ͻ� 3�ܰ� �ܷ�
		{
			//std::cout << "3�ܰ��ܷ�";
			_number = next;
			break;
		}
	}
	case 4:
	{
		if (next > 6)//6 �ʰ��� ����
		{
			//std::cout << "����";
			_area = 6;
			break;
		}
		else // 6 ���Ͻ� 4�ܰ� �ܷ�
		{
			//std::cout << "4�ܰ��ܷ�";
			_number = next;
			break;
		}
	}
	case 5:
	{
		if (next == 3)//3 ��ġ�� 4�ܰ�(�ڳ�)
		{
			//std::cout << "4�ܰ��";
			_area = 4;
			_number = 3;
			break;
		}
		else if (next >= 6)// 6 �̻�� 3�ܰ��
		{
			//std::cout << "3�ܰ��";
			_area = 3;
			_number = 0;
			break;
		}
		else
		{
			//std::cout << "5�ܰ��ܷ�";//3�ƴϰ� 6�̸��� 5�ܰ� �ܷ�
			_number = next;
			break;
		}
	}
	{
	default:
		break;
	}

	}

}

void Stone::SetTogether(bool together) {
	isTogether = together;
}
