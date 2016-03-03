//Chapter 7 MGraph

#include <iostream>

#include "MGraph.h"
#include "Chapter3/LinkQueue.h"

template<class T>

bool visit(T v)
{
	cout << v << " ";
	return true;
}

template<class T>
void MGraph<T>::CreateGraph()
{
	cout << "Input the kind of this graph" << endl;
	cout << "DG for 0, DN for 1, UDG for 2, UDN for 3" << endl;
	cin >> m_graph.kind;
	switch(m_graph.kind)
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
				cout << "The kind of Graph error" << endl;
	}
}

template<class T>
void MGraph<T>::DestroyGraph()
{
	if(m_graph.kind < 2)					//If is Directed
	{
		for(int i = 0; i < m_graph.vexnum; i++)
			for(int j = 0; j < m_graph.vexnum; ++j)
				if(m_graph.arcs[i][j].info)
				{
					delete []m_graph.arcs[i][j].info;
					m_graph.arcs[i][j].info = false;
				}
	}
	else									//If is Undirected
	{
		for(int i = 0; i < m_graph.vexnum; ++i)
			for(int j = 0; j < m_graph.vexnum; ++j)
				if(m_graph.arcs[i][j].info)
				{
					delete []m_graph.arcs[i][j].info;
					m_graph.arcs[i][j].info = m_graph.arcs[j][i].info = false;
				}
	}
	m_graph.vexnum = 0;
	m_graph.arcnum = 0;
}

template<class T>
T MGraph<T>::GetVex(int index)
{
	if(index < 0 || index >= m_graph.vexnum)//
		return false;
	return m_graph.vexs[index];				//return the element where in the 
											//vertex table vexs[index]
}


template<class T>
int MGraph::LocateVex(T u)
{
	for(int i = 0; i < m_graph.vexnum; ++i)//Iterate all the vertex, if there is
		if(u == m_graph.vexs[i])			//a vertex == u, return its index
			return i;
	return -1;
}



template<class T>
void MGraph<T>::PutVex(T v, T value)
{
	int index = LocateVex(v);				//Get the element's index
	if(index < 0)
		return;
	m_graph.vexs[index] = value;			//set its value
}

template<class T>
bool MGraph<T>::CreateDG()
{
	cout << "Input the vexnum and arcnum of this DG" << endl;
	cin >> m_graph.vexnum >> m_graph.arcnum;
	cout << "Input every vertex" << endl;
	for(int i = 0; i < m_graph.vexnum; ++i)
		cin >> m_graph.vexs[i];
	for(int i = 0; i < m_graph.vexnum; ++i)
		for(int j = 0; j < m_graph.vexnum; ++j)
		{
			m_graph.arcs[i][j].adj = 0;
			m_graph.arcs[i][j].info = false;
		}
	T v1, v2;
	for(int i = 0; i < m_graph.arcnum; ++i)
	{
		cout << "Input the start point and the end point of an arc" << endl;
		cin >> v1 >> v2;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		m_graph.arcs[m][n].adj = 1;
	}
	m_graph.kind = DG;
	return true;
}

template<class T>
bool MGraph<T>::CreateDN()
{
	cout << "Input the vexnum and arcnum of this DN" << endl;
	cin >> m_graph.vexnum >> m_graph.arcnum;
	for(int i = 0; i < m_graph.vexnum; ++i)			//inital the graph
		for(int j = 0; j < m_graph.vexnum; ++j)
		{
			m_graph.arcs[i][j].adj = infinity;
			m_graph.arcs[i][j].info = false;
		}
	T v1, v2;
	int cost = 0;
	for(int i = 0; i < m_graph.arcnum; ++i)
	{
		cout << "Input the start/end point and cost of the arc" << endl;
		cin >> v1 >> v2 >> cost;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		m_graph.arcs[m][n].adj = cost;
	}
	m_graph.kind = DN;
	return true;
}

