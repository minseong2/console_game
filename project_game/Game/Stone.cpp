#include "Stone.h"
#include <iostream>

using namespace std;;

Stone::Stone() : location(0),_area(0),_number(0), isTogether(false) {}

Stone::~Stone() {}


int Stone::move_piece(Yut* yut)
{
	int next = 0;
	int value = 0;
	if (_area == 6)//임의로 도착 지정
	{
		cout << "말이 결승선을 통과!";
		return 1;
	}
	/*dice(value);*/
	next = yut->Result() + _number;//현재 위치에 윷 나온 값 더한 것(가게될 곳)

	switch (_area)
	{
	case 0://0 단계
	{
		if (next == 5)//다음 위치가 0단계 5번째(코너)
		{
			//std::cout << "5단계로";
			_area = 5;
			_number = 0;

			break;
		}
		else if (next > 5)//5 초과시 1단계
		{
			//std::cout << "1단계로";
			_area = 1;
			_number = next - 5;

			break;
		}
		else // 5 미만시 0단계 잔류
		{
			//std::cout << "0단계잔류";
			_number = next;
			break;
		}
	}
	case 1:
	{
		if (next == 5)//다음 위치가 1단계 5번째(코너)
		{
			//std::cout << "4단계로";
			_area = 4;
			_number = 0;
			break;
		}
		else if (next > 5)//5 초과시 2단계
		{
			//std::cout << "2단계로";
			_area = 2;
			_number = next - 5;
			break;
		}
		else // 5 미만시 0단계 잔류
		{
			//std::cout << "1단계잔류";
			_number = next;
			break;
		}
	}
	case 2:
	{
		if (next >= 5)//5 초과시 3단계
		{
			//std::cout << "3단계로";
			_area = 3;
			_number = next - 5;
			break;
		}
		else // 5 미만시 2단계 잔류
		{
			//std::cout << "2단계잔류";
			_number = next;
			break;
		}
	}
	case 3:
	{
		if (next > 5)//5 초과시 도착
		{
			//std::cout << "도착";
			_area = 6;
			break;
		}
		else // 5 이하시 3단계 잔류
		{
			//std::cout << "3단계잔류";
			_number = next;
			break;
		}
	}
	case 4:
	{
		if (next > 6)//6 초과시 도착
		{
			//std::cout << "도착";
			_area = 6;
			break;
		}
		else // 6 이하시 4단계 잔류
		{
			//std::cout << "4단계잔류";
			_number = next;
			break;
		}
	}
	case 5:
	{
		if (next == 3)//3 일치시 4단계(코너)
		{
			//std::cout << "4단계로";
			_area = 4;
			_number = 3;
			break;
		}
		else if (next >= 6)// 6 이상시 3단계로
		{
			//std::cout << "3단계로";
			_area = 3;
			_number = 0;
			break;
		}
		else
		{
			//std::cout << "5단계잔류";//3아니고 6미만시 5단계 잔류
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
