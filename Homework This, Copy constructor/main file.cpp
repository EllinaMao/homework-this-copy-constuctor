#include <iostream>
#include "Human.h"
#include "Flat.h"
#include "House.h"
using namespace std;

/*
Задание.
Создайте программу, имитирующую многоквартирный дом. Необходимо иметь классы "Человек", "Квартира", "Дом". Класс "Квартира" содержит динамический массив объектов класса "Человек". Класс "Дом" содержит массив объектов класса "Квартира".

Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для ФИО в классе "Человек".

Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами. В main протестировать работу полученного набора классов.
*/

int main()
{
    // Create Human objects
    Human Andrey("Andrey Petrov", "380992927385", "male", 17);
    Human Andrey2("Andrey Smirnov", "+380992927385", "male", 17);
    Human Salat("Salat Smirnov", "0992927385", "kvadrobober", 17);

    Flat flat1(Andrey, 12, 3);
    Flat flat2(Salat, 5, 1);
    flat1.AddThisHuman(Andrey2); 
    flat1.AddThisHuman(Salat);


    //flat1.PrintInfo();
    

    // Create House object
    House myHouse(flat1, 12, "Agdeeva");
    myHouse.AddThisFlat(flat2);


    // Display House information
    cout << "House Information:" << endl;
    myHouse.PrintInfo();






    return 0;
}