#include "AdressClass.h"
#include "MyError.h"
#include <iostream>
#include <string>

using namespace std;

AdressClass::AdressClass(string t, string st, int h, int num, int price, string name)
{
	if (t == "")
	{
		//throw 0; //��� ������ ���-�� �� ��� - ����� ����������
		//throw "������� ������ �����!"; //��� ��������
		throw MyError();
		//throw My_Bad_Alloc();
		//throw My_File_Error();
	}

	if (st == "")
	{
		//throw;
		throw "������� ������� �����!";
	}

	if (h <= 0)
	{
		//throw;
		throw "������� ������ ���!";
	}

	if (num <= 0)
	{
		//throw;
		throw "������� ������� ��������!";
	}

	if (price <= 0)
	{
		//throw;
		throw "������� ������� ����!";
	}

	if (name == "")
	{
		//throw;
		throw "������� ������ ��������!";
	}

	if ((h == INT_MAX) || (num == INT_MAX) || (price == INT_MAX))
	{
		throw My_Bad_Alloc();
	}

	Town = t;
	House = h;
	Number = num;
	Street = st;
	Price = price;
	Name = name;
}

AdressClass::~AdressClass() { }

string AdressClass::getTown()
{
	return Town;
}

string AdressClass::getStreet()
{
	return Street;
}

int AdressClass::getHouse()
{
	return House;
}

int AdressClass::getNumber()
{
	return Number;
}

int AdressClass::getPrice()
{
	return Price;
}

string AdressClass::getName()
{
	return Name;
}


bool AdressClass::ChangePrice(int temp)
{
	Price = Price + temp;
	return true;
}

bool AdressClass::setUpPrice(int h) // ������ ����� �����������
{
	if (h <= 0)
	{
		//throw MyError();
		throw "������� <= 0";
	}
	return ChangePrice(h);
}

bool AdressClass::setDownPrice(int h) //������ ����� �����������
{
	if (h <= 0)
	{
		//throw MyError();
		throw "������� <= 0";
	}
	return ChangePrice(-h);
}

bool AdressClass::setName(string nm) //� �������� ���� �������� ��� ��������
{
	if (nm == "")
	{
		//throw MyError();
		throw "������� �������";
	}
	Name = nm;
	return true;
}

void AdressClass::Remont() // �������� �������������. ��������������� ����� ������ ���������� �������� (��, ������� �������)
{
	cout << "�� ������ " << Info() << " ����������� ��������\n";
	cout << "@  \n";
	cout << "   @\n";
	cout << "@  \n";
	cout << "   @\n";
}

void AdressClass::Cleaning() // �������� ���������. ��������� ����� ������ ���������� �������� (��, ������� �������)
{
	cout << "�� ������ " << Info() << " ��������� �������-������ " << "_\n";
}

void AdressClass::Water() {
	cout << "�� ������ " << Info() << " ��������� ������� ���� " << "_\n";
}

void AdressClass::Warm() {
	cout << "�� ������ " << Info() << " �������� �������� ��� " << "_\n";
}

void AdressClass::Gas() {
	cout << "�� ������ " << Info() << " ��������� ��������� " << "_\n";
}

string AdressClass::Info()
{
	return Town + ", " + Street + ", "
		+ to_string(House) + ", ��" + to_string(Number)
		+ ", ��������� - "
		+ Name
		+ ", ������: "
		+ to_string(Price);
}

bool AdressClass::operator == (AdressClass t) {

	return (Town == t.getTown() && Street == t.getStreet() && House == t.getHouse() && Number == t.getNumber());

}

bool AdressClass::operator != (AdressClass t) {

	return (Town != t.getTown() || Street != t.getStreet() || House != t.getHouse() || Number != t.getNumber());

}