#include "Heap.cpp"

//用堆维护的优先队列
class Object {
	friend int Knapsack(int*, int*, int, int, int*);
public:
	int operator<=(Object a)const
	{
		return(d >= a.d);
	}
private:
	int ID;
	float d;//单位重量价值
};

class bbnode {
	friend Knap<int, int>;
	friend int Knapsack(int*, int*, int, int, int*);
private:
	bbnode* parent;//指向父节点的指针
	bool Lchild;//左儿子的结束标志
};

template<class Typew, class Typep>
class HeapNode {
	friend Knap<Typew, Typep>;
public:
	operator Typep()const { return uprofit; }
private:
	Typep uprofit,//结点的价值上界
		profit;//结点所相应的价值
	Typew weight;//节点所相应的重量
	int level;//活结点在子树中的层序号
	bbnode* ptr;//指向活结点在子集树中相应结点的指针
};

template<class Typew, class Typep>
class Knap {
	friend Typep Knapsack(Typep*, Typew*, Typew, int, int*);
public:
	Typep MaxKnapsack();
private:
	Typep Bound(int i);
	MaxHeap<HeapNode<Typew, Typep>>* H;
	void AddLiveNode(Typep up, Typep cp, Typew cw, bool ch, int level);//将一个活结点插入优先队列中
	bbnode* E;//指向扩展结点的指针
	Typew c;//背包容量
	int n;//物品总数
	Typew* w;//物品重量数组
	Typep* p;//物品价值数组,已经按单位价值递减的顺序将p，w排序
	Typew cw;//当前重量
	Type cp;//当前价值
	Typep bestp;//当前最优价值
	Typep *bestx;//当前最优解
};
template<class Typew, class Typep>
Typep Knap<Typew, Typep>::Bound(int i)
{//计算上界，贪心算法
	Typew cleft = c - cw;//剩余容量
	Typep b = cp;
	while (i <= n && w[i] <= cleft) {
		cleft -= w[i];
		b += p[i];
		i++;
	}
	if (i <= n)
		b += p[i] * cleft / w[i];
	return b;
}
template<class Typew, class Typep>
void Knap<Typew, Typep>::AddLiveNode(Typep up, Typep cp, Typew cw, bool ch, int lev) 
{//将一个新的活结点插入到子集树和优先节点中
	bbnode* b = new bbnode;
	b->parent = E;
	b->Lchild = ch;
	HeapNode<Typew, Typep> N;
	N.uprofit = up;
	N.profit = cp;
	N.weight = cw;
	N.level = lev;
	N.ptr = b;
	H->Insert(N);
}
template<class Typew,class Typep>
Typep Knap<Typew, Typep>::MaxKnapsack()
{
	//定义最大堆的容量为1000
	H = new MaxHeap<HeapNode< Typew, Typep >>(1000);
	//为bestx分配存储空间
	bestx = new int[n + 1];
	//初始化
	E = 0;
	cw = cp = 0;
	bestp = 0;
	int i = 1;
	Typew up = Bound(1);
	//搜索子集空间树
	while (i != n + 1) {//非叶节点
		//检查当前结点的左儿子结点
		Typew wt = cw + w[i];
		if (wt <= c) {
			//左儿子结点为可行结点
			if (cp + p[i] > bestp) {
				AddLiveNode(up, cp + p[i], cw + w[i], true, i + 1);
			}
			up = Bound(i + 1);
		}
		if (up >= bestp) {
			//右子树可能含最优解
			AddLiveNode(up, cp, cw, false, i + 1);
		}
		//取下一扩展结点
		HeapNode<Typew, Typep> N;
		H->DeleteMax(N);
		E = N.ptr;
		cw = N.weight;
		cp = N.profit;
		up = N.uprofit;
		i = N.level;
	}
	//构造当前最优解
	for (int j = n; j > 0; j--) {
		best[j] = E->Lchild;
		E = E->parent;
	}
	return cp;
}
template<class Typew, class Typep>
Typep Knapsack(Typep* p, Typew* w, Typew c, int n, int* bestx) {
	//返回最大价值，bestx返回最优解
	//初始化
	Typew W = 0;
	Typep P = 0;
	//定义依单位重量排序的物品数组
	Object* Q = new Object[n];
	for (int i = 1; i <= n; i++) {
		Q[i - 1].ID = i;
		Q[i - 1].d = 1.0 * p[i] / w[i];
		P += p[i];
		W += w[i];
	}
	if (W <= c)return P;//所有物品装包
	//依单位数量价值排序
	Sort(Q, n);
	//创建Knap的数据成员
	Knap<Typew, Typep>K;
	K.p = new Typep[n + 1];
	K.w = new Typew[n + 1];
	for (int i = 1; i <= n; i++) {
		K.p[i] = K.p[Q[i - 1].ID];
		K.w[i] = K.w[Q[i - 1].ID];
	}
	K.cp = 0;
	K.cw = 0;
	K.c = c;
	K.n = n;
	K.bestp = K.MaxKnapsack();
	for (int j = 1; j <= n; j++) {
		bestx[Q[j - 1].ID] = K.bestx[j];
	}
	delete[] Q;
	delete[] K.w;
	delete[] K.p;
	delete[] K.bestx;
	return K.bestp;
}
