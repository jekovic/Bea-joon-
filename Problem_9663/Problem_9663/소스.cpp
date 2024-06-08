#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 16
using namespace std;

/*
	�ٴ� �ϳ����� ��ġ�ϰ� �ϱ�
*/

/*
�� ��, ���� ��� ���� �ִ��� Ȯ���ϴ� ����� �ſ� ����������, 
�밢���� ��ġ���ִ����� ã�� ����� �ټ� ��ٷο� �� �ִ�. 

���� �⺻������ �밢���� �����ϴ� ��ǥ�� ���,
(X, Y)�� �밢���� ��ġ�� ��ǥ (A, B)���� �ݵ�� X-A = Y-B�� �����Ѵ�.

���� ��� (0 , 1)�� �������� ������, 
�밢���� �ִ� ���� (1, 2) (2, 3) �� 
�ݵ�� (0 - 1) = (1 - 2) = -1, (0 - 2) = (1 - 3) = -2�� �����Ѵٴ� ���̴�.

���� �츮�� ������ col�̶�� 1���� �迭�� ���ǿ� ���� 
X��ǥ�� Y��ǥ�� ���̰� ������ ���� ���� ��� �ش� ���� �밢���� �ִٰ� �Ǵ��� �� �ִ�.

*/
int N;
int col[MAX];
int result;

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] or abs(col[level] - col[i]) == level - i)
			return false;
		//col[i]�� x ��ǥ, i�� y��ǥ�̱⿡ ���̰� �����ϸ� �밢���� �ִٰ� �����ϱ� 
	}
	return true;
}

void dfs(int cnt)
{
	if (cnt == N) {
		result++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[cnt] = i;
			if (check(cnt)) {
				dfs(cnt + 1);
			}
		}
	}
}

int main() {

	cin >> N;
	dfs(0);
	cout << result;

	return 0;
}