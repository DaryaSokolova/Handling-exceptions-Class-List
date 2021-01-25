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

//������ � ����
std::ostream& operator << (std::ostream& os, const AdressClass& a)
{
	return os << a.Town << " " << a.Street << " " << a.House << " " << a.Number << " " << a.Price << " " << a.Name;
}

//������ � �����
std::istream& operator >> (std::istream& in, AdressClass& p)
{
	in >> p.Town >> p.Street >> p.House >> p.Number >> p.Price >> p.Name;
	if (!in) 
	{
		//�������� ��� �� ������
		throw My_File_Error();
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		//AdressClass Adress1("", "�����", 90, 426, 500, "������");
		//AdressClass Adress1("�������", "��������", 90, 426, 500, "������");
		//AdressClass Adress1("�������", "��������", 57, INT_MAX, 500, "������");
		//cout << Adress1.Info() << endl;
		//Adress1.setUpPrice(-5);
		//Adress1.setDownPrice(5);
		//Adress1.setName("");
		//Adress1.setName("�������");
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
		cerr << "���-�� �� ���";
	}

	//��� ������ � ����
	/*AdressClass AdressForFile("�������", "��������", 90, 426, 500, "������");

	std::ofstream out("intest.txt");
	if (out.is_open())
	{
		out << AdressForFile << std::endl;
	}
	out.close();*/

	//����
	List cList;
	AdressClass* t;

	try
	{
		// ������ ����� ���������� ������ �� �����
		std::ifstream in("intest.txt");
		if (in.is_open())
		{
			AdressClass p;
			in >> p;
			t = new AdressClass(p);
			cList.push(t); //��������� � ����
		}
		in.close();
		cList.print(); //������� ����
	}
	//��������� ���������� (�����������)
	catch (MyError& err)
	{
		err.print();
	}
	catch (...)
	{
		cerr << "���-�� �� ���";
	}

	return 0;
}