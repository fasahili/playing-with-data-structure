#pragma once
#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "nodeTypeT.h"

using namespace std;

template <class T> 
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList<T>& otherList);
	~LinkedList();
	
	const LinkedList<T>& operator=(const LinkedList<T>&);
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	T front() const;
	T back() const;

	virtual bool search(const T& searchItem) const = 0;
	virtual void insertFirst(const T& newItem) = 0;
	virtual void insertLast(const T& newItem) = 0;
	virtual void deleteNode(const T& deleteItem) = 0;
	virtual void deleteLess() = 0;
	virtual void deleteRepe() = 0;



protected:
	int count; 
	nodeType<T>* first; 
	nodeType<T>* last; 
private:
	void copyList(const LinkedList<T>& otherList);
};

template <class T>
LinkedList<T>::LinkedList() {
	first = 0;
	last = 0;
	count = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
	first = NULL;
	copyList(otherList);
}

template <class T>
LinkedList<T>::~LinkedList() {
	destroyList();
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& otherList) {
	if (this != &otherList) {
		copyList(otherList);
	}
	return *this;
}

template <class T>
bool LinkedList<T>::isEmptyList() const {
	return (first == 0);
}

template <class T>
int LinkedList<T>::length() const {
	return count;
}

template <class T>
T LinkedList<T>::front() const {
	assert(first != 0);
	return first->info;
}

template <class T>
T LinkedList<T>::back() const {
	assert(last != 0);
	return last->info;
}

template <class T>
void LinkedList<T>::print() const {
	for (nodeType<T>* current = first; current != 0; current = current->link) {
		cout << current->info << "  ";
	}
	cout << endl;
}

template <class T>
bool LinkedList<T>::search(const T& searchItem) const {
	nodeType<T>* current;
	bool found = false;
	current = first;
	while (current != NULL && !found)
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	return found;
}

template <class T>
void LinkedList<T>::destroyList() {
	nodeType<T>* temp;
	while (first != 0) {
		temp = first;
		first = first->link;
		delete temp;
	}
	last = 0;
	count = 0;
}

template <class T>
void LinkedList<T>::copyList(const LinkedList<T>& otherList) {
	nodeType<T>* newNode;
	nodeType<T>* current;
	if (first != NULL)
		destroyList();

	if (otherList.first == NULL) {
		first = NULL;
		last = NULL;
		count = 0;
	}
	else {
		current = otherList.first;
		count = otherList.count;
		first = new nodeType<T>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while (current != NULL) {
			newNode = new nodeType<T>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
