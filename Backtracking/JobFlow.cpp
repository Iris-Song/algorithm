class Flowshop {
	friend int Flow(int**, int, int[]);
private:
	void Backtrack(int i);
	int** M;//各作业所需的处理时间
	int* x;//当前作业调度
	int* bestx;//当前最优作业调度
	int* f2;//机器2完成处理时间
	int f1;//机器1完成处理时间
	int f;//完成时间和
	int bestf;//当前最优值
	int n;//作业数
};
void Flowshop::Backtrack(int i) 
{
	if (i > n) {
		for (int j = 1; i <= n; j++)
			bestx[j] = x[j];
		bestf = f;	
		return;
	}
	for (int j = i; j <= n; j++) {
		f1 += M[x[j]][1];
		f2[i] = (f2[i - 1] > f1 ? f2[i - 1] : f1) + M[x[j]][2];
		f += f2[i];
		if (f < bestf) {
			swap(x[i], x[j]);
			Backtrack(i + 1);
			swap(x[i], x[j]);
		}
		f1 -= M[x[j]][1];
		f -= f2[i];
	}
}
int Flow(int** M, int n, int bestx[]) {
	int ub = INT_MAX;
	Flowshop X;
	X.x = new int[n + 1];
	X.f2 = new int[n + 1];
	X.M = M;
	X.n = n;
	X.bestx = bestx;
	X.bestf = ub;
	X.f1 = 0;
	X.f = 0;
	for (int i = 0; i <= n; i++) {
		X.f2[i] = 0;
		X.x[i] = 1;
	}
	X.Backtrack(1);
	delete[] X.x;
	delete[] X.f2;
	return X.bestf;
}
