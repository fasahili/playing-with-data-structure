#include <iostream>
using namespace std;
#include "header file.h"
#include <string>


int main()
{
	LargeInteger a(8), b(8), c(8);
	cout << "Please Enter First Nnumber = ";
	a.read(cin);
	cout << endl;
	cout << "Please Enter Second Nnumber = ";
	b.read(cin);
	cout << endl;
	cout << "The Result = ";
	c = a + b;
	c.write(cout);
	cout << endl;
	cout << endl;
}
