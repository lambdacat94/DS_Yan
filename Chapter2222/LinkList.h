#ifndef CHAPTER_2_LINKLIST
#define CHAPTER_2_LINKLIST

template<class T>
struct LNode
{
	T data;
	struct LNode *next;
};

template<class T>
class LinkList
{
public:
	Status InitList();
	Status DestroyList();
	Status ClearList();
	bool ListEmpty();
	int ListLength();
	Status GetElem(int i, T &e);
	Status LocateElem(T e, Status (*compare)(T, T));
	Status PriorElem(T cur_e, T &pre_e);
	Status NextElem(T cur_e, T &next_e);
	Status ListInsert(int i, T e);
	Status ListDelete(int i, T &e);
	Status ListTraverse(Status (*visit)(T));
private:
	int length;
	LList<T> Head;
};

#endif
