// ��� ������ �����ε�(Overloading) �ϱ�
#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int getCents() { return m_cents; }

    Cents operator + (const Cents& c2)
    {
        return Cents(this->m_cents + c2.m_cents);
    }
    //  + *  / - (����)
    // ?:  ::  sizeof  . .* <������ �����ε� �Ұ���)
};

/*
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
    c_out = Cents(c1.getCents() + c2.getCents());
}
*/

//Cents add(const Cents& c1, const Cents& c2)
/*
Cents operator + (const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}
*/
int main()
{
    Cents cents1(4);
    Cents cents2(10);

    Cents sum;
    //add(cents1, cents2, sum);

   //cout << add(cents1, cents2).getCents() << endl;
   // Cents(6)�� �͸� ��ü
    cout << (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;
    
    return 0;
}
