#include "Player.h"
#include"setting.h"
// Player �⺻ ������ -> �����Ҷ� �̸��� ���
Player::Player() {
	string name;
	cout << "�̸��� �Է����ּ���.";
	cin >> name;
	_name = name;
}
Player::~Player() {}

// life�� Stone Ŭ������ ������ ����ִ� �Լ�
void Player::Make_stone(Stone* stone) {
	life.push_back(stone);
	isTogether.push_back(false);
}
// ������ ���� ��ġ�� ���� �ٸ� ���� ��ġ�� ���� Ȯ���ϰ� ���ٸ� ����
//void Player::Together() {
//	for (int i = 0; i < life.size(); i++) {
//		if (isTogether[i]) {
//			continue; // �̹� ���� ������ ���� ������ ����
//		}
//		for (int j = i + 1; j < life.size(); j++) {
//			if (life[i]->location != 0 && life[j]->location != 0 && life[i]->location == life[j]->location) {
//				cout << "����!" << endl;
//
//				isTogether[i] = true; // ���� ���·� ����
//				isTogether[j] = true; // ���� ���·� ����
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
		//	continue; // �̹� ���� ������ ���� ������ ����
		//}
		for (int j = i + 1; j < life.size(); j++) {
			if ((life[i]->_area != 0 || life[i]->_number != 0) && life[i]->_area == life[j]->_area && life[i]->_number == life[j]->_number) {
				gotoxy(44, 32);
				cout << "����!" << endl;
				
				isTogether[i] = true; // ���� ���·� ����
				isTogether[j] = true; // ���� ���·� ����
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
 
// ���⸦ �� ������ ��ġ�� ������
//void Player::Location_share(int num) {
//	int sharedLocation = -1; // ������ ��ġ ���� �ʱ�ȭ
//	// num�� �ش��ϴ� ���� ������ ��ġ�� ã��
//	for (int i = 0; i < life.size(); i++) {
//		if (isTogether[i] && life[i]->location != 0) {
//			sharedLocation = life[i]->location;
//			break; // ã������ �ݺ��� Ż��
//		}
//	}
//	// ������ ��ġ�� ã�� ��� �ش� ��ġ�� ��� ���� �Ҵ�
//	if (sharedLocation != -1) {
//		for (int i = 0; i < life.size(); i++) {
//			if (isTogether[i] && life[i]->location != 0) {
//				life[i]->location = sharedLocation;
//			}
//		}
//	}
//}
void Player::Location_share(int num) {
	int sharedX = -1; // ������ x ��ǥ �ʱ�ȭ
	int sharedY = -1; // ������ y ��ǥ �ʱ�ȭ
	int shareArea = -1;
	int shareNumber = -1;
	// num�� �ش��ϴ� ���� ������ ��ġ�� ã��
	for (int i = 0; i < life.size(); i++) {
		if (isTogether[i] && (life[i]->_area != 0 || life[i]->_number != 0)) {
			sharedX = life[i]->x;
			sharedY = life[i]->y;
			shareArea = life[i]->_area;
			shareNumber = life[i]->_number;
			break; // ã������ �ݺ��� Ż��
		}
	}
	// ������ ��ġ�� ã�� ��� �ش� ��ġ�� ��� ���� �Ҵ�
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

// ������ ���� ������ ���� ��ġ�� ������ Ȯ���ϰ� ���ٸ� ����
int Player::Eat(Player* opponent) {

	
	check = 0;
	for (int i = 0; i < life.size(); i++) {
		for (int j = 0; j < opponent->life.size(); j++) {
			if ((life[i]->_area != 0 || life[i]->_number != 0) && (life[i]->_area == opponent->life[j]->_area && life[i]->_number == opponent->life[j]->_number)) {
				gotoxy(44, 30);
				cout << "���!" << endl;
				// ������ ���� ��ĥ ���
				opponent->life[j]->x = 10; // ������ ���� ��ġ�� 0���� ����ϴ�.
				opponent->life[j]->y = 10;
				opponent->life[j]->_area = 0; // ������ ���� ��ġ�� 0���� ����ϴ�.
				opponent->life[j]->_number = 0;
				opponent->life[j]->pre_x = 10; // ������ ���� ��ġ�� 0���� ����ϴ�.
				opponent->life[j]->pre_y = 10;
				check = 1;
				return 1;

			}
			

		}
	}
	gotoxy(44, 30); 
	cout << "            " << endl;
	return 0; // ��ġ�� ���� ���� ��� 0�� ��ȯ
}