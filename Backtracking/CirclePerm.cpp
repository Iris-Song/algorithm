class Circle {
	friend float CirclePerm(int, float*);
private:
	void Backtrack(int i);
	float Center(int t);
	void Compute(void);
	float min,//当前最优值
		* x,//当前解
		* r;//当前圆排列
	int n;//待排列圆的个数
};
float Circle::Center(int t) 
{
	float temp = 0;
	for (int i = 1; i < t; i++) {
		float value = x[i] + 2.0 * sqrt(r[t] * r[i]);
		if (value > temp)
			temp = value;
	}
	return temp;
}
void Circle::Compute() {
	float low = 0;
	float high = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - r[i] < low)low = x[i] - r[i];
		if (x[i] + r[i] > high)high = x[i] + r[i];
	}
	if (high - low < min)
		min = high - low;
}
void Circle::Backtrack(int t)
{
	if (t > n)
		Compute();
	else {
		for (int j = t; j <= n; j++) {
			swap(r[t], r[j]);
			float center=Center(t);
			if (center + r[t] + r[1] < min) {
				x[t] = center;
				Backtrack(t + 1);
			}
			swap(r[t], r[j]);
		}
	}
}
float CirclePerm(int n, float* a) {
	Circle X;
	X.n = n;
	X.r = a;
	X.min = inf;
	float* x = new float[n + 1];
	X.x = x;
	X.Backtrack(1);
	delete[] x;
	return X.min;
}
