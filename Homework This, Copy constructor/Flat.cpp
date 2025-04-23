#include "Flat.h"

Flat::Flat()
{
 //   cout << "Default Flat" << endl;
    mFlatNumber = 0;
    mFloorNumber = 0;
    mPersons = new Human[1];

    mPersonsCount++;
}

Flat::Flat(const Human& h, const int floorNumber, const int flatNumber)
{

    mFloorNumber = floorNumber;
    mFlatNumber = flatNumber;


    mPersons = new Human[1];
    mPersons[0] = h;


    mPersonsCount++;
}

Flat::Flat(const Flat& f)  
{
 //   cout << "copy flat" << endl;

   mFlatNumber = f.mFlatNumber;  
   mFloorNumber = f.mFloorNumber;  
   mPersonsCount = f.mPersonsCount;  

   mPersons = new Human[mPersonsCount];  
   for (size_t i = 0; i < mPersonsCount; ++i) {  
       mPersons[i] = f.mPersons[i];
   }  
}  

Flat::Flat(Flat&& f) noexcept  
{
  //  cout << "move flat" << endl;

   mFlatNumber = f.mFlatNumber;  
   mFloorNumber = f.mFloorNumber;  
   mPersonsCount = f.mPersonsCount;  
   mPersons = f.mPersons;  

   f.mFlatNumber = 0;  
   f.mFloorNumber = 0;  
   f.mPersonsCount = 0;  
   f.mPersons = nullptr;  
}

Flat& Flat::operator=(const Flat& f)
{
    if (this == &f) {
        return *this; 
    }

    delete[] mPersons;

    mFlatNumber = f.mFlatNumber;
    mFloorNumber = f.mFloorNumber;
    mPersonsCount = f.mPersonsCount;


    mPersons = new Human[mPersonsCount];
    for (size_t i = 0; i < mPersonsCount; ++i) {
        mPersons[i] = f.mPersons[i];
    }

    return *this;
}

Flat& Flat::operator=(Flat&& f) noexcept
{
    if (this == &f) {
        return *this; 
    }

    delete[] mPersons;

    mFlatNumber = f.mFlatNumber;
    mFloorNumber = f.mFloorNumber;
    mPersonsCount = f.mPersonsCount;
    mPersons = f.mPersons;

    f.mFlatNumber = 0;
    f.mFloorNumber = 0;
    f.mPersonsCount = 0;
    f.mPersons = nullptr;

    return *this;
}


void Flat::AddThisHuman(const Human& h)
{
    size_t new_count = mPersonsCount + 1;
    Human* temp = new Human[new_count];

    for (size_t i = 0; i < mPersonsCount; i++) {
        temp[i] = move(mPersons[i]); 
    }

    temp[mPersonsCount] = h; 
    delete[] mPersons;        
    mPersons = temp;          
    mPersonsCount = new_count;
}



void Flat::PrintInfo() const  
{  

   cout << "Flat number: " << mFlatNumber 
   << "\nFloor number: " << mFloorNumber  
   << "\nNumber of tenants: " << mPersonsCount << endl;  

   for (size_t i = 0; i < mPersonsCount; ++i) {  
       cout << "Tenant " << i + 1 << " :"<< endl;  
       mPersons[i].PrintInfo();  
   }  
   cout <<"-------------------------------------------"<< endl;
}


void Flat::SetPerson(const Human& person, const int index)
{
    if (index < 0 || index >(mPersonsCount - 1)) {
        return;
    }

    if (mPersons) {
    delete[] mPersons;
    }

    mPersons = new Human[index]{person};
}

const Human& Flat::GetPersonByIndex(int index) const
{
    static Human invalidHuman; // Default-constructed Human for invalid cases

    if (index < 0 || index >= mPersonsCount) {
        return invalidHuman;
    }

    return mPersons[index];
}



Flat::~Flat()
{

    delete[] mPersons;
}
