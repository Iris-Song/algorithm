class Queen {
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);//递归回溯
	void Backtrack();//迭代回溯
	int n;//皇后个数
	int* x;//当前解
	long sum;//当前已找到的可行方案数
};
bool Queen::Place(int k)
{
	for (int j = 1; j < k; j++) {
		if (abs(k - j) == abs(x[j] - x[k]) || x[j] == x[k])
			return false;
	}
	return true;
}
void Queen::Backtrack(int t) 
{
	if (t > n)
		sum++;
	else {
		for (int i = 1; i <= n; i++) {
			x[t] = i;
			if (Place(t))
				Backtrack(t + 1);
		}
	}
}
void Queen::Backtrack()
{
	x[1] = 0;
	int k = 1;
	while (k > 0) {
		x[k]++;
		while (x[k] <= n && !Place(k))
			x[k]++;
		if (x[k] <= n)
			if (k == n)sum++;
			else {
				k++;
				x[k] = 0;
			}
		else
			k--;
	}
}
