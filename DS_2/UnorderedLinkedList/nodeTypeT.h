#pragma once

template <class T>
struct nodeType {
	T info;
	nodeType<T>* link;
};