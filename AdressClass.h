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

	//�������
	string getTown();
	string getStreet();
	int getHouse();
	int getNumber();
	int getPrice();
	string getName();

	//�������
	bool setUpPrice(int price); //������ ����� �����������
	bool setDownPrice(int price); //������ ����� �����������
	bool setName(string nm); //�������� ��������

//��������
	void Remont();    // �������� �������������
	void Cleaning();  // �������� ���������
	void Water();
	void Warm();
	void Gas();
	//void Print(); //����� ���������� � ���������� �������, � ���������� ����� �������� �� ���������� ���������� ������!
	string Info();

	bool operator == (AdressClass t);
	bool operator != (AdressClass t);

//private:
	string Town; //�����
	string Street; //�����
	int House; //����� ����
	int Number;//����� ��������
	string Name; //������� ��������� ��������
	int Price; //��������� ������

	bool ChangePrice(int h); //��������� ����� ������, ���������� �����! ������ ��� ����, ����� ������ ������� ��������� �� ������������ ������� �������� ��� �����
};