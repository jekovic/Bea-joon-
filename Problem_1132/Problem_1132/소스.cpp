#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
long long res;
long long alpha[10];
bool nonzero[10];

/*
	�� ���ĺ��� �����ϴ� �ڸ����� ����
	���� ���� �ڸ����� �����ϴ� ���ĺ����� 9 ȹ��
*/

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		nonzero[s[0] - 'A'] = 1; //ù ��° �ڸ��� �ִ� ���ĺ� 0 X
		long long k = 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			alpha[s[j] - 'A'] += k;
			k *= 10;
		}
	}
}

void solve() {
	bool flag = 0;
	for (int i = 0; i < 10; i++) {
		if (!alpha[i])
			flag = 1;
	}

	if (!flag) {
		//���ĺ��� ��� ���Ǹ� ���� ���� �Ϳ� 0 ����
		long long min = 1e19;
		int idx;
		for (int i = 0; i < 10; i++) {
			if (!nonzero[i] and alpha[i] < min) {
				min = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;
	}
	sort(alpha, alpha + 10, greater<>()); // �������� ����

	for (int i = 0, j = 9; i < 10; i++, j--) {
		res += alpha[i] * j;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << res;

	return 0;
}