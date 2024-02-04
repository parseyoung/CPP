// exception ���輺�� ����
// ����ϰ� ȣ��Ǵ� for���� ����ó�� �ϸ� ���� ����
// ������ main�ȿ� ����ϸ� �����ս� ������
// ��� ������ ����ó���� �Ϸ��� ���� ����
// �л�ó�� ����ó���� ���� �Ұ����� ��Ȳ �������� �����ϱ� ���� ��Ȳ�� ���
// if ������� �ذ� ���� �� ���� �׷��� �ذ�

#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	// �Ҹ��� �ȿ��� throw �Ұ� ��Ÿ�� ���� �߻�
	~A()
	{
		throw "error";
	}
};
int main()
{
	try
	{
		// ���ܰ� �߻��ϸ� throw�� �Ѿ delete[] ���� X �޸� ���� �߻�
		// ����Ʈ������ unique_ptr�� �ذ�
		int* i = new int[1000000];
		unique_ptr<int> up_i(i);

		// doSomething with i
		throw "error";

		// delete[] i;
		// A a
	}

	catch (...)
	{
		cout << "catch" << endl;
	}

	return 0;
}