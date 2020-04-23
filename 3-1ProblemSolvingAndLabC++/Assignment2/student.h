#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
class CStudent
{

private:
	string m_strName;
	string m_strPhoneNumber;
	string m_strEmail;
	
	// ������ ���̹Ƿ� const ���
	const int m_kId;


public:

	// �ܺο��� �ʱ�ȭ�� ���ֱ� ���� public ���� ����
	static int s_nCountObject;
	CStudent(string Name, string PhoneNumber, string Email, int id = s_nCountObject);
	~CStudent() { s_nCountObject--; };

	// ������ �Լ��� ���� inline ���� ����

	// getter, inline function
	string get_strName() const { return m_strName; };
	string get_strPhoneNumber() const { return m_strPhoneNumber; };
	string get_strEmail() const { return m_strEmail; };
	static int get_nCountObject() { return s_nCountObject; }

	// setter, inlnine function
	void set_strName(string strName) { m_strName = strName; };
	void set_strPhoneNumber(string strPhoneNumber) { m_strPhoneNumber = strPhoneNumber; };
	void set_strEmail(string strEmail) { m_strEmail = strEmail; };

	// methods
	void PrintStudentInfo() const;
	static void PrintCurrentDataCount() { cout << "Current " << s_nCountObject << " data exist in the storage." << endl; };
};