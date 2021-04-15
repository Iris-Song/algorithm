#include<algorithm>
#include<climits>
template<class Type>
//单源最短路径的Dijkstra算法
//c[i][j]表示边(i,j)的权，(i,j)不存在时，c[i][j]是一个很大的数
//dist[i]表示从源到顶点的最短特殊路径长度
//prev记录i的上一个元素
//一共有n个点，下标为1-n,源点下标为v
void Dijkstra(int n,int v,Type dist[],int prev[],Type**c) 
{
	bool s[INT_MAX];
	for (int i = 1; i <= n; i++) {
		dist[i] = c[v][i];
		s[i] = false;
		if (dist[i] == INT_MAX) {
			prev[i] = 0;
		}
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++) {
		int temp = INT_MAX;
		int u = v;
		//找到最小的dist[i]
		for(int j=1;j<=n;j++)
			if (!s[i] && dist[i] < temp) {
				temp = dist[i];
				u = j;
			}
		s[u] = true;
		//更新结点
		for (int j = 1; j <= n; j++)
			if (!s[j] && c[u][j] < INT_MAX) 
				if (dist[u] + c[u][j] < dist[j])
				{
					dist[j] = dist[u] + c[u][j];
					prev[j] = u;
				}
	}

}
