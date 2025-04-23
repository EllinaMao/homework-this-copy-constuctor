#pragma once
#include <iostream>
#include "strmetods.h"
using namespace std;
/*
������ �� ������� �������� ����������-����� � �������-�����, ������� ���������� ��� ���������� ������� ������. �������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������. ��������, ��� ��� � ������ "�������".
*/
class Human {
private:
	char* mFullName;
	char* mPhoneNumber;
	char* mGender;
	int mAge;


	char* PhoneNumberCheck(const char* phoneNumber);
public:

	Human();
	Human(const char* fullName, const char* phoneNumber, const char* gender, const int age);
	Human(const Human& h); // copy constructor
	Human(Human&& h) noexcept; //move
	// copy constructor
    Human& operator=(const Human& h);
	//move
	Human& operator=(Human&& h) noexcept;

	void PrintInfo() const;
	bool IsAdult() const {return mAge >= 18;}

	void SetFullName(const char* fullName);
	void SetPhoneNumber(const char* phoneNumber);
	void SetGender(const char* gender);
	void SetAge(const int age) {mAge = age;}

	const char* GetFullName() const { return mFullName; }
	const char* GetPhoneNumber() const { return mPhoneNumber; }
	const char* GetGender() const { return mGender; }
	int GetAge() const { return mAge; }

	~Human();
};
