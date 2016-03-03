#include "LinkQueue.h"

template <typename T>
QNode<T>::QNode()
{
}

template <typename T>
QNode<T>::~QNode()
{
}

template <typename T>
bool LinkQueue<T>::InitQueue()
{
	front = new QNode < T > ;
	if (!front)
		return false;
	front->next = NULL;
	rear = front;
	return true;
}

template <typename T>
LinkQueue<T>::LinkQueue()
{
	InitQueue();
}

template <typename T>
bool LinkQueue<T>::DestroyQueue()
{
	while (front)
	{
		rear = front->next;
		delete front;
		front = rear;
	}
	return true;
}


template <typename T>
LinkQueue<T>::~LinkQueue()
{
	DestroyQueue();
}

template <typename T>
bool LinkQueue<T>::ClearQueue()
{
	QNode<T> *p, *temp;
	p = front->next;
	front->next = NULL;
	rear = front;
	while (p)
	{
		temp = p->next;
		delete p;
		p = temp;
	}
	return true;
}
/*	
	bool QueueEmpty();
	int QueueLength();
	bool GetHead(T &e);
	bool EnQueue(T e);
	bool DeQueue(T &e);
	bool QueueTraverse(bool(*visit)(T &e));
*/
template <typename T>
bool LinkQueue<T>::QueueEmpty()
{
	return front == rear ? true : false;
}
template <typename T>
int LinkQueue<T>::QueueLength()
{
	QNode<T> *p;
	int len = 0;
	p = front->next;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

template <typename T>
bool LinkQueue<T>::GetHead(T &e)
{
	if (front == rear)
		return false;
	e = front->next->data;
	return true;
}

template <typename T>
bool LinkQueue<T>::EnQueue(T e)
{
	QNode<T> *p = new QNode < T > ;
	if (!p)
		return false;
	p->data = e;
	p->next = NULL;
	rear->next = p;
	rear = p;
	return true;
}

template <typename T>
bool LinkQueue<T>::DeQueue(T &e)
{
	QNode<T> *p = front->next;
	if (front == rear)
		return false;
	e = p->data;
	if (front->next == rear)
		rear = front;
	front->next = p->next;
	delete p;
	p = NULL;
	return true;
}

template <typename T>
bool LinkQueue<T>::QueueTraverse(bool(*visit)(T &))
{
	QNode<T> *p = front->next;
	while (p)
	{
		if (!(*visit)(p->data))
			return false;
		p = p->next;
	}
	return true;
}



