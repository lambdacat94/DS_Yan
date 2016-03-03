#ifndef CHAPTER3_SQSTACK
#define CHAPTER3_SQSTACK

template <typename T> class SqStack{
public:
	SqStack();
	~SqStack();

	bool InitStack();
	bool DestroyStack();
	bool ClearStack();
	bool StackEmpty();
	int StackLength();
	bool GetTop(T &e);
	int GetTop();
	bool Push(T e);
	bool Pop(T &e);
	bool StackTraverse(bool(*visit)(T));
protected:
	T *base;
	T *top;
	int stacksize;
	static const int stack_init_size = 100;
};


#endif