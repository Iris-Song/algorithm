//多边形游戏
// op[i]表示第i条边所对应的运算符，v[i]表示第i个定点上的数值
// p(i,j)表示从顶点i开始，长度为j(链中有j个顶点)的顺时针链
//设m[i,j,0]是链p(i,j)合并的最小值，m[i,j,1]是最大值
int min(int a, int b, int c, int d) {
	if (a <= b && a <= c && a <= d)
		return a;
	if (b <= a && b <= c && b <= d)
		return b;
	if (c <= a && c <= b && c <= d)
		return c;
	return d;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b, int c, int d) {
	if (a >= b && a >= c && a >= d)
		return a;
	if (b >= a && b >= c && b >= d)
		return b;
	if (c >= a && c >= b && c >= d)
		return c;
	return d;
}
int max(int a, int b) {
	return a > b ? a : b;
}
void MinMax(int n, int i, int s, int j, int& minf, int& maxf,int **m[2],int op[]) {
	int a = m[i][s][0], b = m[i][s][1];
	int r = (s + i - 1) % n + 1;
	int c = m[r][j - s][0], d = m[r][j - s][1];
	if (op[r] == '+') {
		minf = a + c;
		maxf = b + d;
	}
	else {
		minf = min(a * c, a * d, b * c, b * d);
		maxf = max(a * c, a * d, b * c, b * d);
	}
}
int PolyMax(int n,int **m[2],int op[]) {
	int minf, maxf;
	for (int j = 2; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			for (int s = 1; s < j; s++) {
				MinMax(n, i, s, j, minf, maxf, m, op);
				m[i][j][0] = min(m[i][j][0], minf);
				m[i][j][1] = max(m[i][j][1], maxf);
			}
		}
	}
	int temp = m[1][n][1];
	for (int i = 2; i <= n; i++) {
		temp = max(temp, m[i][n][1]);
	}
	return temp;
}
