#include <iostream>


#include "ALGraph.h"
#include "Chapter3/LinkQueue.h"
template<class T>
int ALGraph<T>::LocateVex(T u)
{
	for(int i = 0; i < al_graph.vexnum; ++i)
		if(al_graph.vexs[i].data == u)
			return i;
	return -1;
}

template<class T
void CreateGraph()
{
	cout << "Input the kind of this graph" << endl;
	cout << "DG for 0, DN for 1, UDG for 2, UDN for 3" << endl;
	cin >> al_graph.kind;
	switch(al_graph.kind)
	{
		case 0: CreateDG();
				break;
		case 1: CreateDN();
				break;
		case 2: CreateUDG();
				break;
		case 3: CreateUDN();
				break;
		default:
				cout << "The kind of Graph error" <<endl;
	}
}

template<class T>
void ALGraph<T>::DestroyGraph()
{
	ArcNode *p, *q;
	for(int i = 0; i < al_graph.vexnum; ++i)
	{
		p = al_graph.vexs[i].firstarc;
		while(p)
		{
			q = p->nextarc;
			if(al_graph.kind % 2)
				delete p->info;
			delete p;
			p = q;
		}
	}
	al_graph.arcnum = 0;
	al_graph.vexnum = 0;
}

template<class T>
T ALGraph<T>::GetVex(int index)
{
	if(index < 0 || index >= al_graph.vexnum)
		throw "Out of the limited";
	return al_graph.vexs[index].data;
}

template<class T>
void ALGraph<T>::PutVex(T v, T value)
{
	int i = LocateVex(v);
	if(i < 0 )
		return;
	al_graph.vexs[i].data = value;
}

template<class T>
int FirstAdjVex(T v)
{
	int i = LocateVex(v);
	ArcNode *p = al_graph.vexs[i].firstarc;
	if(p)
		return p->adjvex;
	else
		return -1;
}

