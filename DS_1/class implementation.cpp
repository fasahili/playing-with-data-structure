#include <iostream>
using namespace std;

#include "header file.h"
#include <string>

LargeInteger::LargeInteger(int size) {
	maxSize = size;
	length = 0;
	number = new short int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		number[i] = 0;
	}
}
LargeInteger::LargeInteger(const LargeInteger& L) {
	length = L.length;
	maxSize = L.maxSize;
	number = new short int[maxSize];
	for (int i = length - 1; i >= 0; i--) {
		number[i] = L.number[i];
	}
}
void LargeInteger::write(ostream& out) const {
	if (length == 0) out << "NaN";
	for (int i = length - 1; i >= 0; i--) {
		out << number[i];
	}
	out << "";
}

bool LargeInteger::setNumber(string str) {
	int len = str.length();
	if (maxSize < len) {
		length = 0;
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			length = 0;
			return false;
		}
		number[len - 1 - i] = str[i] - '0';
	}
	length = len;
	return true;
}


void LargeInteger::read(istream& in) {
	string str;
	bool tryagain = false;
	while (in.good()) {
		in >> str;
		if (setNumber(str)) break;
		cerr << "invalid number try again " << endl;
	}
}

LargeInteger LargeInteger:: operator+(const LargeInteger& L)const {
	LargeInteger s;
	int x = 0, rest = 0, i, size, y = 0;
	if (length >= L.length) { size = length; }
	else { size = L.length; }
	for (i = 0; i < length; i++) {
		x = number[i] + L.number[i] + rest;
		y = x % 10;
		s.number[i] = y;
		rest = x / 10;
		s.length++;
	}
	if (rest) {
		s.length++;
		s.number[i] = rest;
	}
	return s;
}


LargeInteger LargeInteger::operator*(const LargeInteger& L) const {
	LargeInteger res(maxSize + L.maxSize);
	for (int i = 0; i < maxSize; i++) {
		int carry = 0;
		for (int j = 0; j < L.maxSize; j++) {
			int prod = number[i] * L.number[j] + carry + res.number[i + j];
			carry = prod / 10;
			res.number[i + j] = prod % 10;
		}
	}
	return res;
}

LargeInteger LargeInteger:: operator-(const LargeInteger& L)const {
	LargeInteger d;
	int size;
	if (length >= L.length) { size = length; }
	else { size = L.length; }
	for (int i = 0; i < size; i++) {
		if (number[i] < L.number[i]) {
			number[i + 1] = number[i + 1] - 1;
			number[i] = number[i] + 10;
		}
		d.number[i] = number[i] - L.number[i];
		d.length++;
	}
	return d;
}
bool LargeInteger:: operator ==(const LargeInteger& L) const {
	if (length != L.length)return false;
	for (int i = 0; i < length; i++) {
		if (number[i] != L.number[i]) {
			return false;
		}
	}
	return true;
}
const LargeInteger& LargeInteger:: operator = (const LargeInteger& L) {
	length = L.length;
	maxSize = L.maxSize;
	delete[] number;
	number = new short int[maxSize];
	for (int i = length - 1; i >= 0; i--) {
		number[i] = L.number[i];
	}
	return *this;
}
bool LargeInteger:: operator < (const LargeInteger& L)const {
	if (length > L.length)return false;
	for (int i = 0; i < length; i++) {
		if (number[i] > L.number[i]) {
			return false;
		}
	}
	return true;
}
bool LargeInteger:: operator > (const LargeInteger& L)const {
	if (length < L.length)return false;
	for (int i = 0; i < length; i++) {
		if (number[i] < L.number[i]) {
			return false;
		}
	}
	return true;
}
LargeInteger::~LargeInteger() {
	if (number != NULL) {
		delete[]number;
	}
}
