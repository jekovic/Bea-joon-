#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101

using namespace std;
/*
	�Ӹ� ��ǥ, ���� ��ǥ
*/

int map[MAX][MAX];
int n;
int second; // result

int len = 1;
deque<pair<int, int>> s;
vector<pair<int, int>> apple;
vector<int> a[MAX];
queue<pair<int, char>> m;

// �ð� ���� -> ��, �Ʒ�, ��, �� 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
/*
	���̳� �ڱ� �� ��ǥ�߿� ������ true;
*/
bool colision_detect(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n) {
		return true;
	}
	for (int i = 0; i != s.size()-1; i++) {
		if (x == s[i].first and y == s[i].second) {
			return true;
		}
	}
	return false;
}

int direction = 0;

void def_di(char c) {
	if (c == 'D') {// �ð����
		direction++;
		direction %= 4;
	}
	else if (c == 'L') { // �ݽð�
		direction--;
		if (direction < 0) {
			direction += 4;
		}
	}
}
/*	
	��� ����
*/
bool face_apple(int x, int y) {
	for (int i = 0; i != apple.size(); i++) {
		if (apple[i].first == x && apple[i].second == y) {
			apple.erase(apple.begin() + i);
			return true;
		}
	}
	return false;
}

void move(){
	
	while (1) {
		int x = s.back().first;
		int y = s.back().second;
		
		
		second++;
		x += dx[direction];
		y += dy[direction];

		if (!m.empty()) {
			if (second == m.front().first) {
				if (m.front().second == 'D')
				{
					def_di('D');
				}
				else if (m.front().second == 'L') {
					def_di('L');
				}
				m.pop();
			}
		}

		//��� ������ ��
		if (face_apple(x, y)) {
			s.push_back({ x,y });
			if (colision_detect(x, y)) {
				break;
			}

		}
		//�׳�
		else {
			s.push_back({ x,y });
			if (colision_detect(x, y)) {
				break;
			}
			s.pop_front();
		}	
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> k;

	//���
	while (k--) {
		int q, w;
		cin >> q >> w;
		apple.push_back({ q, w });
	}

	//���� ��ȯ
	int d;
	cin >> d;
	while (d--) {
		int temp;
		char c;
		cin >> temp >> c;
		m.push({ temp, c });
	}

	s.push_back({ 1,1 });
	move();

	cout << second;

	return 0;
}