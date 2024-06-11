#include "Player.h"
#include"setting.h"
// Player 기본 생성자 -> 생성할때 이름을 물어봄
Player::Player() {
	string name;
	cout << "이름을 입력해주세요.";
	cin >> name;
	_name = name;
}
Player::~Player() {}

// life에 Stone 클래스인 말들을 집어넣는 함수
void Player::Make_stone(Stone* stone) {
	life.push_back(stone);
	isTogether.push_back(false);
}
// 움직인 말의 위치가 나의 다른 말과 위치가 같은 확인하고 같다면 업기
//void Player::Together() {
//	for (int i = 0; i < life.size(); i++) {
//		if (isTogether[i]) {
//			continue; // 이미 업기 상태인 돌은 비교하지 않음
//		}
//		for (int j = i + 1; j < life.size(); j++) {
//			if (life[i]->location != 0 && life[j]->location != 0 && life[i]->location == life[j]->location) {
//				cout << "업기!" << endl;
//
//				isTogether[i] = true; // 업기 상태로 변경
//				isTogether[j] = true; // 업기 상태로 변경
//			}
//			/*else {
//				isTogether[i] = false; 
//				isTogether[j] = false;
//			}*/
//		}
//	}
//	for (bool i : isTogether) {
//		cout << i << " ";
//	}
//	cout << endl;
//}
void Player::Together() {

	
	for (int i = 0; i < life.size(); i++) {
		//if (isTogether[i]) {
		//	continue; // 이미 업기 상태인 돌은 비교하지 않음
		//}
		for (int j = i + 1; j < life.size(); j++) {
			if ((life[i]->_area != 0 || life[i]->_number != 0) && life[i]->_area == life[j]->_area && life[i]->_number == life[j]->_number) {
				gotoxy(44, 32);
				cout << "업기!" << endl;
				
				isTogether[i] = true; // 업기 상태로 변경
				isTogether[j] = true; // 업기 상태로 변경
				return;
			}

		}
		gotoxy(44, 32);
		cout << "             " << endl;
	}
	for (bool i : isTogether) {
		cout << i << " ";
	}
	cout << endl;
}
//void Player::Location_share(int num) {
//	for (int i = 0; i < life.size(); i++) {
//			if (isTogether[i] && isTogether[num] ) {
//				life[i]->location == life[num]->location;
//		}
//	}
//}
 
// 업기를 한 말들은 위치를 공유함
//void Player::Location_share(int num) {
//	int sharedLocation = -1; // 공유할 위치 변수 초기화
//	// num에 해당하는 돌이 공유할 위치를 찾음
//	for (int i = 0; i < life.size(); i++) {
//		if (isTogether[i] && life[i]->location != 0) {
//			sharedLocation = life[i]->location;
//			break; // 찾았으면 반복문 탈출
//		}
//	}
//	// 공유할 위치를 찾은 경우 해당 위치를 모든 돌에 할당
//	if (sharedLocation != -1) {
//		for (int i = 0; i < life.size(); i++) {
//			if (isTogether[i] && life[i]->location != 0) {
//				life[i]->location = sharedLocation;
//			}
//		}
//	}
//}
void Player::Location_share(int num) {
	int sharedX = -1; // 공유할 x 좌표 초기화
	int sharedY = -1; // 공유할 y 좌표 초기화
	int shareArea = -1;
	int shareNumber = -1;
	// num에 해당하는 돌이 공유할 위치를 찾음
	for (int i = 0; i < life.size(); i++) {
		if (isTogether[i] && (life[i]->_area != 0 || life[i]->_number != 0)) {
			sharedX = life[i]->x;
			sharedY = life[i]->y;
			shareArea = life[i]->_area;
			shareNumber = life[i]->_number;
			break; // 찾았으면 반복문 탈출
		}
	}
	// 공유할 위치를 찾은 경우 해당 위치를 모든 돌에 할당
	if (sharedX != -1 && sharedY != -1) {
		for (int i = 0; i < life.size(); i++) {
			if (isTogether[i] && (life[i]->_area != 0 || life[i]->_number != 0)) {
				life[i]->x = sharedX;
				life[i]->y = sharedY;
				life[i]->_area = shareArea;
				life[i]->_number = shareNumber;
			}
		}
	}
}

// 움직인 말과 상대방의 말의 위치가 같은지 확인하고 같다면 잡음
int Player::Eat(Player* opponent) {

	
	check = 0;
	for (int i = 0; i < life.size(); i++) {
		for (int j = 0; j < opponent->life.size(); j++) {
			if ((life[i]->_area != 0 || life[i]->_number != 0) && (life[i]->_area == opponent->life[j]->_area && life[i]->_number == opponent->life[j]->_number)) {
				gotoxy(44, 30);
				cout << "잡기!" << endl;
				// 상대방의 돌과 겹칠 경우
				opponent->life[j]->x = 10; // 상대방의 돌의 위치를 0으로 만듭니다.
				opponent->life[j]->y = 10;
				opponent->life[j]->_area = 0; // 상대방의 돌의 위치를 0으로 만듭니다.
				opponent->life[j]->_number = 0;
				opponent->life[j]->pre_x = 10; // 상대방의 돌의 위치를 0으로 만듭니다.
				opponent->life[j]->pre_y = 10;
				check = 1;
				return 1;

			}
			

		}
	}
	gotoxy(44, 30); 
	cout << "            " << endl;
	return 0; // 겹치는 돌이 없는 경우 0을 반환
}