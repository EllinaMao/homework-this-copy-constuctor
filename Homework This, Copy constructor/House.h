#pragma once
#include <iostream>
#include "Flat.h"
#include "strmetods.h"
using namespace std;



class House {
private:
	Flat* mFlat;
    size_t mFlatCount = 0;
	char* mAdress;
	int mHouseNumber;

public:
    House();
    explicit House(Flat&f, const int houseNumber, const char* adress);

    House(const House& h);
    House(House&& h)noexcept;

    House& operator= (const House& h);
    House& operator= (House&& h) noexcept;

    void AddThisFlat(const Flat& f);
    void PrintInfo() const;

    void SetFlat(const Flat& flat, const int index);
    void SetHouseNumber(const int houseNumber){mHouseNumber = houseNumber;}
    void SetFlatNumber(const char* adress);


    const Flat& GetFlatByIndex(int index) const;
    size_t GetFlatCount() const { return mFlatCount; }
    const char* GetAdress() const { return mAdress;}
    int GetHouseNumber() const { return mHouseNumber;}

};

