#ifndef _CLIST_H_
#define _CLIST_H_


#include <iostream>


using namespace std;

template <class T>
class CList
{
private:
	T* data;
	CList* link;
public:
	CList() : data(NULL) { link = this; }
	~CList();
	T* insert(T* p);
	T* search(T* p);
	T* remove(T* p);
	void list();
};


template <class T>
CList<T>::~CList() 
{
	
	if (link == NULL) 
		return;
	
	CList* l = this->link;
	while (l != this)
	{
		CList* t = l;
		l = l->link;
		t->link = NULL;
		
		delete t;
	}
	this->link = NULL;
}


template <class T>
T* CList<T>::insert(T* key)
{
	CList* l;

	for (l = this; l->link != this && l->link->data->getName() < key->getName(); l = l->link);

	if (l->link->data != 0 && key->getName() == l->link->data->getName()) // key is in list
		return l->link->data;


	CList* t = new CList();
	t->data = key;
	t->link = l->link;
	l->link = t;
	return t->data;
}


template <class T>
T* CList<T>::remove(T* key) 
{

	CList* l;

	for (l = this; l->link != this && l->link->data->getName() != key->getName(); l = l->link);

	if (l->link->data != 0 && l->link->data->getName() == key->getName())
	{
		CList* t = l->link;
		T* d = t->data;
		l->link = t->link;
		t->link = 0;
		delete t;
		return d;
	}
	else
		return 0;
}


template <class T>
T* CList<T>::search(T* key)
{
	for (CList* l = this->link; l != this; l = l->link) if (l->data->getName() == key->getName())
	return l->data;

	return 0;
}


template <class T>
void CList<T>::list()
{

	for (CList* l = this->link; l != this; l = l->link)
		l->data->display();

}
#endif