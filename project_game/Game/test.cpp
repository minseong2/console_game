#include "Stone.h"
#include <iostream>

using namespace std;

void move_piece(Stone& s)
{
	int next = 0;
	while (1)
	{
		int value = 0;
		if (s._area == 6)//임의로 도착 지정
		{
			cout << "말이 결승선을 통과!";
			break;
		}std::cout << "윷던지기 : ";
		std::cin >> value;
		dice(value);
		next = value + s._number;//현재 위치에 윷 나온 값 더한 것(가게될 곳)

		switch (s._area)
		{
		case 0://0 단계
		{
			if (next == 5)//다음 위치가 0단계 5번째(코너)
			{
				//std::cout << "5단계로";
				s._area = 5;
				s._number = 0;

				break;
			}
			else if (next > 5)//5 초과시 1단계
			{
				//std::cout << "1단계로";
				s._area = 1;
				s._number = next - 5;

				break;
			}
			else // 5 미만시 0단계 잔류
			{
				//std::cout << "0단계잔류";
				s._number = next;
				break;
			}
		}
		case 1:
		{
			if (next == 5)//다음 위치가 1단계 5번째(코너)
			{
				//std::cout << "4단계로";
				s._area = 4;
				s._number = 0;
				break;
			}
			else if (next > 5)//5 초과시 2단계
			{
				//std::cout << "2단계로";
				s._area = 2;
				s._number = next - 5;
				break;
			}
			else // 5 미만시 0단계 잔류
			{
				//std::cout << "1단계잔류";
				s._number = next;
				break;
			}
		}
		case 2:
		{
			if (next >= 5)//5 초과시 3단계
			{
				//std::cout << "3단계로";
				s._area = 3;
				s._number = next - 5;
				break;
			}
			else // 5 미만시 2단계 잔류
			{
				//std::cout << "2단계잔류";
				s._number = next;
				break;
			}
		}
		case 3:
		{
			if (next > 5)//5 초과시 도착
			{
				//std::cout << "도착";
				s._area = 6;
				break;
			}
			else // 5 이하시 3단계 잔류
			{
				//std::cout << "3단계잔류";
				s._number = next;
				break;
			}
		}
		case 4:
		{
			if (next > 6)//6 초과시 도착
			{
				//std::cout << "도착";
				s._area = 6;
				break;
			}
			else // 6 이하시 4단계 잔류
			{
				//std::cout << "4단계잔류";
				s._number = next;
				break;
			}
		}
		case 5:
		{
			if (next == 3)//3 일치시 4단계(코너)
			{
				//std::cout << "4단계로";
				s._area = 4;
				s._number = 3;
				break;
			}
			else if (next >= 6)// 6 이상시 3단계로
			{
				//std::cout << "3단계로";
				s._area = 3;
				s._number = 0;
				break;
			}
			else
			{
				//std::cout << "5단계잔류";//3아니고 6미만시 5단계 잔류
				s._number = next;
				break;
			}
		}
		default:
			break;
		}
		piece_location(s, board);//위치가 어디인지
	}
}

void piece_location(Stone& s, char arr[][11])
{
	if (ctn > 48)	arr[pre_x][pre_y] = '@';//이전 값 원복
	switch (s._area)
	{
	case 0://각 케이스에 맞게 x,y 변경
	{
		int x = 10 - (2 * (s._number));
		int y = 10;
		arr[x][y] = ++ctn;
		pre_x = x;//이전 값 기억하기 위해
		pre_y = y;
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
		break;
	}
	case 1:
	{
		int x = 0;
		int y = 10 - (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
		break;

	}
	case 2:
	{
		int x = (2 * (s._number));
		int y = 0;
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
		break;

	}
	case 3:
	{
		int x = 10;
		int y = (2 * (s._number));
		arr[x][y] = ++ctn;
		pre_x = x;
		pre_y = y;
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
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
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
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
		//std::cout << "현재 위치 : " << x << " " << y << std::endl;
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
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		cout << "■□■ ■×■ ■×■ ■×■\n";
//		cout << "■□■ ■×■ ■×■ ■×■\n";
//		cout << "■□■ ■×■ ■×■ ■×■\n";
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		break;
//	}
//	case 2:
//	{
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		cout << "■□■ ■□■ ■×■ ■×■\n";
//		cout << "■□■ ■□■ ■×■ ■×■\n";
//		cout << "■□■ ■□■ ■×■ ■×■\n";
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		break;
//
//	}
//	case 3:
//	{
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		cout << "■□■ ■□■ ■□■ ■×■\n";
//		cout << "■□■ ■□■ ■□■ ■×■\n";
//		cout << "■□■ ■□■ ■□■ ■×■\n";
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		break;
//
//	}
//	case 4:
//	{
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		cout << "■□■ ■□■ ■□■ ■□■\n";
//		cout << "■□■ ■□■ ■□■ ■□■\n";
//		cout << "■□■ ■□■ ■□■ ■□■\n";
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		break;
//
//	}
//	case 5:
//	{
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		cout << "■×■ ■×■ ■×■ ■×■\n";
//		cout << "■×■ ■×■ ■×■ ■×■\n";
//		cout << "■×■ ■×■ ■×■ ■×■\n";
//		cout << "■■■ ■■■ ■■■ ■■■\n";
//		break;
//
//	}
//	default:
//		break;
//	}
//
//
//}
