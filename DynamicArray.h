#pragma once

#include "Tutorial.h"
#include <stdexcept>
using namespace std;

template <typename type>
class DynamicArray {
	int length;
	int capacity;
	type* da;
	void resize();
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();
	void addDynamicArray(type element);
	void removeDynamicArray(int index);
	type operator[](int index);
	int size();
	type getAll();
};

template<typename type>
inline DynamicArray<type>::DynamicArray()
{
	/*this->da = new type[2];
	this->capacity = 2;
	this->length = 0;
	*/
}

template<typename type>
inline DynamicArray<type>::DynamicArray(int capacity)
{
	this->da = new type[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template<typename type>
inline DynamicArray<type>::~DynamicArray()
{
	delete this->da;
}

template<typename type>
inline void DynamicArray<type>::resize()
{
	type* newDa = new type[this->capacity * 2];
	for (int i = 0; i < this->length; i++)
		newDa[i] = this->da[i];
	delete[] this->da;
	this->da = newDa;
}


template<typename type>
inline void DynamicArray<type>::addDynamicArray(type element)
{
	if (this->length == this->capacity)
			resize();
	this->da[length++] = element;
}

template<typename type>
inline void DynamicArray<type>::removeDynamicArray(int index)
{
	for (int i = index; i < this->length - 1; i++)
		this->da[i] = this->da[i + 1];
	this->length--;
}

template<typename type>
inline type DynamicArray<type>::operator[](int index)
{
	return this->da[index];
}

template<typename type>
inline int DynamicArray<type>::size()
{
	return this->length;
}

template<typename type>
inline type DynamicArray<type>::getAll()
{
	return da;
}



