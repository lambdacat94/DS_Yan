#ifndef CHAPTER2_SQLIST
#define CHAPTER2_SQLIST

template <typename T>
class SqList
{
//SqList��Ľӿ�
public:
	//����һ���յ����Ա�
	SqList();	
	//����һ������Ϊcon�����Ա�
	SqList(int con);
	//�൱��DestroyList
	~SqList();
	//����գ�����true�����򷵻�false
	bool ListEmpty();
	//���ر���Ԫ�ظ���
	int ListLength();
	//��e���ص�i��Ԫ�ص�ֵ
	bool GetElem(int i, T &e);
	//���ص�һ����e�����ϵcompare()������Ԫ�ص�λ���������ڷ���0
	int LocateElem(T e, bool(*compare)(T e1, T e2));
	//��cur_e������Ԫ�أ��Ҳ��ǵ�һ������pre_e����ǰ�����������ʧ��
	bool PriorElem(T cur_e, T &pre_e);
	//��cur_e������Ԫ�أ��Ҳ������һ������next_e�������̣��������ʧ��
	bool NextElem(T cur_e, T &next_e);
	//�ڵ�i��λ��֮ǰ�����µ�����Ԫ��e������1
	bool ListInsert(int i, T e);
	//ɾ����i��λ��Ԫ�أ���e������ֵ������1
	bool ListDelete(int i, T &e);
	//���ζ�ÿ��Ԫ�ص���visit(),һ��visitʧ�ܣ�����ʧ��
	bool ListTraverse(bool(*visit)(T e));
	/*---------------------------------------------------------------*/

private:
	T * elem;						//�洢�ռ��ַ
	int length;						//��ǰ����
	int listsize;						//��ǰ�������������
	static const int list_init_size = 100;	//���еĳ�ʼ������
	static const int listincrement = 10;	//���еķ�������
};

/*------------------------------golbal------------------------------*/
template <typename T>
bool isequal(T e1, T e2);
#endif