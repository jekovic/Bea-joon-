//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cstring>
//
//using namespace std;
//
//int N, K;
//int c_turn;
//
//// �ε���
//vector<int> robot;
//int robot_index;
//
//class belt_status {
//public:
//	int durable;
//	bool isrobot;
//	belt_status(int q) {
//		this->durable = q;
//		this->isrobot = false;
//	}
//};
//
//vector<belt_status> belt;
//
//bool check_Durability() {
//	int cnt = 0;
//	for (auto& a : belt) {
//		if (a.durable == 0)
//			cnt++;
//	}
//	if (cnt >= K) {
//		return false;
//	}
//	return true;
//}
//
//void input() {
//
//	cin >> N >> K;
//
//	for (int i = 0; i < 2 * N; i++) {
//		int q;
//		cin >> q;
//		belt.push_back(belt_status(q));
//	}
//}
//
//void down_robot() {
//	if (belt[N - 1].isrobot == true) {
//		belt[N - 1].isrobot = false;
//		belt[N].durable--;
//		belt[N].isrobot = true;
//	}
//
//	for (int i = 0; i != robot.size(); i++) {
//		if (robot[i] == N - 1) {
//			robot[i] = N;
//		}
//	}
//}
//
//void move_robot() {
//	for (int i = 0; i != robot.size(); i++) {
//		int idx = robot[i];
//		if (idx == 2 * N - 1) {
//			if (belt[0].isrobot == false and belt[0].durable >= 1) {
//				robot[i] = 0;
//				belt[0].isrobot = true;
//				belt[0].durable--;
//				belt[idx].isrobot = false;
//			}
//		}
//		else {
//			if (belt[++idx].isrobot == false and belt[++idx].durable >= 1) {
//				belt[idx].isrobot = false;
//				robot[i]++;
//				belt[idx+1].isrobot = true;
//				belt[idx+1].durable--;
//				
//			}
//		}
//	}
//	down_robot();
//}
//
//void move() {
//	
//	while (1)
//	{	
//		c_turn++;
//
//		// 1. ȸ��
//		auto temp = belt.back();
//		belt.pop_back();
//		belt.insert(belt.begin(), temp);
//		if (belt[N - 1].isrobot == true) {
//			belt[N - 1].isrobot = false;
//			belt[N].durable--;
//			belt[N].isrobot = true;
//		}
//
//		for (int i = 0; i != robot.size(); i++) {
//			robot[i]++;
//			if (robot[i] == 2 * N - 1) {
//				robot[i] = 0;
//			}
//			else if (robot[i] == N - 1) {
//				robot[i] = N;
//			}
//		}
//		
//
//		//2. �κ� �̵�
//		move_robot();
//
//		//3 �ø��� ĭ�� �κ� �ø��� 
//		if (belt[0].durable > 0 and belt[0].isrobot == false) {
//			belt[0].isrobot= true;
//			belt[0].durable--;
//			robot.push_back(0);
//		}
//
//		//4	
//		if (!check_Durability())	break;
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	input();
//
//	move();
//
//	cout << c_turn;
// 
//
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;
int n, k;
int belt[202];
bool robot[202] = { 0 };
int start_pos = 0;
int end_pos;
int inital_robot_pos = -1;
int result = 1;
int cnt = 0;
bool stop = false;

void rotation_belt() {
    if (start_pos == 0) // 0�̸� �� ���� �ε����� �ű�
        start_pos = 2 * n - 1;
    else
        start_pos--;

    if (end_pos == 0) // 0�̸� �� ���� �ε����� �ű�
        end_pos = 2 * n - 1;
    else
        end_pos--;

    if (robot[end_pos])
        robot[end_pos] = false;
}

void move_robot() {
    if (inital_robot_pos != -1) {
        // ù��° �ܰ迡���� �κ��� ���� ������ �н�
        int idx = end_pos;
        for (int i = 0; i < n - 1;i++) {
            int next = idx; // �κ��� �� ���� ��ġ
            if (idx == 0)
                idx = 2 * n - 1; // ���� ��ġ      
            else
                idx--;

            if (!robot[next] && robot[idx] && belt[next] > 0) {
                // ���� ��ġ�� �κ��� ������
                // ���� ��ġ�� �κ� ���� �ϴ���
                // ���� ��ġ�� �������� 0���� ū��
                belt[next] -= 1; // ������ ����
                if (belt[next] == 0) { // �������� 0�̸�
                    cnt++; // ������ 0 ���� �߰�
                    if (cnt >= k) {
                        stop = true; // ���� flag
                        break;
                    }
                }
                robot[next] = true; // ���� ��ǥ �κ� true
                robot[idx] = false; // ���� ��ǥ �κ��� �Ű����� false
            }
        }
        robot[end_pos] = false; // ������ ��ġ �κ� ������

    }
}

void put_robot() {
    if (belt[start_pos] > 0) {
        belt[start_pos] -= 1; // ������ ����
        if (belt[start_pos] == 0) { // ���� ����
            cnt++;
            if (cnt >= k) {
                stop = true;
            }
        }
        robot[start_pos] = true; // �κ� �ø�
        inital_robot_pos = 0; // �κ� �ø��� ����.
    }
}

int main() {
    cin >> n >> k;
    int temp;
    for (int i = 0; i < 2 * n;i++) {
        cin >> belt[i];
    }
    end_pos = n - 1;
    while (!stop) {
        rotation_belt();
        move_robot();
        put_robot();
        if (stop) // ����
            break;
        result++; // �ܰ� �ϼ�
    }
    cout << result << endl;
    return 0;
}
