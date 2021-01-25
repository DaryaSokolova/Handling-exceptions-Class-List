#include <math.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "AdressClass.h"
#include "MyError.h"
#include "ListClass.h"
#include <string>

#include <exception>

using namespace std;

//запись в файл
std::ostream& operator << (std::ostream& os, const AdressClass& a)
{
	return os << a.Town << " " << a.Street << " " << a.House << " " << a.Number << " " << a.Price << " " << a.Name;
}

//чтение с файла
std::istream& operator >> (std::istream& in, AdressClass& p)
{
	in >> p.Town >> p.Street >> p.House >> p.Number >> p.Price >> p.Name;
	if (!in) 
	{
		//проверим все ли хорошо
		throw My_File_Error();
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		//AdressClass Adress1("", "рвпрд", 90, 426, 500, "Иванов");
		//AdressClass Adress1("Энгельс", "Вольская", 90, 426, 500, "Иванов");
		//AdressClass Adress1("Энгельс", "Вольская", 57, INT_MAX, 500, "Иванов");
		//cout << Adress1.Info() << endl;
		//Adress1.setUpPrice(-5);
		//Adress1.setDownPrice(5);
		//Adress1.setName("");
		//Adress1.setName("Соколов");
		//cout << Adress1.Info() << endl;
	}
	catch (const char* msg)
	{
		cerr << msg;
	}
	catch (MyError& err)
	{
		err.print();
	}
	catch (...)
	{
		cerr << "Что-то не так";
	}

	//для записи в файл
	/*AdressClass AdressForFile("Энгельс", "Вольская", 90, 426, 500, "Иванов");

	std::ofstream out("intest.txt");
	if (out.is_open())
	{
		out << AdressForFile << std::endl;
	}
	out.close();*/

	//лист
	List cList;
	AdressClass* t;

	try
	{
		// чтение ранее записанных данных из файла
		std::ifstream in("intest.txt");
		if (in.is_open())
		{
			AdressClass p;
			in >> p;
			t = new AdressClass(p);
			cList.push(t); //добавляем в лист
		}
		in.close();
		cList.print(); //выводим лист
	}
	//обработка исключения (полиморфизм)
	catch (MyError& err)
	{
		err.print();
	}
	catch (...)
	{
		cerr << "Что-то не так";
	}

	return 0;
}