template<class T>
bool MGraph<T>::CreateUDG()
{
	cout << "Input the vexnum and arcnum of this UDG" << endl;
	cin >> m_graph.vexnum >> m_graph.arcnum;
	for(int i = 0; i < m_graph.vexnum; ++i)
		for(int j = 0; j < m_graph.vexnum; ++j)
		{
			m_graph.arcs[i][j].adj = 0;
			m_graph.arcs[i][j].info = false;
		}
	T v1, v2;
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		cout << "Input the start point and end point of the arc" << endl;
		cin >> v1 >> v2;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		m_graph.arcs[m][n] = 1;
		m_graph.arcs[n][m] = 1;
	}
	m_graph.kind = UDG;
	return true;
}

template<class T>
bool MGraph<T>::CreateUDN()
{
	cout << "Input the vexnum and arcnum of this UDN" << endl;
	cin >> m_graph.vexnum >> m_graph.arcnum;
	for(int i = 0; i < m_graph.vexnum; ++i)
		for(int j = 0; j < m_graph.vexnum; ++j)
		{
			m_graph.arcs[i][j].adj = infinity;
			m_graph.arcs[i][j].info = false;
		}
	int cost;
	T v1, v2;
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		cout << "Input the start/end point and cost of the arc" << endl;
		cin >> v1 >> v2 >> cost;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		m_graph.arcs[m][n].adj = cost;
		m_graph.arcs[n][m].adj = cost;
	}
	m_graph.kind = UDN;
	return true;
}

template<class T>
int MGraph<T>::FirstAdjVex(T v)
{
	int temp = LocateVex(v);
	int cost = 0;
	if(m_graph.kind == 1 || m_graph.kind = 3)
		cost = infinity;
	for(int i = 0; i < m_graph.vexnum; ++i)
		if(m_graph.arcs[temp][i] != cost)
			return i;
	return -1;
}

template<class T>
int MGraph<T>::NextAdjVex(T v, T w)		//return the vertex of v above w
{
	int id_v = LocateVex(v);
	int id_w = LocateVex(w);
	int cost = 0;
	if(m_graph.kind == 1 || m_graph.kind == 3)
		cost = infinity;
	for(int i = id_w + 1; i < m_graph.vexnum; ++i)
		if(m_graph.arcs[id_v][i] != cost)
			return i;
	return -1;
}

template<class T>
bool MGraph<T>::InsertVex(T v)
{
	if(m_graph.vexnum >= MAX_VERTEX_NUM)
		return false;
	if(LocateVex(v) >= 0)
		return false;
	m_graph.vexs[m_graph.vexnum] = v;
	for(int i = 0; i <= m_graph.vexnum; ++i)
	{
		if(m_graph.kind % 2)				//net
		{
			m_graph.arcs[m_graph.vexnum][i].adj = infinity;
			m_graph.arcs[i][m_graph.vexnum].adj = infinity;
		}
		else
		{
			m_graph.arcs[m_graph.vexnum][i].adj = 0;
			m_graph.arcs[i][m_graph.vexnum].adj = 0;
		}
		m_graph.arcs[m_graph.vexnum][i].info = false;
		m_graph.arcs[i][m_graph.vexnum].info = false;
	}
	m_graph.vexnum ++;
	return true;
}

template<class T>
bool MGraph<T>::InsertArc(T v, T w)
{
	int v1 = LocateVex(v);
	int w1 = LocateVex(w);
	if(v1 < 0 || w1 < 0)
		return false;
	m_graph.arcnum ++;
	int cost;
	if(m_graph.kind % 2)				//Net
	{
		cout << "Input the cost of this Arc" << endl;
		cin >> cost;
		m_graph.arcs[v1][w1].adj = cost;
	}
	else								//Graph
		m_graph.arcs[v1][w1].adj = 1;
	if(m_graph.kind > 1)				//Undirected net or graph
	{
		m_graph.arcs[w1][v1].adj = m_graph.[v1][w1].adj;
		m_graph.arcs[w1][v1].info = m_graph.[v1][w1].info;
	}
	return true;
}

