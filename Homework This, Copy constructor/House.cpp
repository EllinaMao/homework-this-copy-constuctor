#include "House.h"

House::House()
{
    mHouseNumber = 0;
    mAdress = copy_str("Unkown");
    mFlat = new Flat[1];

    mFlatCount++;
}

House::House(Flat& f, const int houseNumber, const char* adress)
{
    mFlat = new Flat[1];
    mFlat[0] = f;

    mHouseNumber = houseNumber;
    mAdress = copy_str(adress);
    mFlatCount++;
}


House::House(const House& h)
{ 
    mHouseNumber = h.mHouseNumber;
    mFlatCount = h.mFlatCount;

    if (h.mAdress) {
        mAdress = copy_str(h.mAdress);
    }
    else {
        mAdress = nullptr;
    }

    mFlat = h.mFlat;
}

House::House(House&& h) noexcept
{

    mHouseNumber = h.mHouseNumber;
    mFlatCount = h.mFlatCount;


    mAdress = h.mAdress;
    h.mAdress = nullptr;


    mFlat = move(h.mFlat);
}

House& House::operator=(const House& h)
{
    if (this == &h) {
        return *this;
    }
    delete[] mAdress;

    mHouseNumber = h.mHouseNumber;
    mFlatCount = h.mFlatCount;

    if (h.mAdress) {
        mAdress = copy_str(h.mAdress);
    }
    else {
        mAdress = nullptr;
    }

    mFlat = h.mFlat;

    return *this;
}

House& House::operator=(House&& h) noexcept
{
    if (this == &h) {
        return *this;
    }

    delete[] mAdress;

    mHouseNumber = h.mHouseNumber;
    mFlatCount = h.mFlatCount;

    mAdress = h.mAdress;
    h.mAdress = nullptr;


    mFlat = move(h.mFlat);

    return *this;
}


void House::AddThisFlat(const Flat& f)
{
    size_t new_count = mFlatCount + 1;
    Flat* temp = new Flat[new_count];

    for (size_t i = 0; i < mFlatCount; i++) {
        temp[i] = move(mFlat[i]); 
    }

    temp[mFlatCount] = f;
    delete[] mFlat;
    mFlat = temp;
    mFlatCount = new_count;
}

void House::PrintInfo() const
{
    cout << "House Number: " << mHouseNumber
        << "\nAddress: " << (mAdress ? mAdress : "No Address")
        << "\nNumber of Flats: " << mFlatCount << endl;
    cout << endl;

    for (size_t i = 0; i < mFlatCount; ++i) {
        cout << "Flat " << i + 1 << " Info:" << endl;
        mFlat[i].PrintInfo();
    }

}

void House::SetFlat(const Flat& flat, const int index)
{
    if (index < 0 || index >(mFlatCount - 1)) {
        return;
    }

    mFlat[index] = flat;
}

void House::SetFlatNumber(const char* adress)
{
    if (mAdress) {
        delete[] mAdress;
    }

    if (adress) {
        mAdress = copy_str(adress);
    }
    else {
        mAdress = nullptr;
    }
}

const Flat& House::GetFlatByIndex(int index) const
{
    static Flat invalidFlat;

    if (index < 0 || index >(mFlatCount - 1)) {
        return invalidFlat;
    }

    return mFlat[index];
}
