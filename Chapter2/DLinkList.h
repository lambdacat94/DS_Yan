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
	//将s所指节点插入第一个节点之前
	bool InsFirst(const LNode<T> &s);
	//删除链表中的第一个节点，并以q返回
	bool DelFrist(LNode<T> *&q);
	//在链表最后追加一个元素
	bool Append(const LNode<T> &s);
	//删除尾节点并以q返回
	bool Remove(LNode<T> &q);
	//把s所指向的元素插入到p之前
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

