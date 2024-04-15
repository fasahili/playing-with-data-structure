#pragma once
#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "LinkedListT.h"

using namespace std;

template <class T>
class UnorderedLinkedList : public LinkedList<T> {
public:
	bool search(const T& searchItem) const;
	void insertFirst(const T& newItem);
	void insertLast(const T& newItem);
	void deleteNode(const T& deleteItem);
	void deleteLess();
	void deleteRepe();
	void divideMid(linkedList<T>& item);
	void divideAt(linkedList<T>& obj, const T& item);

};

template <class T>
void UnorderedLinkedList<T>::deleteNode(const T& deleteItem) {
	nodeType<T>* current;
	nodeType<T>* trailCurrent;
	bool found;

	if (this->first == NULL)
		cerr << "Cannot delete from an empty list." << endl;
	else {
		if (this->first->info == deleteItem) {
			current = this->first;
			this->first = this->first->link;
			this->count--;
			if (this->first == NULL)  this->last = NULL;
			delete current;
		}
		else {
			found = false;
			trailCurrent = this->first;
			current = this->first->link;
			while (current != NULL && !found) {
				if (current->info != deleteItem) {
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}

			if (found) {
				trailCurrent->link = current->link;
				this->count--;
				if (this->last == current)
					this->last = trailCurrent;
				delete current;
			}
			else
				cout << "The item to be deleted is not in " << "the list." << endl;
		}
	}
}

template <class T>
bool UnorderedLinkedList<T>::search(const T& searchItem) const {
	nodeType<T>* current;
	bool found = false;
	current = this->first;
	while (current != NULL && !found)
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	return found;
}

template <class T>
void UnorderedLinkedList<T>::insertFirst(const T& newItem) {
	nodeType<T>* newNode;
	newNode = new nodeType<T>;
	newNode->info = newItem;
	newNode->link = this->first;
	this->first = newNode;
	this->count++;
	if (this->last == NULL)
		this->last = newNode;
}
template <class T>
void UnorderedLinkedList<T>::insertLast(const T& newItem) {
	//create new node and fill it up
	nodeType<T>* newNode = new nodeType<T>;
	newNode->info = newItem;
	newNode->link = 0;
	//consider empty list case 
	if (this->first == 0) {
		this->first = this->last = newNode;
		this->count++;
	}
	else {
		this->last->link = newNode;
		this->last = newNode;
		this->count++;
	}
}

//Assignment
template <class T>
void UnorderedLinkedList<T>::deleteLess() 
{
		if (this->first == NULL)
		{
			cout << "the list is empty" << endl;
			return;
		}
		nodeType<T>* current;
		current = this->first;
		T item = current->info;
		int count = 1;

		current = current->link;

		while (current != NULL)
		{
			if (current->info == item)
			{
				count++;
			}
			if (item > current->info)
			{
				item = current->info;
				count = 1;
			}
			current = current->link;
		}
		for (int i = 0; i < count; i++)
		{
			deleteNode(item);
		}
	
}
template <class T>
void UnorderedLinkedList<T>::deleteRepe()
{
	if (this->first == NULL)
	{
		cout << "the list is empty" << endl;
		return;
	}
	nodeType<T>* current;
	current = this->first;
	T item = current->info;
	int count = 1;

	current = current->link;

	while (current != NULL)
	{
		if (current->info == item)
		{
			count++;
		}
		if (item > current->info)
		{
			item = current->info;
			count = 1;
		}
		current = current->link;
	}
	for (int i = 0; i < count; i++)
	{
		deleteNode(item);
	}

}
template <class T>
void UnorderedLinkedList<T>::divideMid(linkedList<T>& item)
{
	nodeType<T>* current = first;
	item.last = last;
	int divide = (count / 2) + 1;
	for (int i = 0; i <= divide; i++)
	{
		current = current->link;
	}
	last = current;
	item.first = last->link;
	last->link = 0;
}
template <class T>
void UnorderedLinkedList<T>::divideAt(linkedList<T>& obj, const T& item)