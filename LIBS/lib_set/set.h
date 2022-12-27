#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include "../lib_bitfield/bitfield.h"

class TSet {
private:
	size_t maxPower;                       // ������������ �������� ���������
	TBitField bitField;                    // ������� ���� ��� �������� ������������������� �������
public:
	TSet(int mp);
	TSet(const TSet& s);                   // ����������� �����������
	operator TBitField();                  // �������������� ���� � �������� ����

	size_t GetMaxPower(void) const noexcept { return maxPower; }

	void InsElem(size_t Elem);            // �������� ������� � ���������
	void DelElem(size_t Elem);            // ������� ������� �� ���������
	bool IsMember(size_t Elem) const;     // ��������� ������� �������� � ���������

	TSet operator+ (const int Elem);       // ����������� � ���������
	TSet operator- (const int Elem);       // �������� � ���������
	TSet operator+ (const TSet& s);        // �����������
	TSet operator* (const TSet& s);        // �����������
	TSet operator~ (void);                 // ����������

	int operator== (const TSet& s) const;
	int operator!= (const TSet& s) const;
	TSet& operator=(const TSet& s);

	friend istream& operator>>(istream& in, TSet& bf);
	friend ostream& operator<<(ostream& out, const TSet& bf);
};

#endif  // INCLUDE_SET_H_