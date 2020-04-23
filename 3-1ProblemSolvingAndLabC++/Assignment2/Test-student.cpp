#include "student.h"
using namespace std;

int main() 
{
	/* �����ڰ� �� ȣ��ǰ� �ν��Ͻ��� ���������� �����Ǵ°� */

	CStudent *student1 = new CStudent("name1", "010-1111-1111", "student1@naver.com"); // �л�1 : �����ͷ�
	CStudent::PrintCurrentDataCount();
	cout << endl;
	CStudent student2("name1", "010-1111-1112", "student1@naver.com"); // �л�2
	CStudent::PrintCurrentDataCount();
	cout << endl;
	CStudent student3("name1", "010-1111-1113", "student1@naver.com"); // �л�3
	cout << endl;
	CStudent::PrintCurrentDataCount();
	cout << endl;


	/* ��� �Լ� �� ��� ������ �� �����ϴ°� */

	student1->set_strPhoneNumber("NAN"); // set_strPhoneNumber Test
	student1->PrintStudentInfo();
	cout << endl;
	student2.set_strEmail("student2@gmail.com"); // set_strEmail Test
	student2.PrintStudentInfo();
	cout << endl;
	student3.set_strName("name3"); // set_strName Test
	student3.PrintStudentInfo();
	cout << endl;
	CStudent::PrintCurrentDataCount();


	/* ��ü ���Ű� �� �����ϴ°� */

	delete student1; // �����Ҵ��� ���� ������ ��ü ����
	cout << endl;
	CStudent::PrintCurrentDataCount();
	cout << endl;
	student2.~CStudent(); // �Ϲ� �ν��Ͻ� �Ҹ��� ȣ���� ���� ��ü ����
	student2.PrintStudentInfo();
	cout << endl;
	CStudent::PrintCurrentDataCount();
}