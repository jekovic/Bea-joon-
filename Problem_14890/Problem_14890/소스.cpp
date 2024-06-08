#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 101

using namespace std;
int N, L;
int map[MAX][MAX];
int sero[MAX][MAX];

int posible;
// �Ʒ�  -- �� -- ������ -- ���� 
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void garo(int map[][101]) {
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		bool ok = true;
		vector<int> slope(N, 0);	// ����

		for (int j = 0; j < N - 1; j++) {

			if (abs(map[i][j] - map[i][j + 1]) > 1) {
				ok = false;
				break;
			}

			//������ �� (�������� ������)
			if (map[i][j] == map[i][j + 1] + 1) {
				int cur_h = map[i][j + 1];
				for (int k = j + 2; k < j + 1 + L; k++) {
					if (k >= N || map[i][k] != cur_h) {
						ok = false;
						break;
					}
				}
				if (ok) {
					slope[j + L] = true;
				}
				else {
					break;
				}
			}

			//�޿��� ��(�������� ������)
			if (map[i][j] == map[i][j + 1] - 1) {
				int cur_h = map[i][j];
				for (int k = j; k > j - L; k--) {
					if (k < 0 || map[i][k] != cur_h || slope[k]) {
						ok = false;
						break;
					}
				}
				if (!ok)
					break;
			}
		}

		//��� ī��Ʈ
		if (ok == true)
			posible++;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			sero[j][i] = map[i][j];
		}
	}

	garo(map);
	garo(sero);

	cout << posible;

	return 0;
}