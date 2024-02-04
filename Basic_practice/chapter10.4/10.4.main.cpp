// Association(제휴관계)
// 전방선언이 되어있는 경우가 많을 경우 제휴관계이다
// 어느 한 쪽이 주인공이 아니다 라고 생각하면 좋을듯,
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor; //forward declaration

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(string name_in)
		: m_name(name_in)
	{}

	void addDoctor(Doctor * new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	friend class Doctor;

	void meetDoctors();
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;

public:
	Doctor(string name_in)
		: m_name(name_in)
	{}
	
	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	friend class Patient;

	void meetPatient()
	{
		for (auto& ele : m_patients)
		{
			cout << "Meet patients : " << ele->m_name << endl;
		}
	}
};

void Patient::meetDoctors()
{
	for (auto& ele : m_doctors)
	{
		cout << "Meet doctor : " << ele->m_name << endl;
	}
}
// class Doctor은 전방선언이 되어있지만, m_name의 존재 파악 못함
// 따로 body를 분리해야 함

int main()
{
	Patient *p1 = new Patient("Jack Jack");
	Patient *p2 = new Patient("Dash");
	Patient *p3 = new Patient("Violet");

	Doctor *d1 = new Doctor("Se young");
	Doctor* d2 = new Doctor("Jae Hyun");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// Patients meet doctors
	p1->meetDoctors();
	p2->meetDoctors();

	// Doctors meet patients
	d1->meetPatient();
	d2->meetPatient();


	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;

}