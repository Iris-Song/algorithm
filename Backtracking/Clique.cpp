class Clique {
	int friend MaxClique(int**, int[], int);
private:
	void Backtrack(int i);
	int** a,//图G的邻接矩阵
		n,//图G的顶点数
		* x,//当前解
		* bestx,//当前最优解
		cn,//当前顶点数
		bestn;//当前最大顶点数
	
	Clique(int** a, int n,int *v) {
		this->n = n;
		this->a = a;
		this->x = new int[n + 1];
		this->cn = 0;
		this->bestn = 0;
		this->bestx = v;
	}
	~Clique()
	{
		delete[] this->x;
	}
};
void Clique::Backtrack(int i) 
{
	if (i > n) {//到达叶子节点
		for (int j = 1; j <= n; j++)
			bestx[j] = x[j];
		bestn = cn;
		return;
	}
	bool OK = true;
	for (int j = 1; j < i; j++) {
		if (x[j] && a[i][j] == 0) {
			OK = false;
			break;
		}
	}
	if (OK) {//进入左子树
		x[i] = 1;
		cn++;
		Backtrack(i + 1);
		x[i] = 0;
		cn--;
	}
	if (cn + n - i > bestn) {//在范围内 进入右子树
		x[i] = 0;
		Backtrack(i + 1);
	}
}
int MaxClique(int** a, int v[], int n) 
{
	Clique Y(a, n, v);
	Y.Backtrack(1);	
}
