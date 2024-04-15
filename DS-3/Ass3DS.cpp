#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class ArrayList {
public:
	ArrayList(int size = 100);
	ArrayList(const ArrayList<T>& otherList);
	~ArrayList();
	const ArrayList<T>& operator=(const ArrayList<T>&);

	bool  isEmpty() const;
	bool  isFull() const;
	int   listSize() const;
	int   maxListSize() const;
	void  print() const;
	bool  isItemAtEqual(int location, const T& item) const;
	virtual void insertAt(int location, const T& insertItem);
	virtual void insertEnd(const T& insertItem);
	void removeAt(int location);
	void retrieveAt(int location, T& retItem) const;
	void replaceAt(int location, const T& repItem);
	void clearList();
	int seqSearch(const T& item) const;
	void insert(const T& insertItem);
	void remove(const T& removeItem);

	//Assignment
	void MyRemoveAt(int location);
	void removeAll(const T& item);
	ArrayList<int> findAll(const T& item);
	bool operator>(const ArrayList<T>& otherList);
	T minFunc(const ArrayList <T>& otherList);




public:
	T* list;
	int length;
	int maxSize;
};

template <class T>
bool ArrayList<T>::isEmpty() const {
	return (length == 0);
}

template <class T>
bool ArrayList<T>::isFull() const {
	return (length == maxSize);
}

template <class T>
int ArrayList<T>::listSize() const {
	return length;
}

template <class T>
int ArrayList<T>::maxListSize() const {
	return maxSize;
}

template <class T>
void ArrayList<T>::print() const {
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

template <class T>
bool ArrayList<T>::isItemAtEqual(int location, const T& item) const {
	return(list[location] == item);
}

template <class T>
void ArrayList<T>::insertAt(int location, const T& insertItem) {
	if (location < 0 || location > maxSize)
		cerr << "The position of the item to be inserted " << "is out of range" << endl;
	else
		if (length >= maxSize)
			cerr << "Cannot insert in a full list" << endl;
		else {
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];
			list[location] = insertItem;
			length++;
		}
}

template <class T>
void ArrayList<T>::insertEnd(const T& insertItem) {
	if (length >= maxSize)
		cerr << "Cannot insert in a full list" << endl;
	else {
		list[length] = insertItem;
		length++;
	}
}

template <class T>
void ArrayList<T>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed " << "is out of range" << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
		{
			list[i] = list[i + 1];
		}
		length--;

	}
}

template <class T>
void ArrayList<T>::retrieveAt(int location, T& retItem) const {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is " << "out of range." << endl;
	else
		retItem = list[location];
}

template <class T>
void ArrayList<T>::replaceAt(int location, const T& repItem) {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is " << "out of range." << endl;
	else
		list[location] = repItem;
}

template <class T>
void ArrayList<T>::clearList() {
	length = 0;
}

template <class T>
ArrayList<T>::ArrayList(int size) {
	if (size < 0) {
		cerr << "The array size must be positive. Creating " << "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new T[maxSize];
	assert(list != NULL);
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] list;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherList) {
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new int[maxSize];
	assert(list != NULL);
	for (int j = 0; j < length; j++)
		list[j] = otherList.list[j];
}

template <class T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& otherList) {
	if (this != &otherList) {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new T[maxSize];
		assert(list != NULL);
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class T>
int ArrayList<T>::seqSearch(const T& item) const
{
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
}

template <class T>
void ArrayList<T>::insert(const T& insertItem) {
	int loc;
	if (length == 0)
		list[length++] = insertItem;
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else {
		loc = seqSearch(insertItem);
		if (loc == -1)
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in " << "the list. No duplicates are allowed." << endl;
	}
}

template <class T>
void ArrayList<T>::remove(const T& removeItem)
{
	int loc;
	if (length == 0)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
}

//Assignment
template <class T>
void ArrayList<T>::MyRemoveAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed " << "is out of range" << endl;
	else
	{
		list[location] = list[length - 1];
		length--;
	}
}
template <class T>
void ArrayList<T>::removeAll(const T& item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			remove(list[i]);
		}
	}
}
template <class T>
ArrayList<int> ArrayList<T>::findAll(const T& item)
{
	ArrayList<int> temp;
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			temp.list[j] = i;
			j++;
		}
	}
	temp.length = j ;
	return temp;
}
template <class T>
bool ArrayList<T>::operator>(const ArrayList <T> & otherList)
{
	if (this->length > otherList.length)
		return true;
	else
		return false;

}
template <class T>
T ArrayList<T> ::minFunc(const ArrayList <T>& otherList)
{
	T temp = otherList.list[0];
	for (int i = 0; i < otherList.length; i++)
	{
		if (temp < otherList.list[i])
		{
			temp = otherList.list[i];
		}
	}
	return temp;
}

int main()
{
	ArrayList<string> A;
	A.insertAt(0, "Ahmad");
	A.insertAt(1, "Foaad");
	A.insertAt(2, "Mohammad");
	A.insertAt(3, "sara");
	A.insertAt(4, "Faris");
	A.insertAt(5, "Mohammad");
	A.insertAt(6, "Sara");
	A.insertAt(7, "Samer");
	A.insertAt(8, "Abdallah");
	A.insertAt(9, "Faris");
	cout <<"                 0     1       2      3     4       5      6    7      8       9" << endl;
	cout << "All elemants = "; A.print();
	cout << endl;
	cout << "                            0     1       2      3     4       5      6     7      8       " << endl;
	cout << "Delete index[6]=>[Sara] = ";
	A.MyRemoveAt(6);
	A.print();
	cout << endl;


	cout << endl;
	cout << "Find All [Faris] = ";
	ArrayList<int> B;
	B = A.findAll("Faris");
	B.print();
	cout << endl;
	cout << "                        0     1      2      3       4      5      6                  " << endl;
	cout << "Remove All [Faris] = ";
	A.removeAll("Faris");
	A.print();
	cout << endl;
	//cout << (A > B) << endl;
	cout << "The Minimum of list [ZAINA] = ";
	cout << A.minFunc(A) << endl;
	cout << endl;
}//Faris Abdulkarim Sahili [12115935]