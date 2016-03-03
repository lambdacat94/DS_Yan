#include <iostream>

#include "SqList.h"

template <typename T>
void ListUnion(SqList<T> &La, const SqList<T> &Lb)
{
	//��ȡLa��Lb�ĳ���
	int La_len = La.ListLength(), Lb_len = Lb.ListLength();
	T e;
	for (int i = 1; i <= Lb_len; ++i)
	{
		Lb.GetElem(i, e);		//��ͷ�鿴Lb�е�ÿ��Ԫ���Ƿ������La��
		if (��La.LocateElem(e, iseuqal))	//�������������
			La.ListInsert(++La_len, e);
	}
}

template <typename T>
void MergeList_Sq(const SqList<T> &La, const SqList<T> &Lb, SqList<T> &Lc)
{	//���Ա�La, Lb�������зǵݼ��� �鲢La��Lb�õ��µı�Lc��LcԪ�طǵݼ�
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

