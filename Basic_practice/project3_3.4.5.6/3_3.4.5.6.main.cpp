#include <iostream>

int main() {

	using namespace std;

	//sizeof(float); sizeof�� �������� ũ�⸦ �˰���� ��� ��� ������ Ÿ���� �־ �ǰ� ������ �־ ��
	//sizeof�� �Լ� �ƴϰ� ���۷���Ʈ�� ǥ������ ���� �س�, �̷����� �������� ��� ��ȣ ��� �۵���

	//comma operator

	int x = 3;
	int y = 10;

	int z = (++x, ++y);
	//�� �ڵ带 Ǯ��� �� 3���� 
	//++x;
	//++y;
	//int z = y;

	cout << x << " " << y << " " << z << endl;

	// conditional opertator
	bool oneSale = true;

	const int price = (oneSale == true) ? 10 : 100;

	cout << price << endl;

	int d = 5;
	
	cout << ((d % 2 == 0) ? 0 : "odd") << endl;

	return 0;

}