template<class T>
bool MGraph<T>::DeleteVex(T v)
{
	int delpos = LocateVex(v);
	if(delpos < 0)						//No the vertex V
		return false;
	int vrtype =0;				
	if(m_graph.kind % 2)				//Net
		vrtype = infinity;
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		if(m_graph.arcs[i][delpos].adj != vrtype)	//There is an Arc between other Vex
		{
			if(m_graph.arcs[i][delpos].info != false)
			{
				delete [](m_graph.arcs[i][delpos].info);
				m_graph.arcs[i][delpos] = m_graph.arcs[delpos][i] = false;
			}
			m_graph.arcnum --;
		}
	}
	if(m_graph.kind < 2)				//Directed
	{
		for(int i = 0; i < m_graph.vexnum; ++i)
		{
			if(m_graph.arcs[delpos][i].adj != vrtype)
			{
				if(m_graph.arcs[delpos][i].info)
				{
					delete [](m_graph.arcs[delpos][i].info);
					m_graph.arcs[delpos][i] = false;
				}
				m_graph.arcnum --;
			}
		}
	}
	for(int i = delpos + 1; i < m_graph.vexnum; ++i)
		m_graph.vexs[i -1] = m_graph.vexs[i];
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		for(int j = delpos + 1; j < m_graph.vexnum; ++j)
			m_graph.arcs[i][j - 1] = m_graph.arcs[i][j];
	}
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		for(int j = delpos + 1; j < m_graph.vexnum; ++j)
			m_graph.arcs[j - 1][i] = m_graph.arcs[j][i];
	}
	m_graph.vexnum --;
	return true;
}

template<class T>
bool MGraph<T>::DelelteArc(T v, T w)
{
	int v1 = LocateVex(v);
	int w1 = LocateVex(w);
	if(v1 < 0 || w1 < 0)
		return false;
	if(m_graph.kind % 2 == 0)			//Graph
		m_graph.arcs[v1][w1].adj = 0;
	else
		m_graph.arcs[v1][w1].adj = infinity;
	if(m_graph.arcs[v1][w1].info)
	{
		delete []m_graph.arcs[v1][w1].info;
		m_graph.arcs[v1][w1].info = false;
	}
	if(m_graph.kind > 1)				//Undirected
	{
		m_graph.arcs[w1][v1].adj = m_graph.arcs[v1][w1].adj;
		m_graph.arcs[w1][v1].info = m_graph.arcs[v1][w1].info;
	}
	m_graph.arcnum --;
	return false;
	}
}

template<class T>
bool MGraph<T>::DFS(int index)
{
	visited[index] = true;
	//Do something
	T v1 = GetVex(index);
	for(int i = FirstAdjVex(v1); i >= 0; i = NextAdjVex(v1, GexVex(i)))
		if(!visited[i])
			DFS(i);
}

template<class T>
bool MGraph<T>::DFSTraverse(bool (*visit)(T v))
{
	VisitFunc = visit;
	for(int i = 0; i < MAX_VERTEX_NUM; ++i)
		visited[i] = false;
	for(int i = 0; i < m_graph.vexnum; ++i)
		if(!visited[i])
			DFS(i);
	return true;
}

template<class T>
bool MGraph<T>::BFSTraverse(bool (*visit)(T v))
{
	LinkQueue<int> q;
	for(int i = 0; i < MAX_VERTEX_NUM; ++i)
		visited[i] = false;
	int receive;
	T u1;
	for(int i = 0; i < m_graph.vexnum; ++i)
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(!visit(m_graph.vexs[i]))
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
						if(!visit(m_graph.vexs[j]))
							return false;
						q.EnQueue(j);
					}
				}
			}//while
		}//if
	}//for
	return true;
}



