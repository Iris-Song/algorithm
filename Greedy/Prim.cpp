#define maxint =1000+10;
template<class Type>

//c[i][j]表示边(i,j)的权
void Prim(int n, Type** c)
{
	Type lowcost[maxint];
	int closest[maxint];
	bool s[maxint];
	s[1] = true;
	for (int i = 2; i <= n; i++) {
		lowcost[i] = c[1][i];
		closest[i] = 1;
		s[i] = false;
	}
	for (int i = 1; i < n; i++) {
		Type min = INF;
		int j = 1;
		//找到符合要求的最小的点
		for (int k = 2; k <= n; k++) {
			if (lowcost[k] < min && !s[k]) {
				min = lowcost[k];
				j = k;
			}
		}
		cout << j << " " << closest[j] << endl;
		s[j] = true;
		//更新最小点
		for (int k = 2; k <= n; k++) {
			if (c[j][k] < lowcost[k] && !s[k]) {
				lowcost[k] = c[j][k];
				closest[k] = j;
			}
		}
	}
}
