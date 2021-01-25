#include <math.h>
#include <iostream>

#include <string.h>
#include <string>

#include "ListClass.h"

using namespace std;

//���������� � ����� ������
void List::push(AdressClass* x) { //������ ��� ������ �����, ��� ��� ������ � �����, � ��������� �� ���� ����� �� �������

	node* r = new node;//������� ����� �������

	r->inf = x;

	r->next = NULL; //������ ���������

	if (!head && !tail) { //���� ������ ����

		r->prev = NULL; //������ �������

		head = r; //��� ������

	}

	else {

		tail->next = r; //r - ��������� ��� ������

		r->prev = tail; //����� - ���������� ��� r

	}

	tail = r; //r ������ �����

}

//����� ������ �� �����
void List::print()
{

	node* r = head; //�������� �� ������

	while (r != NULL) { //���� �� ����� �� ����� ������

		cout << r->inf->Info() << " " << endl; //�������� �����  ���������� � ������ ������

		r = r->next; //������� � ���������� ��������

	}

	cout << '\n';

}

//�������� �� �������������
bool List::findBool(AdressClass* x) { //������ ��������� ������
	node* p = head; //�������� �� ������
	while (p) { //���� �� ����� �� ����� ������
		if (p->inf == x) return true; // ���� �����, ���������� true
		p = p->next; //������� � ���������� ��������

	}
	return false; //���� �� �����, �� ���������� false

}

//����� ��������
node* List::find(AdressClass* x) { //������ ��������� ������
	node* p = head; //�������� �� ������
	while (p) { //���� �� ����� �� ����� ������
		if (p->inf == x) break; // ���� �����, ���������� ����
		p = p->next; //������� � ���������� ��������

	}
	return p;
}

//������� �����
void List::insert_after(node* x, AdressClass* y) { //��������� ����� �
	node* p = new node; //������� ����� �������
	p->inf = y;
	if (x == tail) { //���� ��������� ����� ������
		p->next = NULL; //����������� ��-� - ���������
		p->prev = x; //��������� ����� �
		x->next = p;
		tail = p; //������ ����� - p

	}
	else { //��������� � �������� ������
		x->next->prev = p; //��� ���������� �� r ��-�� ���������� - p
		p->next = x->next; //��������� �� p - ��������� �� �
		p->prev = x; //p ��������� ����� �
		x->next = p;

	}

}

//�������� �������� �����
void List::deleteNode(node* x) { //������� ����� �
	if (x == head && x == tail) //������������ ������� ������
		head = tail = NULL;
	else if (x == head) { //������� ������ ������
		head = head->next; //�������� ������
		head->prev = NULL;


	}
	else if (x == tail) { //������� ����� ������
		tail = tail->prev; //�������� �����
		tail->next = NULL;

	}
	else {
		x->next->prev = x->prev; //��� ���������� �� � ���������� ���������� r->prev
		x->prev->next = x->next; //��� ����������� �� � ��������� ���������� x->next

	}
	delete x; //������� �

}

//������� ����
void List::deleteList() { //������� ������
	while (head) { //���� ������ �� ����
		node* p = head; //��������� �� ������
		head = head->next; //��������� ������
		head->prev = NULL; //��������
		delete p; //������� p

	}
}