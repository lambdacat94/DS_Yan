#ifndef CHAPTER2_SQLIST
#define CHAPTER2_SQLIST

template <typename T>
class SqList
{
//SqList类的接口
public:
	//构造一个空的线性表
	SqList();	
	//构造一个容量为con的线性表
	SqList(int con);
	//相当于DestroyList
	~SqList();
	//若表空，返回true，否则返回false
	bool ListEmpty();
	//返回表中元素个数
	int ListLength();
	//用e返回第i个元素的值
	bool GetElem(int i, T &e);
	//返回第一个与e满足关系compare()的数据元素的位序，若不存在返回0
	int LocateElem(T e, bool(*compare)(T e1, T e2));
	//若cur_e是其中元素，且不是第一个，用pre_e返回前驱，否则操作失败
	bool PriorElem(T cur_e, T &pre_e);
	//若cur_e是其中元素，且不是最后一个，用next_e返回其后继，否则操作失败
	bool NextElem(T cur_e, T &next_e);
	//在第i个位置之前插入新的数据元素e，表长加1
	bool ListInsert(int i, T e);
	//删除第i个位置元素，用e返回其值，表长减1
	bool ListDelete(int i, T &e);
	//依次对每个元素调用visit(),一旦visit失败，操作失败
	bool ListTraverse(bool(*visit)(T e));
	/*---------------------------------------------------------------*/

private:
	T * elem;						//存储空间基址
	int length;						//当前长度
	int listsize;						//当前分配的链表容量
	static const int list_init_size = 100;	//书中的初始分配量
	static const int listincrement = 10;	//书中的分配增量
};

/*------------------------------golbal------------------------------*/
template <typename T>
bool isequal(T e1, T e2);
#endif