// �Լ� �����ε�
// ��Ȯ�ϰ� ������ �ؾ� �Լ� �����ε��� ������ ����
// �����Ϸ��� ������ ��Ȯ�� ���ϸ� ������ �߻���
// return type ������ ������ ���� ����, �Ű������� �޶����

void print(unsigned int value) {}
void print(float value) {}

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

int main()
{
	print((unsigned int)'a');
	print(0u);
	print(3.14F);
	return 0;
}