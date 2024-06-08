/*
	�м� ��
	���� �ٸ� �� �м��� �־����� ��, 
	���м��� �����

	==> �м��� ���� ��, ���� �и��� �ִ������� ������.
	
*/

#include <iostream>

using namespace std;

unsigned int Max(unsigned int a, unsigned int b)
{
	unsigned int ret = (a > b) ? a : b;
	return ret;
}

unsigned int Min(unsigned int a, unsigned int b)
{
	unsigned int ret = (a < b) ? a : b;
	return ret;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int ret = 1;
	
	unsigned int x = Max(a,b);
	unsigned int y = Min(a, b);

	while (ret > 0) {
		ret = x % y;
		x = y;
		y = ret;
	}
	return x;

}

int main()
{
	unsigned int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	unsigned int x = 1;//x�� �и�
	unsigned int y = 1;//y�� ����
	
	x = b * d;
	y = a * d + b * c;
	unsigned int g = gcd(x, y);
	//cout << gcd(x, y)<< endl;

	x /= g;
	y /= g;

	cout << y << ' ' << x;

	return 0;
}