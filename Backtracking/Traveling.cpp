template <class Type>
class Traveling {
	friend Type TSP(int**, int[], int,Type);
private:
	void Backtrack(int i);
	int n,//图的顶点个数
		* x,//当前解
		* bestx;//当前最优解
	Type** a,//图的邻接矩阵
		cc,//当前费用
		bestc,//当前最优值
		NoEdge;//无边标记
	
};
template <class Type>
void Traveling<Type>::Backtrack(int i)
{
	if (i == n) {
		if (a[x[n - 1]][x[n]] != NoEdge && a[x[n]][1] != NoEdge &&
			(bestc == NoEdge || cc + a[x[n - 1]][x[n]] + a[x[n]][1] < bestc)) {
			for (int j = 1; j <= n; j++) {
				bestx[j] = x[j];
			}
			bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
		}
	}
	else {
		for (int j = 1; j <= n; j++) {
			if (a[x[i - 1]][x[j]] != NoEdge && (
				bestc == NoEdge || cc + a[x[i - 1]][x[j]] < bestc
				)) {
				swap(x[i], x[j]);
				cc += a[x[i - 1]][x[j]];
				Backtrack(i + 1);
				cc -= a[x[i - 1]][x[j]];
				swap(x[i], x[j]);
			}
		}
	}
}
template <class Type>
Type TSP(int** a, int v[], int n, Type NoEdge) 
{
	Traveling<Type>Y;
	Y.n = n;
	Y.x = new int[n + 1];
	for (int i = 1; i <= n; i++)
		Y.x[i] = i;
	Y.a = a;
	Y.n = n;
	Y.bestc = NoEdge;
	Y.bestx = v;
	Y.cc = 0;
	Y.NoEdge = NoEdge;
	Y.Backtrack(2);
	delete[] Y.x;
	return Y.bestc;
}
