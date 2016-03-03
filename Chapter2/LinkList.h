#ifndef CHAPTER2_LINKLIST
#define CHAPTER2_LINKLIST

template <typename T>
struct LNode
{
	T data;
	struct LNode<T> *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, T &e);
	int LocateElem(T e, bool(*compare)(T e1, T e2));
	bool PriorElem(T cur_e, T &pre_e);
	bool NextElem(T cur_e, T &next_e);
	bool ListInsert(int i, T e); 
	bool ListDelete(int i, T &e);
	bool ListTraverse(bool(*visit)(T e));

private:
	LNode<T> *Head;
};

template <typename T>
bool isequal(T e1, T e2);
#endif