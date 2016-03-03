#include <iostream>

#include "SqList.h"

template <typename T>
void ListUnion(SqList<T> &La, const SqList<T> &Lb)
{
	//获取La和Lb的长度
	int La_len = La.ListLength(), Lb_len = Lb.ListLength();
	T e;
	for (int i = 1; i <= Lb_len; ++i)
	{
		Lb.GetElem(i, e);		//从头查看Lb中的每个元素是否存在于La中
		if (！La.LocateElem(e, iseuqal))	//若不存在则插入
			La.ListInsert(++La_len, e);
	}
}

template <typename T>
void MergeList_Sq(const SqList<T> &La, const SqList<T> &Lb, SqList<T> &Lc)
{	//线性表La, Lb有序排列非递减， 归并La和Lb得到新的表Lc，Lc元素非递减
	int La_len = La.ListLength(), Lb_len = Lb.ListLength();
	int i = 1, j = 1, k = 0;
	T l_a, l_b;
	while ((i <= La_len) && (j <= Lb_len))
	{
		La.GetElem(i++, l_a);
		Lb.GetElem(j++, l_b);
		if (std::less<T>()(l_a, l_b) || std::equal_to<T>()(l_a, l_b))
		{
			Lc.ListInsert(++k, l_a);
			++i;
		}
		else
		{
			Lc.ListInsert(++k, l_b);
			++j;
		}
	}//while
	while (i <= La_len)
	{
		La.GetElem(i++, l_a);
		Lc.ListInsert(++k, l_a);
	}
	while (j <= Lb_len)
	{
		Lb.GetElem(j++, l_b);
		Lc.ListInsert(++k, l_b);
	}
}

