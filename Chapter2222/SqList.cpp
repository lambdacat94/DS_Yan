#include "SqList.h"
// This Impletment maybe some strange, but I don't know where

template<class T>
Status SqList<T>::InitList()
{
	elem = new T[LIST_INIT_SIZE];
	length = 0;
	listsize = LIST_INIT_SIZE;
	return OK;
}

template<class T>
Status SqList<T>::DestroyList()
{
	delete []elem;
	length = 0;
	listsize = 0;
	return OK;
}

template<class T>
Status SqList<T>::ClearList();
{
	length = 0;
	return OK;
}

template<class T>
bool SqList<T>::ListEmpty()
{
	if(length == 0)
		return true;
	return false;
}

template<class T>
int SqList<T>::ListLength()
{
	return length;
}

template<class T>
Status SqList<T>::GetElem(int i, T &e)
{
	e = *(elem + i -1);
	return OK;
}

template<class T>
int SqList<T>::LocateElem(T e, Status (* compare)(T, T))
{
	for(int i = 0; i < length; ++i)
	{
		if(compare(e, *(elem + i -1)))
				return i;
	}
	return 0;
}

template<class T>
Status PriorElem(T cur_e, T &pre_e)
{
	int pos = LocateElem(cur_e);
	if(!pos || pos == length)
		return ERROR;
	return *(elem + pos - 2);
}

template<class T>
Status NextElem(T cur_e, T &next_e)
{
	int pos = LocateElem(cur_e);
	if(!pos || pos == length)
		return ERROR;
	return *(elem + pos);
}

template<class T>
Status ListInsert(int i, T e)
{
	if(i < 1 || i > length + 1)
		return ERROR;					//throw Exception will better
	for(int j = length; j >= i; --j)
		elem[j] = elem[j - 1];
	elem[i - 1] = e;
	length++;
	return OK;
}

template<class T>
Status ListDelete(int i, T &e)
{
	if(i < 1 || i > length)
		return ERROR;
	e = elem[i - 1];
	for(int j = i; j < length; ++j)
		elem[j - 1] = elem[j];
	length--;
	return OK;
}

template<class T>
Status ListTraverse(Status (*visit)(T))
{
	for(int i = 0; i < length; ++i)
	{
		if(!visit(elem[i]))
			return ERROR;
	}
	return OK;
}

