#include <math.h>
#include <iostream>

#include <string.h>
#include <string>

#include "ListClass.h"

using namespace std;

//добавление в конец списка
void List::push(AdressClass* x) { //теперь сам список знает, где его голова и хвост, а остальным об этом знать не следует

	node* r = new node;//создаем новый элемент

	r->inf = x;

	r->next = NULL; //всегда последний

	if (!head && !tail) { //если список пуст

		r->prev = NULL; //первый элемент

		head = r; //это голова

	}

	else {

		tail->next = r; //r - следующий для хвоста

		r->prev = tail; //хвост - предыдущий для r

	}

	tail = r; //r теперь хвост

}

//вывод списка на экран
void List::print()
{

	node* r = head; //укзатель на голову

	while (r != NULL) { //пока не дошли до конца списка

		cout << r->inf->Info() << " " << endl; //вызываем вывод  информации о каждом адресе

		r = r->next; //переход к следующему элементу

	}

	cout << '\n';

}

//проверка на повторяемость
bool List::findBool(AdressClass* x) { //печать элементов списка
	node* p = head; //укзатель на голову
	while (p) { //пока не дошли до конца списка
		if (p->inf == x) return true; // если нашли, возвращаем true
		p = p->next; //переход к следующему элементу

	}
	return false; //если не нашли, то возвращаем false

}

//поиск элемента
node* List::find(AdressClass* x) { //печать элементов списка
	node* p = head; //укзатель на голову
	while (p) { //пока не дошли до конца списка
		if (p->inf == x) break; // если нашли, прекращаем цикл
		p = p->next; //переход к следующему элементу

	}
	return p;
}

//вставка после
void List::insert_after(node* x, AdressClass* y) { //вставляем после х
	node* p = new node; //создаем новый элемент
	p->inf = y;
	if (x == tail) { //если вставляем после хвоста
		p->next = NULL; //вставляемый эл-т - последний
		p->prev = x; //вставляем после х
		x->next = p;
		tail = p; //теперь хвост - p

	}
	else { //вставляем в середину списка
		x->next->prev = p; //для следующего за r эл-та предыдущий - p
		p->next = x->next; //следующий за p - следующий за х
		p->prev = x; //p вставляем после х
		x->next = p;

	}

}

//удаление элемента после
void List::deleteNode(node* x) { //удаляем после х
	if (x == head && x == tail) //единственный элемент списка
		head = tail = NULL;
	else if (x == head) { //удаляем голову списка
		head = head->next; //сдвигаем голову
		head->prev = NULL;


	}
	else if (x == tail) { //удаляем хвост списка
		tail = tail->prev; //сдвигаем хвост
		tail->next = NULL;

	}
	else {
		x->next->prev = x->prev; //для следующего от х предыдущим становится r->prev
		x->prev->next = x->next; //для предыдущего от х следующим становится x->next

	}
	delete x; //удаляем х

}

//удаляем лист
void List::deleteList() { //удаляем список
	while (head) { //пока список не пуст
		node* p = head; //указатель на голову
		head = head->next; //переносим голову
		head->prev = NULL; //обнуляем
		delete p; //удаляем p

	}
}