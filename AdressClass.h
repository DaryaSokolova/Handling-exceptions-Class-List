#pragma once

#include <string>
#include <exception>

using namespace std;

class AdressClass
{

public:
	AdressClass(string t, string st, int h, int num, int price, string name);
	AdressClass() { };
	~AdressClass();

	//геттеры
	string getTown();
	string getStreet();
	int getHouse();
	int getNumber();
	int getPrice();
	string getName();

	//сеттеры
	bool setUpPrice(int price); //аренда может увеличиться
	bool setDownPrice(int price); //аренда может уменьшаться
	bool setName(string nm); //сменился владелец

//действия
	void Remont();    // квартира ремонтируется
	void Cleaning();  // квартира убирается
	void Water();
	void Warm();
	void Gas();
	//void Print(); //вывод информации о конкретном объекте, в дальнейшем лучше заменить на перегрузку операторов вывода!
	string Info();

	bool operator == (AdressClass t);
	bool operator != (AdressClass t);

//private:
	string Town; //город
	string Street; //улица
	int House; //номер дома
	int Number;//номер квартиры
	string Name; //фамилия владельца квартиры
	int Price; //стоимость аренды

	bool ChangePrice(int h); //служебный метод класса, недоступен извне! Сделан для того, чтобы единым образом проверять на допустимость попытку изменить вес кошки
};