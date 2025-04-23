#include "Human.h"

char* Human::PhoneNumberCheck(const char* phoneNumber)
{
    char* temp = copy_str(phoneNumber);
    char* phonepass;
    short phonesize = 13;
    short shortphonesize = 10;
    size_t tempsize = strlen(temp);

    if (tempsize == shortphonesize) {
        phonepass = new char[phonesize + 1];
        phonepass[0] = '+';
        phonepass[1] = '3';
        phonepass[2] = '8';
        for (int i = 0; i < shortphonesize; ++i) {
            phonepass[i + 3] = temp[i];
        }
        phonepass[phonesize] = '\0';
    }
    else if(tempsize == phonesize - 1) {
        phonepass = new char[phonesize + 1];
        phonepass[0] = '+';
        for (int i = 0; i < phonesize - 1; ++i) {
            phonepass[i + 1] = temp[i]; 
        }
        phonepass[phonesize] = '\0';
    }
    else {
        phonepass = temp; 
        temp = nullptr;   
    }

    if (temp) {
        delete[] temp; // Clean up temp only if it wasn't moved
    }
    return phonepass;
}

Human::Human()
{
	mFullName = copy_str("Unkown");
	mPhoneNumber = copy_str("Unkown");
	mGender = copy_str("Unkown");
	mAge = 0;
}

Human::Human(const char* fullName, const char* phoneNumber, const char* gender, const int age)
{
	mFullName = copy_str(fullName);
    mPhoneNumber = PhoneNumberCheck(phoneNumber);
	mGender = copy_str(gender);
	mAge = age; 
}

Human::Human(const Human& h)
{
	//cout << "Copy" << endl;
	mFullName = copy_str(h.mFullName);
	mPhoneNumber = copy_str(h.mPhoneNumber);
	mGender = copy_str(h.mGender);
	mAge = h.mAge;
}


Human::Human(Human&& h) noexcept
{
	//cout << "Move" << endl;
	mFullName = h.mFullName;
	mPhoneNumber = h.mPhoneNumber;
	mGender = h.mGender;
	mAge = h.mAge;

	h.mFullName = nullptr;
	h.mPhoneNumber = nullptr;
	h.mGender = nullptr;
}

Human& Human::operator=(const Human& h)
{
    if (this != &h) {
        delete[] mFullName;
        delete[] mPhoneNumber;
        delete[] mGender;

       // cout << "Copy=" << endl;
        mFullName = copy_str(h.mFullName);
        mPhoneNumber = copy_str(h.mPhoneNumber);
        mGender = copy_str(h.mGender);
        mAge = h.mAge;
    }
    return *this;
}

Human& Human::operator=(Human&& h) noexcept
{
    if (this != &h) {
        delete[] mFullName;
        delete[] mPhoneNumber;
        delete[] mGender;

       // cout << "Move=" << endl;
        mFullName = h.mFullName;
        mPhoneNumber = h.mPhoneNumber;
        mGender = h.mGender;
        mAge = h.mAge;

        h.mFullName = nullptr;
        h.mPhoneNumber = nullptr;
        h.mGender = nullptr;
        h.mAge = 0;
    }
    return *this;
}

void Human::PrintInfo() const
{
	cout << "Fullname: " << mFullName
		<<" gender: "<< mGender
		<<" age: "<< mAge
		<< " phonenumber: " << mPhoneNumber
		<< endl;
}

void Human::SetFullName(const char* fullName)
{
	if (mFullName)
	{
		delete[] mFullName;
	}
	mFullName = copy_str(fullName);
}

void Human::SetPhoneNumber(const char* phoneNumber)
{
    if (mPhoneNumber)
    {
        delete[] mPhoneNumber;
    }
    mPhoneNumber = PhoneNumberCheck(phoneNumber);
}

void Human::SetGender(const char* gender)
{
    if (mGender)
    {
        delete[] mGender;
    }
    mGender = copy_str(gender);
}

Human::~Human()
{
   // cout << "Destruct human" << endl;
    delete[] mFullName;
    delete[] mPhoneNumber;
    delete[] mGender;
}

