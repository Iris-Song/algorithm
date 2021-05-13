class Stamp {
	friend int MaxStamp(int, int,int[]);
private:
	void Backtrack(int i,int r);
	int n,//邮票面值数
		m,//每张信封最多允许贴的邮票数
		maxvalue,//当前最优值
		maxl,//邮资上界
		* x,//当前解
		* y,//贴出各种邮资所需最少邮票数
		* bestx;//当前最优解
	Stamp(int ,int,int[]);
	~Stamp();
};
Stamp::Stamp(int n,int m,int bestx[]) {
	this->n = n;
	this->m = m;
	this->maxvalue = 0;
	this->maxl = bestx[n]*m;//假设m张最大面值
	this->bestx = bestx;
	this->x = new int[n + 1];
	this->y = new int[maxl + 1];
	for (int i = 0; i <= n; i++)x[i] = 0;
	for (int i = 1; i <= maxl; i++)y[i] = INT_MAX;
	this->x[1] = 0;
	this->y[0] = 0;
}
Stamp::~Stamp() {
	delete[] this->x;
	delete[] this->y;
}
void Stamp::Backtrack(int i,int r)
{
	for (int j = 0; j <= x[i - 2] * (m - 1); i++) 
		if (y[i] < m)
			for (int k = 1; k <= m - y[i]; k++)
				if (y[i] + k < y[j + x[i - 1] * k])
					y[j + x[i - 1] * k] = y[j] + k;
	while (y[r] < INT_MAX)r++;
	if (i > n) {
		if (r - 1 > maxvalue) {
			maxvalue = r - 1;
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];
		}
		return;
	}
	int* z = new int[maxl + 1];
	for (int k = 1; k <= maxl; k++)
		z[k] = y[k];
	for (int j = x[i - 1] + 1; j <= r; j++)
		x[i] = j;
	Backtrack(i + 1, r);
	for (int k = 1; k <= maxl; k++)
		y[k] = z[k];
	delete[] z;
}
int MaxStamp(int n, int m, int bestx[]) {
	Stamp X(n, m, bestx);
	X.Backtrack(2, 1);
	return X.maxvalue;
}
