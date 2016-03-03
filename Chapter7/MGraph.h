#ifndef CHAPTER_7_MGRAPH
#define CHAPTER_7_MGRAPH

#define MAX_VERTEX_NUM	20				//顶点上限
const int infinity = INT_MAX;			//最大整数
struct ArcCell{		
	int adj;									//权或者表示是否存在相关联关系
	char *info;								//弧的相关信息
};


template<class T>
struct _MGraph{
	T vexs[MAX_VERTEX_NUM]; 			//顶点表
	ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//临接矩阵
	int vexnum;								//顶点数
	int arcnum;								//边数
	int kind;								//图的存储类型
};

typedef enum{DG, DN, UDG, UDN} GraphKind;

template<class T>
class MGraph{
private:
	_MGraph<T> m_graph;					//私有变量存储图
	bool visited[MAX_VERTEX_NUM];		//图的每个顶点是否被访问过
public:
	void CreateGraph();					//创建图
	void DestroyGraph();					//销毁图
	int LocateVex(T u);					//返回顶点u在图中的位置
	T GetVex(int index);					//返回index位置上的顶点
	void PutVex(T v, T value);			//对顶点v重新赋值
	int FirstAdjVex(T v);				//返回与v临接的第一个位置
	int NextAdjVex(T v, T w);			//
	bool InsertVex(T v);					//插入顶点
	bool DeleteVex(T v);					//删除顶点
	bool InsertArc(T v, T w);			//添加弧
	bool DeleteArc(T v, T w);			//删除弧
private:
	bool CreateDG();						//有向图
	bool CreateDN();						//有向网
	bool CreateUDG();						//无向图
	bool CreateUDN();						//无向网
	void DFS(int index);					//从index出发，深度优先遍历
public:
	bool (*VisitFunc)(T v);
	bool DFSTraverse(bool (* visit)(T v));	//深度优先遍历
	bool BFSTraverse(bool (* visit)(T v));	//广度优先遍历
};


#endif //CHAPTER_7_MGRAPH
