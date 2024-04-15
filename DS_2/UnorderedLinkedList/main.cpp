#include "UnorderedLinkedListT.h"
#include "LinkedListT.h"

int main()
{
	UnorderedLinkedList<string> L;
	L.insertFirst(20);
	L.insertLast(22);
	L.insertFirst(2);
	L.insertFirst(100);
	L.insertFirst(5);
	L.print();

	return 0;
}