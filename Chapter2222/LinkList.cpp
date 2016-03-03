#include <iostream>

#include "LinkList.h"

template<class T>
Status LinkList<T>::InitList()
{
	Head = new Node<T>;
	Head->next = NULL;
	length = 0;
	return OK;
}

template<class T>
Status LinkList<T>::DestroyList()
{
	Node<T> *p;
	while(Head)
	{
		p = Head;
		Head = Head->next;
		delete p;
	}
	length = 0;
	return OK;
}

template<class T>
Status LinkList<T>::ClearList()
{
	Head = NULL;
	length = 0;
	return OK;
}

template<class T>
bool LinkList<T>::ListEmpty()
{
	if(Head->next == NULL)
		return true;
	return false;
}

template<class T>
int LinkList<T>::ListLength()
{
	int len = 0;
	Node<T> *p;
	p = Head;
	while(p->next)
	{
		len++;
		p = p->next;
	}
	return len;
	//else we can return this->length;
}

template<class T>
Status LinkList<T>::GetElem(int i, T &e)
{
	Node<T> *p;
	p = Head->next;
	int j = 1;
	while(p && j < i)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i)
		return ERROR;
	else
		e = p->next;
	return OK;
}

template<class T>
int LinkList<T>::LocateElem(T e, Status (*compare)(T, T))
{
	int j = 1;
	Node<T> *p = Head->next;
	while(p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if(p == NULL)
		return 0;
	else
		return j;
}

template<class T>
Status LinkList<T>::PriorElem(T cur_e, T &pre_e)
{
	Node<T> *p = Head, *q = p->next;
	while(q && q->data != cur_e)
	{
		p = q;
		q = q->next;
	}
	if(p == Head || q == NULL)
		return ERROR;
	else
		pre_e = p->data;
	return OK;
}

template<class T>
Status LinkList<T>::NextElem(T cur_e, T &next_e)
{
	Node<T> *p = Head, *q = p->next;
	while(p && p->data != cur_e)
	{
		p = q;
		q = q->next;
	}
	if(p == Head || q == NULL)
		return ERROR;
	else
		next_e = q->data;
	return OK;
}

template<class T>
Status LinkList<T>::ListInsert(int i, T e)
{
	int j = 0;
	Node<T> *p = Head;
	while(p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if(!p || j > j  - 1)
		return ERROR;
	else
	{
		Node<T> *s = new Node<T>;
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
	return OK;
}


template<class T>
Status LinkList<T>::ListDelete(int i, T &e)
{
	Node<T> *p = Head, *q;
	int j = 0;
	while(p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if(!p->next && j < i - 1)
		return ERROR;
	else
	{
		q = p->next;
		p->next = q->next;
		e = q->data;
		delete q;
	}
	return OK;
}

template<class T>
Status LinkList<T>::ListTraverse(Status (*visit)(T))
{
	Node<T> *p = Head->next;
	while(visit(p))
	{
		p = p->next;
	}
	return OK;
}























