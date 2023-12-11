// ���� �⺻ Ŭ������ ���̾Ƹ� ���
// virtual�� ��ӹ޾Ƽ� PowerDevice ��ü�� �����ؼ� �ּҰ� ���� 

#include <iostream>
using namespace std;

class PowerDevice
{
public:
    int m_i;

    PowerDevice(int power)
    {
        m_i = power;
        cout << "PoweredDevice " << power << "\n";
    }
};

class Scanner : virtual public PowerDevice
{
public:
    Scanner(int power, int scanner)
        : PowerDevice(power)
    {
        cout << "Scanner: " << scanner << "\n";
    }
};

class Printer : virtual public PowerDevice
{
public:
    Printer(int power, int printer)
        : PowerDevice(power)
    {
        cout << "Printer: " << printer << "\n";
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PowerDevice(power), Scanner(power, scanner), Printer(power, printer)
    {}
};

int main()
{
    Copier cop(1, 2, 3);

    cout << &cop.Scanner::PowerDevice::m_i << endl;     // Scanner�� PowerDevice�� m_i ����
    cout << &cop.Printer::PowerDevice::m_i << endl;     // Printer�� PowerDevice�� m_i ����
    // �ּ� ���� ���
    return 0;
}
