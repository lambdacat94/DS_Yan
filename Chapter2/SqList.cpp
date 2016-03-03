#include <iostream>

#include "SqList.h"


template <typename T>
SqList<T>::SqList():length(0), listsize(list_init_size)
{
	this->elem = new T[list_init_size];	//这里没有处理存储分配失败，new如果失败会
						//throw std::bad_alloc不用处理
}

template <typename T>
SqList<T>::SqList(int con):length(con), listsize(con)
{
	this->elem = new T[con];
}

template <typename T>
SqList<T>::~SqList()
{
	delete[] elem;
	elem = nulptr;
	this->length = 0;
	this->listsize = 0;
}


template <typename T>
bool SqList<T>::ListEmpty()
{
	return (this->length == 0) ? true : false;
}


template <typename T>
int SqList<T>::ListLength()
{
	return this->length;
}

template <typename T>
bool SqList<T>::GetElem(int i, T &e)
{
	if (i <= 0 || i >= this->length + 1)
		return false;						
	e = *(elem + i - 1);
	return true;
}

template <typename T>
int SqList<T>::LocateElem(T e, bool(*compare)(T e1, T e2))
{
	int i = 0;
	while (!compare(e, *(elem + i)) && i < length)
		++i;
	if (i == length)
		return 0;
	return i + 1;
}

template <typename T>
bool SqList<T>::PriorElem(T cur_e, T &pre_e)
{
	int pos = LocateElem(cur_e, isequal);
	if (!pos || pos == 1)
		return false;
	pre_e = *(elem + pos - 2);
	return true;
}

template <typename T>
bool SqList<T>::NextElem(T cur_e, T &next_e)
{
	int pos = LocateElem(cur_e, isequal);
	if (!pos || pos == this->length)
		return false;
	next_e = *(elem + pos);
	return true;
}

template <typename T>
bool SqList<T>::ListInsert(int i, T e)
{
	if (i < 1 || i > this->length)
		return false;
	if (length >= listsize)
	{
		T *newbase = new T[listsize + listincrement];
		for (int i = 0; i < length; ++i)
			*(newbase + i) = *(elem + i);
		delete elem;
		elem = newbase;
		newbase = nulptr;
		listsize += listincrement;
	}
	for (int j = length; j >= i; --j)
		*(elem + j) = *(elem + j - 1);
	*(elem + i - 1) = e;
	this->length++;
	return true;
}

template <typename T>
bool SqList<T>::ListDelete(int i, T &e)
{
	if (i < 1 || i > this->length)
		return false;
	for (int j = i; j < this->length; ++j)
		*(elem + j - 1) = *(elem + j);
	this->length--;
	return true;
}

template <typename T>
bool SqList<T>::ListTraverse(bool(*visit)(T e))
{
	for (int i = 0; i < this->length; ++i)
	{
		if (!visit(*(elem + i)))
			return false;
	}
	return true;
}
/*------------------------------golbal------------------------------*/
template <typename T>
bool isequal(T e1, T e2)
{
	return std::equal_to<T>()(e1, e2);
}