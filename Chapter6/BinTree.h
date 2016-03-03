#ifndef CHAPTER6_BINTREE
#define CHAPTER6_BINTREE

template <typename T>
class BiTNode{
public:
protected:
	T data;
	class BiTNode<T> *lchild, *rchild;
};

template <typename T>
class BinTree{
	BinTree();
	~BinTree();

	bool CreateBiTree();
	bool PreOrderTraverse(bool(*visit) (T e));
	bool InOrderTraverse(bool(*visit) (T e));
	bool PostOrderTraverse(bool(*visit)(T e));
	bool LevelOrderTraverse(bool(*visit)(T e));

protected:
	BiTNode<T> *head;
	int depth;
};

//------------------------------------static---------------------------------------//
template <typename T>
static int create(BiTNode<T> *p, int k, T end)
{
	BiTNode<T> *q;
	T x;
	cin >> x;
	if (x != end)
	{
		q = new BiTNode < T > ;
		q->data = x;
		q->lchild = NULL;
		q->rchild = NULL;
		if (k == 1)
			p->lchild = q;
		if (k == 2)
			p->rchild = q;
		create(q, 1, end);
		create(q, 2, end);
	}
	return 0;
}

template <typename T>
static int PreTraverse(BiTNode<T> *p, bool(*visit) (T e))
{
	if (p != NULL)
	{
		visit(p->data);
		PreTraverse(p->lchild);
		PreTraverse(p->rchild);
	}
	return 0;
}

template <typename T>
static int InTraverse(BiTNode<T> *p, bool(*visit) (T e))
{
	if (p != NULL)
	{
		InTraverse(p->lchild);
		visit(p->data);
		InTraverse(p->rchild);
	}
}

template <typename T>
static int PostTraverse(BiTNode<T> *p, bool(*visit)(T e))
{
	if (p != NULL)
	{
		PostTraverse(p->lchild);
		PostTraverse(p->rchild);
		visit(p->data);
	}
}
#endif