#include <iostream>
#include "Heap.cpp"
using namespace std;

class bbnode
{
	friend class Clique;
private:
	bbnode* parent;//point to parent node
	bool LChild;   //identify left child
};

class CliqueNode
{
	friend class Clique;
public:
	operator int() const{return un;}
private:
	int cn,			//now vertex num in clique
		un,			//now max vertex num in clique
		level;		//node level in the tree
	bbnode* ptr;	//point to alive node in tree
};

class Clique
{
	friend int main();
public:
	int BBMaxClique(int[]);
private:
	void AddLiveNode(MaxHeap<CliqueNode>& H, int cn, int un, int level, bbnode E[], bool ch);
	int** a,		//graph matrix
		n;			//graph vertex num
};

//add live node in maxheap
void Clique::AddLiveNode(MaxHeap<CliqueNode>& H, int cn, int un, int level, bbnode E[], bool ch)
{
	bbnode* b = new bbnode;
	b->parent = E;
	b->LChild = ch;
	CliqueNode N;
	N.cn = cn;
	N.ptr = b;
	N.un = un;
	N.level = level;
	H.Insert(N);
}

//解最大团问题的优先队列式分支限界法
int Clique::BBMaxClique(int bestx[])
{
	MaxHeap<CliqueNode> H(1000);

	//initialize
	bbnode* E = 0;
	int i = 1,
		cn = 0,
		bestn = 0;

	//search tree
	while (i != n + 1)//non-leaf node
	{
		//检查顶点i与当前团中其他顶点之间是否有边相连
		bool OK = true;
		bbnode* B = E;
		for (int j = i - 1; j > 0; B = B->parent, j--)
		{
			if (B->LChild && a[i][j] == 0)
			{
				OK = false;
				break;
			}
		}

		if (OK)//左儿子节点为可行结点
		{
			if (cn + 1 > bestn)
				bestn = cn + 1;
			AddLiveNode(H, cn + 1, cn + n - i + 1, i + 1, E, true);
		}

		if (cn + n - i >= bestn)//右子树可能含有最优解
		{
			AddLiveNode(H, cn, cn + n - i, i + 1, E, false);
		}

		//取下一扩展节点
		CliqueNode N;
		H.DeleteMax(N); //堆非空
		E = N.ptr;
		cn = N.cn;
		i = N.level;
	}

	//构造当前最优解
	for (int j = n; j > 0; j--)
	{
		bestx[j] = E->LChild;
		E = E->parent;
	}

	return bestn;
}


int main()
{
	cout << "Here is a program to solve MaxClique problem." << endl;
	cout << "please enter the number of vertex in your clique:" << endl;
	int num;
	while (true) {
		cin >> num;
		if (!cin.fail()) {
			break;
		}
		cout << "input is not legal.Please input again" << endl;
		cin.clear();
		rewind(stdin); 
	}
	int *bestx=new int [num+1];
	int** a = new int* [num + 1];
	for (int i = 1; i <= num; i++)
	{
		a[i] = new int[num + 1];
	}

	cout << "please input adjacent matrix(1 reprsent edge exist,0 represent not exist):" << endl;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			while (1) {
				cin >> a[i][j];
				if (!cin.fail() && (a[i][j] == 1 || a[i][j] == 0)) {
					break;
				}
				cout << "row " << i << " colum " << j << " is not legal.Please input this position again." << endl;
				cin.clear();
				rewind(stdin); 
			}
		}
	}

	Clique c;
	c.a = a;
	c.n = num;

	cout << "max num in this clique is: " << c.BBMaxClique(bestx) << endl;
	cout << "max clique solution vector is:" << endl;
	for (int i = 1; i <= num; i++)
	{
		cout << bestx[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= num; i++)
	{
		delete[] a[i];
	}
	delete[]a;
	return 0;
}


