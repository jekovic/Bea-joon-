#include <iostream>
#include <vector>
int N;

using namespace std;
vector<vector<int> > board;

//4����
int dy[] = { 0,1,0,-1 };
int dx[] = { -1, 0,1,0 };

// �����̴� ���� ����
double p[9] = { 0.05, 0.1, 0.1, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01 };
/*
 * �����̴� �𷡿� ���� dy, dx 2���� ����
 * ù ��° ������ ����
 * �� ��° ������ ���⿡ ���� �����̴� ���� dy, dx
*/
int m_dy[4][10] = {
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{-2,-1,-1,0,0,0,0,1,1,-1}
};
int m_dx[4][10] = {
	{-2,-1,-1,0,0,0,0,1,1,-1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0}
};
int result = 0;
int cnt = 0;

void check() {
	int y = N / 2, x = N / 2; // �迭�� �߰� ��ǥ
	int a;
	int dist = 1;
	int d = 0; // ���� ���� ( 0 : ��, 1 : ��, 2 : ��, 3 : ��)
	int cnt = 0; // �� �� �̵� Ȯ�ο� count ����
	while (1) {
		cnt++;

		//dist��ŭ d�������� �̵�
		for (int m = 0; m < dist; m++) {
			int ny = y + dy[d];  // d �������� �̵�
			int nx = x + dx[d];  // d �������� �̵�
			y = ny;
			x = nx;
			a = board[ny][nx]; // �̵��� �� 
			for (int k = 0; k < 9; k++) {
				int m_ny = ny + m_dy[d][k]; //�𳯸��� �� y ��ǥ
				int m_nx = nx + m_dx[d][k]; //�𳯸��� �� x ��ǥ

				int sand = (int)(board[ny][nx] * p[k]); //�𳯸��� �� ��
				a -= sand; // �̵��� �𷡿��� �𳯸��� �𷡸� ����
				if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N)  // ���� ������ �̵��� ��� result�� �𳯸� �𷡸� �߰�
					result += sand;
				else   // ���� ���� ��� �ش� ��ǥ�� �𳯸��� �� �� �߰�
					board[m_ny][m_nx] += sand;

			}
			//������ �� �̵�
			int m_ny = ny + m_dy[d][9];
			int m_nx = nx + m_dx[d][9];
			if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N) {
				result += a;
			}
			else
				board[m_ny][m_nx] += a;

			board[ny][nx] = 0; // �̵� �� �� = 0���� ����
			if (ny == 0 && nx == 0) //�̵� �� ��ǥ�� (0, 0)�� ��� ����
				return;
		}
		if (cnt == 2) {
			//�� �� �̵��� ��� dist+=1
			dist++;
			cnt = 0;
		}
		d = (d + 1) % 4; // �̵� ������ �ٲ�
	}
}
int main()
{
	//�Է�
	cin >> N;
	board = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//�� �̵�
	check();

	//��� ���
	cout << result;
}