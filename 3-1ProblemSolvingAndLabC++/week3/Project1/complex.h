#pragma once

/* �ش� Ŭ���� ���� */
class Complex {

private :
	/* m_n ?
	* m : member varible
	* n : number type (int)
	*/
	int m_nReal;
	int m_nImaginary;

public :
	// constructor
	Complex();

	// setter
	void setReal(int new_r);
	void setImaginary(int new_i);

	// getter
	int getReal();
	int getImaginary();

	// submethod
	void show();
};