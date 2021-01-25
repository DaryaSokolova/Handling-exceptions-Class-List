#pragma once
#include <math.h>
#include <iostream>

#include <string.h>
#include <string>

#include "AdressClass.h"

using namespace std;

struct node {

	AdressClass* inf;

	node* next;

	node* prev;

};


class List {

private:

	node* head;

	node* tail;

public:

	List() { head = NULL; tail = NULL; }

	void push(AdressClass* x); //добавление в конец списка

	void print(); //вывод списка

	bool findBool(AdressClass* x); //проверить на повторение

	void insert_after(node* x, AdressClass* y); //

	node* find(AdressClass* x);

	void deleteNode(node* x);

	void deleteList();

};
