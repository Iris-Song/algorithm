/* 1954263 ������ �ƿ� */
#include <iostream>

using namespace std;

template<class Type>
class MaxHeap
{
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() { delete[] heap; }

	int Size() const { return CurrentSize; }
	Type Max();//find max node
	MaxHeap<Type>& Insert(const Type& x); 
	MaxHeap<Type>& DeleteMax(Type& x); 

private:
	int CurrentSize, MaxSize;
	Type* heap;  // element array
};

template<class Type>
MaxHeap<Type>::MaxHeap(int MaxHeapSize)
{
	MaxSize = MaxHeapSize;
	heap = new Type[MaxSize + 1];
	CurrentSize = 0;
}
template<class Type>
Type MaxHeap<Type>::Max()
{          
	return heap[1];
}
template<class Type>
MaxHeap<Type>& MaxHeap<Type>::Insert(const Type& x)
{
	if (CurrentSize == MaxSize)
	{
		cout << "no space to insert!" << endl;
		return *this;
	}

	// find new element x's position
	// i is new element's position,find it's final positon from bottom to top
	int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2])//array digit num from 1 to start
	{
		// i is not root��its value bigger than its father��need modify
		heap[i] = heap[i / 2]; // father node down
		i /= 2;              // up to find final position
	}
	heap[i] = x;
	return *this;
}
template<class Type>
MaxHeap<Type>& MaxHeap<Type>::DeleteMax(Type& x)
{
	if (CurrentSize == 0)
	{
		cout << "empty heap!" << endl;
		return *this;
	}

	x = heap[1]; //max elem
	// get last node,modify heap from root
	Type y = heap[CurrentSize--]; 

	// find place for y starting at root
	int i = 1,  // current node of heap
		ci = 2; // child of i

	while (ci <= CurrentSize)
	{
		// ci is the bigger one child of i
		if (ci < CurrentSize && heap[ci] < heap[ci + 1])
			ci++;
		
		if (y >= heap[ci])
			break;// find right position
		
		heap[i] = heap[ci]; // bigger child up
		// next layer
		i = ci;            
		ci *= 2;
	}

	heap[i] = y;
	return *this;
}

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

//���������������ȶ���ʽ��֧�޽編
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
		//��鶥��i�뵱ǰ������������֮���Ƿ��б�����
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

		if (OK)//����ӽڵ�Ϊ���н��
		{
			if (cn + 1 > bestn)
				bestn = cn + 1;
			AddLiveNode(H, cn + 1, cn + n - i + 1, i + 1, E, true);
		}

		if (cn + n - i >= bestn)//���������ܺ������Ž�
		{
			AddLiveNode(H, cn, cn + n - i, i + 1, E, false);
		}

		//ȡ��һ��չ�ڵ�
		CliqueNode N;
		H.DeleteMax(N); //�ѷǿ�
		E = N.ptr;
		cn = N.cn;
		i = N.level;
	}

	//���쵱ǰ���Ž�
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


