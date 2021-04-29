//wij=a[i-1]+b[i]+...+b[j]+a[j]
//w(i,j)p(i,j)=w(i,j)+w(i,m-1)pl+w(m+1,j)pr
//w(i,j)p(i,j)=w(i,j)+min(w(i,k-1)p(i,k-1)+w(k-1,j)p(k+1,j))=m(i,j)

void OptimalBinarySearchTree(int *a,int *b,int n,int **m,int**s,int**w) 
{
	for (int i = 0; i <= n; i++) {
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0;
	}
	for(int r=0;r<n;r++)
		for (int i = 1; i <= n - r; i++) {
			int j = i + r;
			w[i][j] = w[i][j - 1] + a[j] + b[j];
			m[i][j] = m[i + 1][j];
			s[i][j] = i;//保存最优子树T(i,j)根节点中元素
			for (int k = i + 1; k <= j; k++) {
				int t = m[i][k - 1] + m[k + 1][j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			m[i][j] += w[i][j];
		}
}
