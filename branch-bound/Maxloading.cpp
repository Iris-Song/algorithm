
template<class Type>class MaxHeap;
template<class Type>class HeapNode;

template<class Type>
class bbnode {
	friend void AddLiveNode(MaxHeap<HeapNode<int>>&, bbnode*, Type, bool, int);
	friend int MaxLoading(int*, int, int, int*);
	friend class AdjacencyGraph;
private:
	bbnode* parent;//指向父节点的指针
	bool Lchild;//左儿子的结束标志
};

template<class Type>
class HeapNode {
	friend void AddLiveNode(MaxHeap<HeapNode<int>>&, bbnode*, Type, bool, int);
	friend Type MaxLoading(Type*, Type, int, int*);
public:
	operator Type()const { return uweight; }
private:
	Type uweight;//活结点上界
	int level;//活结点在子树中的层序号
	bbnode* ptr;//指向活结点在子集树中相应结点的指针
};
template<class Type>
class MaxHeap {
	friend void AddLiveNode(MaxHeap<HeapNode<int>>&, bbnode*, Type, bool, int);
	friend Type MaxLoading(Type*, Type, int, int*);
public:
	MaxHeap(int n) {
		mh = new int[n + 1];
	}
	~MaxHeap() {
		delete[]mh;
	}
private:
	HeapNode<Type>* mh;
};

template<class Type>
void AddLiveNode(MaxHeap<HeapNode<Type>>&H,bbnode*E,Type wt,bool ch,int lev)
{
	bbnode* b = new bbnode;
	b->parent = E;
	b->Lchild = ch;
	HeapNode<Type> N;
	N.uweight = wt;
	N.level = lev;
	N.ptr = b;
	H->Insert(N);
}

template<class Type>
Type MaxLoading(Type* w, Type c, int n, int* bestx)
{
	MaxHeap<HeapNode<Type> > H(1000);
	Type* r = new Type[n + 1];//定义剩余重量数组
	r[n] = 0;
	for (int j = n-1; j > 0; j--) {
		r[j] = r[j + 1] + w[j + 1];
	}
	//初始化
	int i = 1;//当前扩展结点所处的层
	bbnode* E = 0;//当前扩展结点
	Type Ew = 0;//扩展结点所相应的载重量
	//搜索子集空间树
	while (i!=n+1)
	{
		if (Ew + w[i] <= c)
			AddLiveNode(H, E, Ew + w[i] + r[i], true, i + 1);
		AddLiveNode(H, E, Ew + r[i], false, i + 1);
		HeapNode<Type>N;
		H.DeleteMax(N);//非空
		i = N.level;
		E = N.ptr;
		Ew = N.uweight - r[i - 1];
	}
	//构造当前最优解
	for (int j = n; j > 0; j--) {
		bestx[j] = E->Lchild;
		E = E->parent;
	}
	return Ew;
}
