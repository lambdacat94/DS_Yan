#include "SqStack.h"
//这次我改变了编程风格

template <typename T>
SqStack<T>::SqStack()
{
	InitStack();
}

template <typename T>
SqStack<T>::~SqStack()
{
	DestroyStack();
}

template <typename T>
bool SqStack<T>::InitStack()
{
	base = new T[stack_init_size];
	if (base)
		return false;
	top = base;
	stacksize = stack_init_size;
	return true;
}

template <typename T>
bool SqStack<T>::DestroyStack()
{
	delete base;
	base = NULL;
	return true;
}


template <typename T>
bool SqStack<T>::ClearStack()
{
	top = base;
	return true;
}

template <typename T>
bool SqStack<T>::StackEmpty()
{
	return (base == top ? true : false);
}

template <typename T>
int SqStack<T>::StackLength()
{
	return (top - base);
}


template <typename T>
bool SqStack<T>::GetTop(T &e)
{
	if (base == top)
		return false;
	e = *(top - 1);
	return true;
}
template <typename T>
int SqStack<T>::GetTop()
{
	return *(top - 1);
}
template <typename T>
bool SqStack<T>::Push(T e)
{
	if (stacksize == StackLength())
	{
		return false;	//Oh, I dont want to care about the exceptions,so return false
	}
	top = e;
	top++;
	return true;
}
template <typename  T>
bool SqStack<T>::Pop(T & e)
{
	if (top == base)
		return false;
	e = *(top - 1);
	top--;
	return true;
}
template <typename T>
bool SqStack<T>::StackTraverse(bool(*visit)(T))
{
	T *p = base;
	while (p != top)
	{
		visit(*p);
		++p;
	}
	return true;
}