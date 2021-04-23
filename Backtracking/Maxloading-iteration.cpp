template<class Type>
Type Maxloading(Type w[], Type c, int n, int bestx[]) {
	int *x = new int[n + 1];
	Type bestw = 0,cw = 0,r = 0;
	for (int i = 1; i <= n; i++)
		X.r += w[i];
	int i = 1;
	while (true) {
		while (i <= n && cw + w[i] <= c) {//进入左子树
			r -= w[i];
			cw += w[i];
			x[i] = 1;
			i++;
		}
		if (i > n) {//到达叶节点
			for (int j = 1; j <= n; j++) {
				bestx[j] = x[j];
				bestw = cw;
			}
		}
		else {//进入右子树
			r -= w[i];
			x[i] = 0;
			i++;
		}
		while (cw + r <= bestw) {//剪枝回溯
			i--;
			while (i > 0 && !x[i]) {//从右子树返回
				r += w[i];
				i--;
			}
			if (i == 0) {
				delete[] x;
				return bestw;
			}
			//进入右子树
			x[i] = 0;
			cw -= w[i];
			i++;
		}
	}
}
