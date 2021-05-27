#include "Heap.cpp"

template<class Type>
class Graph {
public:
	void ShortestPath(int);
	Graph(int, Type**);
	~Graph();
private:
	int n,//图G的顶点数
		* prev;//前驱顶点数组
	Type** c,//图G的邻接矩阵,若两点之间没有边，大小为inf
		* dist;//最短距离数组
};
template<class Type>
Graph<Type>::Graph(int n, Type** c) {
	this->n = n;
	this->c = c;
	prev = new int[n + 1];
	dist = new int[n + 1];
	for (int i = 0; i <= n; i++)
		dist[i] = inf;
}
template<class Type>
Graph<Type>::~Graph() {
	delete[]prev;
	delete[]dist;
}

template<class Type>
class MinHeapNode {
	friend Graph<Type>;
public:
	operator Type() const { return length; }
	MinHeapNode(int, Type);
private:
	int i;//顶点编号
	Type length;//当前路长
};
template<class Type>
MinHeapNode<Type>::MinHeapNode(int i, Type length)
{
	this->i = i;
	this->length = length;
}
template<class Type>
void Graph<Type>::ShortestPath(int v) 
{
	//v是初始扩展结点的对应下标
	MinHeap<MinHeapNode<Type>> H(1000);
	//定义源为初始扩展结点
	MinHeapNode<Type> E(v,0);
	dist[v] = 0;

	while (true) {
		for (int j = 1; j <= n; j++) {
			if (c[E.i][j] < inf&&E.length+ c[E.i][j]<dist[j]) {
				dist[j] = E.length + c[E.i][j];
				prev[j] = E.i;
				//加入活结点优先队列
				MinHeapNode<Type> N(j, dist[j]);
				H.Insert(N);
			}
			try { H.DeleteMin(E); }
			catch (OutOfBounds) { break; }
		}
	}
}
