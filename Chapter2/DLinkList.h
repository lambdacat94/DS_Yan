#ifndef CHAPTER2_DLINKLIST
#define CHAPTER2_DLINKLIST
template <typename T>
class DLinkList;

template <typename Type>
class LNode
{
//	friend class DLinkList;
public:
	LNode();
	LNode(Type elem);
	~LNode();
private:
	LNode<Type> *next;
	Type data;
};


template <typename T>
class DLinkList
{
public:
	DLinkList();
	DLinkList(T elem);
	~DLinkList();
	bool InitList();

	bool DestroyList();

	bool ClearList();
	//��s��ָ�ڵ�����һ���ڵ�֮ǰ
	bool InsFirst(const LNode<T> &s);
	//ɾ�������еĵ�һ���ڵ㣬����q����
	bool DelFrist(LNode<T> *&q);
	//���������׷��һ��Ԫ��
	bool Append(const LNode<T> &s);
	//ɾ��β�ڵ㲢��q����
	bool Remove(LNode<T> &q);
	//��s��ָ���Ԫ�ز��뵽p֮ǰ
	bool InsBefore(const LNode<T> &p, const LNode<T> &s);
	bool InsAfter(const LNode<T> &p, const LNode<T> &s);
	bool SetCurElem(T e);
	T GetCurElem();
	bool ListEmpty();
	int ListLength();
	LNode<T> GetHead();
	LNode<T> GetLast();
	LNode<T> PriorPos();
	LNode<T> NextPos(int i, LNode<T> *p);
	bool LocatePos(int i, LNode<T> *&p);
	LNode<T> LocateElem(T e, bool(*compare)(T, T));
	bool ListTraverse(bool(*visit)(T));

	//bool MakeNode(const LNode<T> &p, T e);
private:
	LNode<T> *head, *tail;
	int len;
};
#endif  //CHAPTER2_DLINKLIST