template<class T>
int NextAdjVex(T v, T w)
{
	int i = LocateVex(v);
	int j = LocateVex(w);
	ArcNode *p = al_graph.vexs[i].firstarc;
	while(p && (p->adjvex != j))
		p = p->nextarc;
	if(!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}

template<class T>
void ALGraph<T>::InsertVex(T v)
{
	if(al_graph.vexnum > MAX_VERTEX_NUM)
		return;
	if(LocateVex(v) >= 0)
		return;
	al_graph.vexs[al_graph.vexnum].data = v;
	al_graph.vexs[al_graph.vexnum].firstarc = false;
	al_graph.vexnum++;
}

template<class T>
bool ALGraph<T>::DeleteVex(T v)
{
	if(al_graph.vexnum >= MAX_VERTEX_NUM)
		return false;
	int i = LocateVex(v);
	if(i < 0)
		return false;
	ArcNode *p = al_graph.vexs[i].firstarc, q;
	while(p)
	{
		q = p;
		p = p->nextarc;
		if(al_graph.kind % 2)
			delete q->info;
		delete q;
		al_graph.arcnum--;
	}
	al_graph.vexnum--;
	for(int j = i; j < al_graph.vexnum; ++j)
		al_graph.vexs[j] = al_graph.vexs[j + 1];
	for(int j = 0; j < al_graph.vexnum; ++j)
	{
		p = al_graph.vexs[j].firstarc;
		while(p)
		{
			if(p->adjvex == j)
			{
				if(p == al_graph.vexs[j].firstarc)
				{
					al_graph.vexs[j].firstarc = p->nextarc;
					if(al_graph.kind % 2)
						delete p->info;
					delete p;;
					p = al_graph.vexs[j].firstarc;
					if(al_graph.kind < 2)
						al_graph.arcnum--;
				}
				else
				{
					q->nextarc = p->nextarc;
					if(al_graph.kind % 2)
						delete p->info;
					delete p;
					p = q->nextarc;
					if(al_graph.kind < 2)
						al_graph.arcnum--;
				}
			}
			else
			{
				if(p->adjvex > i)
					p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return true;
}

template<class T>
void ALGraph<T>::InsertArc(T v, T w)
{
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i < 0 || j < 0)
		return false;
	al_graph.arcnum++;
	int cost;
	if(al_graph.kind % 2)		//net
	{
		cout << "Input the Cost" << endl;
		cin >> cost;
	}
	ArcNode *p = new ArcNode;
	p->adjvex = j;
	p->nextarc = false;
	if(al_graph.kind % 2)		//net
	{
		p->info = new InfoType;
		*(p->info) = cost;
	}
	else						//graph
		p->info = false;
	p->nextarc = al_graph.vexs[i].firstarc;
	al_graph.vexs[i].firstarc = p;
	if(al_graph.kind > 1)		//Undirected
	{
		p = new ArcNode;
		p->adjvex = i;
		p->nextarc = false;
		if(al_graph.kind == 3)
		{
			p->info = new InfoType;
			*(p->info) = cost;
		}
		else
			p->info = false;
		p->nextarc = al_graph.vexs[j].firstarc;
		al_graph.vexs[j].firstarc = p;
	}
	return true;
}

template<class T>
void ALGraph<T>::DeleteArc(T v, T w)
{
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i < 0 || j < 0 || i == j)
		return;
	ArcNode *p = al_graph.vexs[i].firstarc;
	while(p && p->adjvex != j)
	{
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == j)
	{
		if(p == al_graph.vexs[i].firstarc)
			al_graph.vexs[i].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		if(al_graph.kind % 2)
			delete p->info;
		delete p;
		al_graph.arcnum--;
	}
	if(al_graph.kind > 1)
	{
		p = al_graph.vexs[j].firstarc;
		while(p && p->adjvex != i)
		{
			q = p;
			p = p->nextarc;
		}
	}
	if(p && p->adjvex == i)
	{
		if(p == al_graph.vexs[j].firstarc)
			al_graph.vexs[j].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		if(al_graph.kind == 3)
			delete p->info;
		delete p;
	}
}

template<class T>
void ALGraph<T>::DFS(int index)
{
	visited[index] = true;
	VisitFunc(al_graph.vexs[index].data);
	T v1 = GetVex(index);
	for(int i = FirstAdjVex(v1); i >= 0; i = NextAdjVex(v1, GetVex(i)))
		if(!visited[i])
			DFS(i);
}

template<class T>
bool DFSTraverse(bool (*visit)(T v))
{
	VisitFunc = visit;
	for(int i = 0; i <MAX_VERTEX_NUM; ++i)
		visited[i] = false;
	for(int i = 0; i < al_graph.vexnum; ++i)
		if(!visited[i])
			DFS(i);
	return true;
}

template<class T>
bool BFSTraverse(bool (*visit)(T v))
{
	LinkQueue<T> q;
	T u1;
	for(int i = 0; i < MAX_VERTEX_NUM; ++i)
		visited[i] = false;
	for(int i = 0; i < al_graph.vexnum; ++i)
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(!visit(al_graph.vexs[i].data))
				return false;
			q.EnQueue(i);
			while(!q.IsEmpty())
			{
				q.DeQueue(receive);
				u1 = GetVex(receive);
				for(int j = FirstAdjVex(u1); j >= 0; j = NextAdjVex(u1, GetVex(j)))
				{
					if(!visited[j])
					{
						visited[j] = true;
						if(!visit(al_graph.vexs[j].data))
							return false;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	return true;
}

/*-------------------------------------------------------------------------*/
/*
���ѽⷨ
����˼����������
��map��ŵ�ͼ
Ԫ��ֵΪ2��ʾ��ǽ
1��ʾ�ǵﱤ
0��ʾ�ǽֵ�
�����Ͻǵ�һ����ʼɨ��һֱɨ�赽���½����һ��λ��
�ҵ����Է��õﱤ�ĵط�Ȼ����õ�һ���ﱤ
��Ǹ�λ��Ϊ�ﱤ����λ��
Ȼ���ٴ�ͷɨ����Է��õﱤ�ĵط�
�ظ���������ֱ���Ҳ������Է��õﱤ��λ�õ�ʱ��Ϊֹ
��ans��¼���ѵ������ȼ�Ϊ���Է��õ����ﱤ��Ŀ
*/
#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include<string>
#include<algorithm>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int n, ans, map[5][5];
bool legal(int x, int y)//�жϵ�ǰλ���Ƿ�ɷ��õﱤ
{
	int i;
	//���μ����ĸ�������������˲��ɷ��õ����ֱ�ӷ��ص�ǰλ�ò�����
	//��û�������
	if (map[x][y]) return false;	//���������˵�����ǽֵ���ֻ�нֵ����Է���
	if (x>0)//up
		for (i = x - 1; i >= 1; i--)
			if (map[i][y] == 2)
				break;
			else if (map[i][y] == 1)
				return false;
	if (x<n)//down
		for (i = x + 1; i <= n; i++)
			if (map[i][y] == 2)
				break;
			else  if (map[i][y] == 1)
				return false;
	if (y>0)//left
		for (i = y - 1; i >= 1; i--)
			if (map[x][i] == 2)
				break;
			else
				if (map[x][i] == 1)
					return false;
	if (y<n)//right
		for (i = y + 1; i <= n; i++)
			if (map[x][i] == 2)
				break;
			else
				if (map[x][i] == 1)
					return false;
	return true;//�������ĸ������û�г��ֲ��ɷ��õ����
	//���λ�ÿ϶����Է���һ���ﱤ
}
void DFS(int m)//��m��¼�������
{
	int i, j;
	for (i = 1; i <= n; i++)//�����Ͻǵ�һ��λ�õ����½����һ��λ�����ν��м���
	{
		for (j = 1; j <= n; j++)
		{
			if (legal(i, j))//����ɷ��õﱤ
			{
				map[i][j] = 1;//���Ϊ�ѷ���
				DFS(m + 1);//������һ������
				map[i][j] = 0;//����ʱ�����
			}
		}
	}
	ans = (ans>m ? ans : m);//��¼����������
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j; char ch;
	while (std::cin >> n&&n)
	{
		memset(map, 0, sizeof(map));//��ʼ����ͼ
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				std::cin >> ch;
				if (ch == 'X')//���ǽ��λ��
					map[i][j] = 2;
			}
		}
		ans = 0;
		DFS(0);//�����Ϊ0��ʼ����
		std::cout << ans << endl;
	}
	return 0;
}