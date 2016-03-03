#ifndef CHAPTER3_LINKQUEUE
#define CHAPTER3_LINKQUEUE

template <typename T>
class QNode{
	//friend class LinkQueue<T>;
public:
	QNode();
	~QNode();
protected:
	T data;
	class QNode<T> *next;
};


template <typename T>
class LinkQueue{
public:
	LinkQueue();
	~LinkQueue();
	bool InitQueue();
	bool DestroyQueue();
	bool ClearQueue();
	bool QueueEmpty();
	int QueueLength();
	bool GetHead(T &e);
	bool EnQueue(T e);
	bool DeQueue(T &e);
	bool QueueTraverse(bool(*visit)(T &e));

protected:
	QNode<T> *front;
	QNode<T> *rear;
};
#endif