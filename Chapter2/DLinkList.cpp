#include "DLinkList.h"

template <typename Type>
LNode<Type>::LNode()
{}
template <typename Type>
LNode<Type>::LNode(Type elem) :data(elem), next(NULL)
{}
template <typename Type>
LNode<Type>::~LNode()
{}


template <typename T>
DLinkList<T>::DLinkList() :len(0)
{
	LNode<T> *p = new LNode < T > ;
	p->next = NULL;
	head = tail = p;
}
template <typename T>
DLinkList<T>::DLinkList(T elem):len(0)
{
	LNode<T> *p = new LNode<T>(elem);
	p->next = NULL;
	head = tail = p;
}

template <typename T>
DLinkList<T>::~DLinkList()
{
	ClearList();
	delete head;
	head = tail = NULL;
	len = 0;
}
template <typename T>
bool DLinkList<T>::ClearList()
{
	LNode<T> *p, *q;
	p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}//添加catch处理删除的错误然后返回false
	tail = head;
	len = 0;
	return true;
}

template < typename T >
bool DLinkList<T>::InsFirst(const LNode<T> &s)
{
	//const &不可能有空引用，所以这部分不用检测错误
	s.next = head->next;
	head->next = s;
	return true;
}

template <typename T>
bool DLinkList<T>::DelFrist(LNode<T> *&q)
{
	if (ListEmpty())
		return false;
	q = head->next;
	head->next = q->next;
	q->next = NULL;
	return true;
}

template <typename T>
bool DLinkList<T>::Append(const LNode<T> &s)
{

}
template <typename T>
bool DLinkList<T>::Remove(LNode<T> &q)
{

}
template <typename T>
bool DLinkList<T>::InsBefore(const LNode<T> &p, const LNode<T> &s)
{

}
template  <typename T>
bool DLinkList<T>::InsAfter(const LNode<T> &p, const LNode<T> &s)
{

}
template <typename T>
bool DLinkList<T>::SetCurElem(cosnt T &e)
{

}
template <typename T>
T DLinkList<T>::GetCurElem() const
{

}
template <typename T>
bool DLinkList<T>::ListEmpty() const
{

}
template <typename T>
int DLinkList<T>::ListLength() const
{

}
template <typename T>
LNode<T> DLinkList<T>::GetHead()
{

}
template <typename T>
LNode<T> DLinkList<T>::GetLast()
{

}
template <typename T>
LNode<T> DLinkList<T>::PriorPos()
{

}
template <typename T>
LNode<T> DLinkList<T>::NextPos(int i, LNode<T> *p)
{

}
template <typename T>
bool DLinkList<T>::LocatePos(int i, LNode<T> *&p)
{

}
template <typename T>
LNode<T> DLinkList<T>::LocateElem(T e, bool(*compare)(T, T))
{

}
template <typename T>
bool DLinkList<T>::ListTraverse(bool(*visit)(T))
{


}










