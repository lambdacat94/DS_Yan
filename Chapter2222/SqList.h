#ifndef CHAPTER_2_SQLIST
#define CHAPTER_2_SQLIST

#define LIST_INIT_SIZE  100
#define LISTINCREMENT	10

template<class T>
class SqList
{
public:
	Status InitList();
	Status DestroyList();
	Status ClearList();
	Status ListEmpty();
	int ListLength();
	Status GetElem(int i, T &e);
	int LocateElem(T e, Status (*compare)());
	Status PriorElem(T cur_e, T &pre_e);
	Status NextElem(T cur_e, T &next_e);
	Status ListInsert(int i, T e);
	Status ListDelete(int i, T &e);
	Status ListTraverse(Status (*visit)(T));
private:
	T *elem;
	int length;
	int listsize;
}
#endif
