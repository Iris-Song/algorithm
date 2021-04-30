//!Not Done yet
#include<climits>
//下标为1-n
template<class Type>
class Huffman {
	friend BinaryTree<int> HuffmanTree(Type[], int);
public:
	operator Type ()const { return weight; }
private:
	BinaryTree<int>tree;
	Type weight;
};
template<class Type>
class BinaryTree {
pubilc:

private:
	void MakeTree(int i, BinaryTree a, BinaryTree b);
};
template<class Type>
BinaryTree<int>HuffmanTree(Type f[], int n)
{
	//生成单节点树
	HuffmanTree<Type>* w = new HuffmanTree<Type>[n + 1];
	BinaryTree<int> z, zero;
	for (int i = 1; i <= n; i++) {
		z.MakeTree(i, zero, zero);
		w[i].weight = f[i];
		w[i].tree = z;
	}
	//建优先队列
	MinHeap<Huffman<Type>> Q(1);

}
