#ifndef	_POLYNOMIAL_H_
#define _POLYNOMIAL_H_

typedef struct {  //��ı�ʾ����������
	float coef; // ϵ��
	int expn;   // ָ��
} Term;

typedef struct PNode{    // ������ͣ�����
	Term elem;
	struct PNode * next;
}*pLink;

typedef struct {     //��������, ����ʽ��ʾ
	pLink head, tail;
	int len;
}polynomial;
void CreatePolyn(polynomial &P, int m);
void DestroyPolyn(polynomial &P);
int PolyLength(polynomial &P);
void AddPolyn(polynomial &Pa, polynomial &Pb);
void subtractPolyn(polynomial &Pa, polynomial &Pb);
void MultiplyPolyn(polynomial &Pa, polynomial &Pb);

#endif