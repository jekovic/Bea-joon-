#include <iostream>
#include <vector>
#define MAX 301

using namespace std;

int DP[MAX];
int stage[MAX];

/*
	1��° MAX = 1���
	2��° MAX = 1+1 ���
	3��° MAX = max(1+2, 2+1)
	4��°���ʹ� max(2��° �Ʒ� + ����, 3��° �Ʒ� + 1��° �Ʒ�+ ����)
*/

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		stage[i] = k;
	}
	
	DP[1] = stage[1];
	DP[2] = stage[2] + stage[1];
	DP[3] = max(stage[3] + stage[1], stage[2] + stage[3]);
	for (int i = 4; i <= n; i++) {
		DP[i] = max(DP[i - 2] + stage[i], DP[i - 3] + stage[i - 1] + stage[i]);
	}
	cout << DP[n];
	return 0;
}