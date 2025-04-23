#include <iostream>
#include "Human.h"
#include "Flat.h"
#include "House.h"
using namespace std;

/*
�������.
�������� ���������, ����������� ��������������� ���. ���������� ����� ������ "�������", "��������", "���". ����� "��������" �������� ������������ ������ �������� ������ "�������". ����� "���" �������� ������ �������� ������ "��������".

������ �� ������� �������� ����������-����� � �������-�����, ������� ���������� ��� ���������� ������� ������. �������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������. ��������, ��� ��� � ������ "�������".

�� ��������� ���������� ������ ���������� �������������� (����������� ����������� ����������), �������������. � main �������������� ������ ����������� ������ �������.
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