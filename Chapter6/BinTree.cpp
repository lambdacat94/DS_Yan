#include "BinTree.h"
template <typename T>
bool BinTree<T>::CreateBiTree()
{
	T x;
	cin >> x;
	if (x == end)
		return false;
	BiTNode<T> *p = new BiTNode<T>;
	if (!p)
		return false;
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	head = p;
	create(p, 1, end);
	create(p, 2, end);
}
template <typename T>
bool BinTree<T>::PreOrderTraverse(bool(*visit) (T e))
{
	BiTNode<T> *p = head;
	PreTraverse(p, visit);
	return true;
}

template <typename T>
bool BinTree<T>::InOrderTraverse(bool(*visit) (T e))
{
	BiTNode<T> *p = head;
	InTraverse(p, visit);
	return true;
}

template <typename T>
bool BinTree<T>::PostOrderTraverse(bool(*visit)(T e))
{
	BiTNode<T> *p = head;
	PostTraverse(p, visit);
	return true;
}

template <typename T>
bool LevelOrderTraverse(bool(*visit)(T e))
{
	BiTNode<T> *Queue[100];
	BiTNode<T> *b;
	int front, rear;
	front = rear = 0;
	if (head != NULL)
	{
		Queue[rear++] = head;
		while (front != rear)
		{
			b = Queue[front++];
			if (b->lchild)
				Queue[rear++] = b->lchild;
			if (b->rchild)
				Queue[rear++] = b->rchild;
		}
	}
	return true;
}
//以下是严蔚敏的原版实现代码
/*
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	if(T)
	{
		if(visit(T->data))
			if(PreOrderTraverse(T->lchild, visit))
				if(PreOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	else
		return ERROR;
	//代码不漂亮
*/

/*
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	InitStack(S);
	Push(S, T);
	while(!StackEmpty(S))
	{
		while(GetTop(S, p) && p)
			Push(S, p->lchild);
		Pop(S, p);
		if(!StackEmpty(S))
		{
			Pop(S, p);
			if(!visit(p->data))
				return ERROR;
			Push(S, p->rchild);
		}
	}
	return OK;
}
*/

/*
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if (T) {
		if (OK == PostOrderTraverse(T->lchild, visit))
			if (OK == PostOrderTraverse(T->rchild, visit))
				if (OK == visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
*/


/*
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	BiTree p;
	LinkQueue Q;
	InitQueue(Q);
	p = T;
	while (p || !QueueEmpty(Q)) {
		if (p) {
			visit(p->data);
			if (p->lchild)
				EnQueue(Q, p->lchild);
			if (p->rchild)
				EnQueue(Q, p->rchild);
			if (!QueueEmpty(Q))
				DeQueue(Q, p);
			else
				break;
		}
	}
	return OK;
}
*/


/*
Status CreateBiTree(BiTree &T)
{
	scanf(&ch);
	if(ch == ' ')
		T = NULL;
	else
	{
		if(!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
*/


/*
Status PreOrderTraverse2(BiTree T, Status (*visit)(TElemType e))
{
	SqStack S;
	BiTree p;
	InitStack(S);
	p = T;
	while (p || !StackEmpty(S)) {
		if (p) {	//访问根指针，左指针进栈
			if (ERROR == visit(p->data))
				return ERROR;
			Push(S, p);
			p = p->lchild;
		}
		else 
		{
			Pop(S, p);
			p = p->rchild;
		}
	}
	return OK;
}

*/