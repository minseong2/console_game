#include "Stone.h"
#include <iostream>

using namespace std;

void move_piece(Stone& s)
{
	int next = 0;
	while (1)
	{
		int value = 0;
		if (s._area == 6)//���Ƿ� ���� ����
		{
			cout << "���� ��¼��� ���!";
			break;
		}std::cout << "�������� : ";
		std::cin >> value;
		dice(value);
		next = value + s._number;//���� ��ġ�� �� ���� �� ���� ��(���Ե� ��)

		switch (s._area)
		{
		case 0://0 �ܰ�
		{
			if (next == 5)//���� ��ġ�� 0�ܰ� 5��°(�ڳ�)
			{
				//std::cout << "5�ܰ��";
				s._area = 5;
				s._number = 0;

				break;
			}
			else if (next > 5)//5 �ʰ��� 1�ܰ�
			{
				//std::cout << "1�ܰ��";
				s._area = 1;
				s._number = next - 5;

				break;
			}
			else // 5 �̸��� 0�ܰ� �ܷ�
			{
				//std::cout << "0�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 1:
		{
			if (next == 5)//���� ��ġ�� 1�ܰ� 5��°(�ڳ�)
			{
				//std::cout << "4�ܰ��";
				s._area = 4;
				s._number = 0;
				break;
			}
			else if (next > 5)//5 �ʰ��� 2�ܰ�
			{
				//std::cout << "2�ܰ��";
				s._area = 2;
				s._number = next - 5;
				break;
			}
			else // 5 �̸��� 0�ܰ� �ܷ�
			{
				//std::cout << "1�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 2:
		{
			if (next >= 5)//5 �ʰ��� 3�ܰ�
			{
				//std::cout << "3�ܰ��";
				s._area = 3;
				s._number = next - 5;
				break;
			}
			else // 5 �̸��� 2�ܰ� �ܷ�
			{
				//std::cout << "2�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 3:
		{
			if (next > 5)//5 �ʰ��� ����
			{
				//std::cout << "����";
				s._area = 6;
				break;
			}
			else // 5 ���Ͻ� 3�ܰ� �ܷ�
			{
				//std::cout << "3�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 4:
		{
			if (next > 6)//6 �ʰ��� ����
			{
				//std::cout << "����";
				s._area = 6;
				break;
			}
			else // 6 ���Ͻ� 4�ܰ� �ܷ�
			{
				//std::cout << "4�ܰ��ܷ�";
				s._number = next;
				break;
			}
		}
		case 5:
		{
			if (next == 3)//3 ��ġ�� 4�ܰ�(�ڳ�)
			{
				//std::cout << "4�ܰ��";
				s._area = 4;
				s._number = 3;
				break;
			}
			else if (next >= 6)// 6 �̻�� 3�ܰ��
			{
				//std::cout << "3�ܰ��";
				s._area = 3;
				s._number = 0;
				break;
			}
			else
			{
				//std::cout << "5�ܰ��ܷ�";//3�ƴϰ� 6�̸��� 5�ܰ� �ܷ�
				s._number = next;
				break;
			}
		}
		default:
			break;
		}
		piece_location(s, board);//��ġ�� �������
	}
}

void piece_location(Stone& s, char arr[][11])
{
	if (ctn > 48)	arr[pre_x][pre_y] = '@';//���� �� ����
	switch (s._area)
	{
	case 0://�� ���̽��� �°� x,y ����
	{
		int x = 10 - (2 * (s._number));
		int y = 10;
		arr[x][y] = ++ctn;
		pre_x = x;//���� �� ����ϱ� ����
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	case 1:
	{
		int x = 0;
		int y = 10 - (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 2:
	{
		int x = (2 * (s._number));
		int y = 0;
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 3:
	{
		int x = 10;
		int y = (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 4:
	{
		int x = (2 * (s._number));
		int y = (2 * (s._number));
		if (s._number > 3)
		{
			x = x - 2;
			y = y - 2;
		}
		else if (s._number == 3)
		{
			x = x - 1;
			y = y - 1;
		}
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;

	}
	case 5:
	{
		int x = (2 * (s._number));
		int y = 10 - (2 * (s._number));
		if (s._number > 3)
		{
			x = x - 2;
			y = y + 2;
		}
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "���� ��ġ : " << x << " " << y << std::endl;
		break;
	}
	default:
		break;
	}
	print_board();

}
//void dice(int value)
//
//{
//	gotoxy(0, 15);
//	switch (value)
//	{
//	case 1:
//	{
//		cout << "���� ���� ���� ����\n";
//		cout << "���� �᡿�� �᡿�� �᡿��\n";
//		cout << "���� �᡿�� �᡿�� �᡿��\n";
//		cout << "���� �᡿�� �᡿�� �᡿��\n";
//		cout << "���� ���� ���� ����\n";
//		break;
//	}
//	case 2:
//	{
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� �᡿�� �᡿��\n";
//		cout << "���� ���� �᡿�� �᡿��\n";
//		cout << "���� ���� �᡿�� �᡿��\n";
//		cout << "���� ���� ���� ����\n";
//		break;
//
//	}
//	case 3:
//	{
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� ���� �᡿��\n";
//		cout << "���� ���� ���� �᡿��\n";
//		cout << "���� ���� ���� �᡿��\n";
//		cout << "���� ���� ���� ����\n";
//		break;
//
//	}
//	case 4:
//	{
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� ���� ����\n";
//		cout << "���� ���� ���� ����\n";
//		break;
//
//	}
//	case 5:
//	{
//		cout << "���� ���� ���� ����\n";
//		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
//		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
//		cout << "�᡿�� �᡿�� �᡿�� �᡿��\n";
//		cout << "���� ���� ���� ����\n";
//		break;
//
//	}
//	default:
//		break;
//	}
//
//
//}
