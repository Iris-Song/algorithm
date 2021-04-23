class Triangle {
	friend int Compute(int);
private:
	void Backtrack(int i);
	int** p;//符号三角形矩阵
	int count;//当前＋个数
	int half;//n*(n+1)/4
	int n;//第一行符号数
	long sum;//已找到的符号三角形数
};
void Triangle::Backtrack(int t)
{
	if (count > half || t * (t - 1) / 2 - count > half)
		return;
	if (t > n) {
		sum++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		p[1][t] = i;
		count += i;
		for (int j = 2; j <= t; j++) {
			p[j][t - j + 1] = p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2];
			count += p[j][t - j + 1];
		}
		Backtrack(t + 1);
		for (int j = 2; j <= t; j++) 
			count -= p[j][t - j + 1];
		count -= i;
	}
}
int Compute(int n) {
	Triangle X;
	X.n = n;
	X.half = n*(n-1)/4;
	X.count = 0;
	X.sum = 0;
	if (X.half % 2)
		return 0;
	int** p = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		p[i] = new int[n + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			p[i][j] = 0;
	X.p = p;
	X.Backtrack(1);
	delete[] X.p;
	return X.sum;
}
