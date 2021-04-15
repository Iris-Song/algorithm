//s数组中存储的是开始时间，f数组中存储的是结束时间，
// i号事件的开始事件为s[i]，结束时间为f[i],i的范围是1-n
//假设f已按照由小到大的顺序排列好
template<class Type>
void GreedySelector(int n,Type s[], Type f[], bool A[])
{
	A[1] = true;
	int j = 1;
	for (int i = 2; i <= n; i++) {
		if (f[j] <= s[i]) {
			A[i] = true;
			j = i;
		}
		else
			A[i] = false;
	}
}
