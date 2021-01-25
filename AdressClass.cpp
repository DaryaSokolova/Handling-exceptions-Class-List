#include "AdressClass.h"
#include "MyError.h"
#include <iostream>
#include <string>

using namespace std;

AdressClass::AdressClass(string t, string st, int h, int num, int price, string name)
{
	if (t == "")
	{
		//throw 0; //для вывода что-то не так - любое исключение
		//throw "Неверно указан город!"; //для мессаджа
		throw MyError();
		//throw My_Bad_Alloc();
		//throw My_File_Error();
	}

	if (st == "")
	{
		//throw;
		throw "Неверно указана улица!";
	}

	if (h <= 0)
	{
		//throw;
		throw "Неверно указан дом!";
	}

	if (num <= 0)
	{
		//throw;
		throw "Неверно указана квартира!";
	}

	if (price <= 0)
	{
		//throw;
		throw "Неверно указана цена!";
	}

	if (name == "")
	{
		//throw;
		throw "Неверно указан владелец!";
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

bool AdressClass::setUpPrice(int h) // аренда может увеличиться
{
	if (h <= 0)
	{
		//throw MyError();
		throw "Введено <= 0";
	}
	return ChangePrice(h);
}

bool AdressClass::setDownPrice(int h) //аренда может уменьшиться
{
	if (h <= 0)
	{
		//throw MyError();
		throw "Введено <= 0";
	}
	return ChangePrice(-h);
}

bool AdressClass::setName(string nm) //у квартиры есть владелец или сменился
{
	if (nm == "")
	{
		//throw MyError();
		throw "Введена пустота";
	}
	Name = nm;
	return true;
}

void AdressClass::Remont() // квартира ремонтируется. ремонтироваться может только правильная квартира (та, которая создана)
{
	cout << "По адресу " << Info() << " ремонтируют квартиру\n";
	cout << "@  \n";
	cout << "   @\n";
	cout << "@  \n";
	cout << "   @\n";
}

void AdressClass::Cleaning() // квартира убирается. убираться может только правильная квартира (та, которая создана)
{
	cout << "По адресу " << Info() << " убираются клининг-службы " << "_\n";
}

void AdressClass::Water() {
	cout << "По адресу " << Info() << " проведена горячая вода " << "_\n";
}

void AdressClass::Warm() {
	cout << "По адресу " << Info() << " временно отключен газ " << "_\n";
}

void AdressClass::Gas() {
	cout << "По адресу " << Info() << " проведено отопление " << "_\n";
}

string AdressClass::Info()
{
	return Town + ", " + Street + ", "
		+ to_string(House) + ", кв" + to_string(Number)
		+ ", владельцы - "
		+ Name
		+ ", аренда: "
		+ to_string(Price);
}

bool AdressClass::operator == (AdressClass t) {

	return (Town == t.getTown() && Street == t.getStreet() && House == t.getHouse() && Number == t.getNumber());

}

bool AdressClass::operator != (AdressClass t) {

	return (Town != t.getTown() || Street != t.getStreet() || House != t.getHouse() || Number != t.getNumber());

}