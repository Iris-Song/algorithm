#include<algorithm>
template<class Type>
//装的数目越多越优
//n个物品，M大小的容量，i号物品的质量为w[i]
void loading(int n,Type M,Type w[],bool x[]) 
{
	//升序排列
	sort(w + 1, w + n);
	for (int i = 1; i <= n; i++) 
		x[i] = 0;
	for (int i = n; i >= 1; i--) {
		if (w[i] < M) {
			x[i] = 1;
			M -= w[i];
		}
		else 
			break;
	}
}
