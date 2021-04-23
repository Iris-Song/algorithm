/Maxloading recursive backtracking
template<class Type>
class Loading {
	friend Type Maxloading(Type[], Type, int, int[]);
private:
	void Backtrack(int i);
	int n;//集装箱数
	int* x;//当前解
	int *bestx;//当前最优解
	Type* w;//集装箱重量数组
	Type c; //第一艘轮船的载重量
	Type cw; //当前载重量
	Type bestw; //当前最优载重量
	Type r;//剩余集装箱数量
};
template<class Type>
void Loading<Type>::Backtrack(int i) 
{
	if (i > n) {
		if (cw > bestw) {
			for (int j = 1; i <= n; j++)
				bestx[j] = x[j];
			bestw = cw;
		}
		return;
	}
	//搜索子树
	r -= w[i];
	if (cw + w[i] <= c) {//搜索左子树
		x[i] = 1;
		cw += w[i];
		Backtrack(i + 1);
		cw -= w[i];
	}
	if (cw + r > bestw) {//搜索右子树
		x[i] = 0;
		Backtrack(i + 1);
	}
	r += w[i];
}
template<class Type>
Type Maxloading(Type w[], Type c, int n, int bestw[]) {
	Loading<Type> X;
	X.x = new int[n + 1];
	X.w = w;
	X.n = n;
	X.bestx = bestx;
	X.bestw = 0;
	X.cw = 0;
	X.r = 0;
	for (int i = 1; i <= n; i++)
		X.r += w[i];
	X.Backtrack(1);
	delete[] X.x;
	return X.bestw;
}
