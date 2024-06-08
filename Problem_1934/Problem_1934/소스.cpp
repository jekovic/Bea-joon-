/*
	�ּҰ����
	-> �� ���� ���� �ִ� ������� ���� ��'

	��Ŭ���� ȣ���� �̿�
	�ִ����� ->  �ּҰ����
	
*/
#include <iostream>

using namespace std;

unsigned short Max(unsigned short a, unsigned short b)
{
	int k = (a > b) ? a : b;
	return k;
}
unsigned short Min(unsigned short a, unsigned short b)
{
	int k = (a < b) ? a : b;
	return k;
}
unsigned short gcd(unsigned short x, unsigned short y)
{
	// �ִ����� ���ϴ� ���
	unsigned short ret = 1;
	unsigned short n = Max(x, y);
	unsigned short m = Min(x, y);
	
	while (ret > 0)
	{
		ret = n % m;
		n = m;
		m = ret;
	}
	
	
	return n;

}

unsigned long lcm(unsigned short a, unsigned short b) {

	return (unsigned long)(a * b) / gcd(a, b);
}

int main()
{
	unsigned short T, k  = 0;
	cin >> T;
	int arr[1000] = { 0, };
	
	while (k < T)
	{
		unsigned short A, B = 0;
		cin >> A >> B;
		arr[k] = lcm(A, B);

		k++;
	}

	for (int i = 0; i < T; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}