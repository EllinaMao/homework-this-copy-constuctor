#pragma once
#include <iostream>
#include "Human.h"
#include "strmetods.h"
using namespace std;

class Flat {
private:
    Human* mPersons;
    size_t mPersonsCount = 0;
    int mFloorNumber;
    int mFlatNumber;

public:

    Flat();
    explicit Flat(const Human& h, const int floorNumber, const int flarNumber);
    Flat(const Flat& f);
    Flat(Flat&& f) noexcept;
    Flat& operator=(const Flat& f);
    Flat& operator=(Flat&& f) noexcept;

    void AddThisHuman(const Human& h);


    void PrintInfo() const;

    void SetPerson(const Human& person, const int index);
    void SetFloorNumber(const int floorNumber){mFloorNumber = floorNumber;}

    void SetFlatNumber(const int flatNumber) { mFlatNumber = flatNumber; }

    const Human& GetPersonByIndex(int index) const;
    size_t GetPersonsCount() const { return mPersonsCount; }
    int GetFloorNumber() const { return mFloorNumber;}
    int GetFlatNumber() const { return mFlatNumber;}


    ~Flat();
};