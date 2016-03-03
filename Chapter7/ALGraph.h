#ifndef CHAPTER_7_ALGRAPH
#define CHAPTER_7_ALGRAPH

#define MAX_VERTEX_NUM	20
struct ArcNode
{
	int adjvex;			//the adj vertex of this arc
	struct ArcNode *nextarc;
	InfoType *info;
};

template<class T>
struct VNode
{
	T data;
	ArcNode *firstarc;
};

template<class T>
struct _ALGraph
{
	VNode<T> vexs[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
	int kind;	//0:DG, 1:DN, 2:UDG, 3:UDN
}

template<class T>
class  ALGraph
{
public:
	void CreateGraph();
	void DestroyGraph();
	int LocateVex(T u);
	T GetVex(int index);
	void PutVex(T v, T value);
	int FirstAdjVex(T v);
	int NexAdjVex(T v, T w);
	bool InsertVex(T v);
	bool DeleteVex(T v);
	bool InsertArc(T v, T w);
	bool DeleteArc(T v, T w);
	bool (*VisitFunc)(T v);
	void DFS(int index);
	bool DFSTraverse(bool (*visit)(T v));
	bool BFSTraverse(bool (*visit)(T v));

private:
	_ALGraph<T> al_graph;
	bool visited[MAX_VERTEX_NUM];
}

#endif//CHAPTER_7_ALGRAPH

