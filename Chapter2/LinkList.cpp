#include <iostream>

#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList()
{
	Head = new LNode < T > ;
	Head->next = NULL;		//或者nulptr，使用NULL为了向下兼容
}

template <typename T>
LinkList<T>::~LinkList()
{
	LNode<T> *p;
	while (Head)
	{
		p = Head;
		Head = Head->next;
		delete p;
	}
	delete Head;
	Head = NULL;
}

template <typename T>
void LinkList<T>::ClearList()
{
	LNode <T> *p;
	while (Head)
	{
		p = Head;
		Head = Head->next;
		delete p;
	}
	Head->next = NULL;
}

template <typename T>
bool LinkList<T>::ListEmpty()
{
	return (Head->next == NULL) ? true : false;
}

template <typename T>
int LinkList<T>::ListLength()
{
	int len = 0;
	LNode<T> * p = Head->next;
	while (p)
	{
		p = p->next;
		len++;
	}
	return len;
}

template <typename T>
bool LinkList<T>::GetElem(int i, T &e)
{
	if (i <= 0 || i > this->length + 1)
		return false;
	LNode<T> *p = Head;
	for (int j = 1; j <= i; ++j)
		p = p->next;
	e = p->data;
	return true;
}

template <typename T>
int LinkList<T>::LocateElem(T e, bool(*compare)(T e1, T e2))
{
	LNode<T> *p = Head->next;
	int len = 0;
	while (p)
	{
		if (!compare(e, p->data))
		{
			++len;
			p = p->next;
		}
	}
	if (len == length)
		return 0;
	return len + 1;
}

template <typename T>
bool LinkList<T>::PriorElem(T cur_e, T &pre_e)
{
	int pos = LocateElem(cur_e, isequal);
	if (pos != 0)
	{
		GetElem(pos - 1, pre_e);
		return true;
	}
	return false;
}

template <typename T>
bool LinkList<T>::NextElem(T cur_e, T &next_e)
{
	int pos = LocateElem(cur_e, isequal);
	if (pos != 0)
	{
		GetElem(pos + 1, next_e);
		return true;
	}
	return false;
}

template <typename T>
bool LinkList<T>::ListInsert(int i, T e)
{
	LNode<T> *p = Head, *s;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return false;
	s = new LNode<T>;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

template <typename T>
bool LinkList<T>::ListDelete(int i, T &e)
{
	LNode<T> *p = Head, *q;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1)
		return false;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return true;
}

template <typename T>
bool LinkList<T>::ListTraverse(bool(*visit)(T e))
{
	LNode<T> *p = Head->next;
	while (p != NULL)
	{
		if (!visit(p->data))
			return false;
	}
	return true;
}


template <typename T>
bool isequal(T e1, T e2)
{
	return std::equal_to<T>()(e1, e2);
}
int main()
{
	return 0;
}



