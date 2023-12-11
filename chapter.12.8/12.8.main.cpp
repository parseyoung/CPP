// 가상 기본 클래스와 다이아몬스 상속
// virtual로 상속받아서 PowerDevice 객체를 공유해서 주소가 같음 

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

    cout << &cop.Scanner::PowerDevice::m_i << endl;     // Scanner의 PowerDevice의 m_i 접근
    cout << &cop.Printer::PowerDevice::m_i << endl;     // Printer의 PowerDevice의 m_i 접근
    // 주소 같게 출력
    return 0;
}
