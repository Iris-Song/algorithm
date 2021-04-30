//每个物品可以部分装进去
template<class Type>
//n个物品，M大小的容量，i号物品的价值为v[i],装入的百分比为x[i]
//假设已经按照v[i]/w[i]，由大到小的顺序将v[i],w[i]排好序
void Knapsack(int n,Type M,Type v[],Type w[],Type x[]) 
{
	int i;
	for (i = 1; i <= n; i++) 
		x[i] = 0;
	for (i = 1; i <= n; i++) {
		if (w[i] < M) {
			x[i] = 1;
			M -= w[i];
		}
		else 
			break;
	}
	if (i <= n) {
		x[i] = double(M) / double(w[i]);
	}
}
