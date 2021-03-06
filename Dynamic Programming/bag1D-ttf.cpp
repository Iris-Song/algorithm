template<class Type>
void Traceback(int n, Type w[],Type v[],Type **p,int *head,int x[])
{
	Type j = p[head[0] - 1][0], m = p[head[0] - 1][1];
	for (int i = 1; i <= n; i++) {
		x[i] = 0;
		for (int k = head[i + 1]; k <= head[i] - 1; k++) {
			if (p[k][0] + w[i] == j && p[k][1] + v[i] == m) {
				x[i] = 1;
				j = p[k][0];
				m = p[k][1];//找到满足要求的有序对
				break;
			}
		}
	}
}
template<class Type>
Type Knapsack(int n, Type c, Type v[], Type w[], Type** p, int x[]) {
	int* head = new int[n + 2];//记录每一层的对数
	head[n + 1] = 0;
	p[0][0] = 0;
	p[0][1] = 0;
	int left = 0, right = 0, next = 1;
	head[n] = 1;
	for (int i = n; i >= 1; i--) {
		int k = left;
		for (int j = left; j <= right; j++) {
			if (p[j][0] + w[i] > c)
				break;
			Type y = p[j][0] + w[i], m = p[j][1] + v[i];
			while (k <= right&&p[k][0]<y) 
			{
				p[next][0] = p[k][0];
				p[next++][1] = p[k++][1];
			}
			if (k <= right && p[k][0] == y) {
				if (m < p[k][1])
					m = p[k][1];
				k++;
			}
			if (m > p[next - 1][1]) {
				p[next][0] = y;
				p[next++][1] = m;//最后一对价值最大
			}
			while (k <= right && p[k][1]<=p[next-1][1]) {
				k++;//使k等于价值最大的下标
			}
		}
		while (k <= right) {
			p[next][0] = p[k][0];
			p[next++][1] = p[k++][1];//使未填满的地方都是价值最大值的有序对
		}
		left = right + 1;
		right = next - 1;
		head[i - 1] = next;
	}
	Traceback(n, w, v, p, head, x);
	return p[next - 1][1];
}
