#include "Stone.h"
#include <iostream>

using namespace std;;

Stone::Stone() : location(0), isTogether(false) {}

Stone::~Stone() {}

//int Stone::Move(Yut* yut) {
//	location += yut -> result;
//	return location;
//
//}
void Stone::move_piece()
{
	int next = 0;
	while (1)
	{
		int value = 0;
		if (_area == 6)//���Ƿ� ���� ����
		{
			cout << "���� ��¼��� ���!";
			break;
		}std::cout << "�������� : ";
		std::cin >> value;
		/*dice(value);*/
		next = value + _number;//���� ��ġ�� �� ���� �� ���� ��(���Ե� ��)

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
		default:
			break;
		}
		//piece_location(s, board);//��ġ�� �������
	}
}
void piece_location(Stone* s, char arr[][11])
{
	if (ctn > 48)	arr[pre_x][pre_y] = '@';//���� �� ����
	switch (s._area)
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
void Stone::SetTogether(bool together) {
	isTogether = together;
}
