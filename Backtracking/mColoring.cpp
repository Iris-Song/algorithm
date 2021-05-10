class Color {
	friend int mColoring(int, int, int**);
private:
	void Backtrack(int i);
	int n,//图的顶点个数
		m,//可用颜色数
		** a,//图的邻接矩阵
		* x,//当前解
		sum;//当前已找到的可m着色方案数
	Color(int n,int m,int **a) {
		this->n = n;
		this->m = m;
		this->a = a;
		this->x = new int[n + 1];
		this->sum = 0;
	}
	~Color() {
		delete[] this->x;
	}
};

void Color::Backtrack(int i)
{
	if (i > n) {
		sum++;
		return;
	}
	for (int j = 1; j <= n; j++) {
		x[i] = j;
		bool OK = true;
		for (int k = 1; k <= m; k++) {
			if (a[k][j] == 1 && x[k] == x[j]) {
				OK = false;
				break;
			}
		}
		if (OK) {
			Backtrack(i + 1);
		}
		x[i] = 0;
	}
}

int mColoring(int n, int m, int** a) 
{
	Color X(n, m, a);
	X.Backtrack(1);
	return X.sum;
}
