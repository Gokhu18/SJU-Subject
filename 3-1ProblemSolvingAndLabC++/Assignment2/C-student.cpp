#include "student.h"

int CStudent::s_nCountObject = 0;

CStudent::CStudent(string Name, string PhoneNumber, string Email, int id): m_kId(id+1)
// parameter : Name, Phone Number, Email
// default parameter : id �� ���� ����Ǿ� �ִ� ������ + 1 �� �ʱ�ȭ�ϵ��� ����
// const member initialization : �ݷ� �ʱ�ȭ
{
	m_strName = Name;
	m_strPhoneNumber = PhoneNumber;
	m_strEmail = Email;
	s_nCountObject++;
}


void CStudent::PrintStudentInfo() const
// ���� ���¸� �ٲ� ������ �־�� �� �Ǵ� �Լ��̹Ƿ� const ����
{
	cout << "student info ------: " << endl;
	cout << "m_strName----------: " << m_strName << endl;
	cout << "m_strPhoneNumber---: " << m_strPhoneNumber << endl;
	cout << "m_strEmail---------: " << m_strEmail << endl;
	cout << "m_kid--------------: " << m_kId << endl;
}