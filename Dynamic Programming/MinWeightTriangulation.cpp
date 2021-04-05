//凸多边形最优三角剖分
//w(i,k,j)为vi、vj、vk组成的三角形权值之和
template<class Type>
void MinWeightTriangulation(int n, Type** t) 
{
	for (int i = 1; i <= n; i++)
		t[i][i] = 0;
	for (int gap = 2; gap < n; gap++) {
		for (int i = 1; i <= n-gap; i++) {
			int j = i + gap;
			t[i][j] = t[i + 1][j] + w(i - 1, i, j);
			for (int k = i + 1; k < j; k++) {
				t[i][j] = min(t[i][j], t[i][k] + t[k + 1][j] + w(i - 1, k, j));
			}
		}
	}
}
