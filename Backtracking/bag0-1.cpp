template<class Typew,class Typep>
class Knap {
	friend Typep Knapsack(Typep*, Typew*, Typew int);
private:
	Typep Bound(int i);
	void Backtrack(int i);
	Typew c;//背包容量
	int n;//物品树
	Typew* w;//物品重量数组
	Typep* p;//物品价值数组,已经按单位价值递减的顺序将p，w排序
	Typew cw;//当前重量
	Type cp;//当前价值
	Typep bestp;//当前最优价值
};
template<class Typew, class Typep>
void Knap<Typew, Typep>::Backtrack(int i)
{
	if (i > n) {//到达叶子结点
		bestcp = cp;
		return;
	}
	if (cw + w[i] <= c) {//进入左子树
		cw += w[i];
		cp += p[i];
		Backtrack(i + 1);
		cw -= w[i];
		cp -= p[i];
	}
	if (Bound(i + 1) > bestp) {
		//进入右子树
		Backtrack(i + 1);
	}
}
template<class Typew, class Typep>
Typep Knap<Typew, Typep>::Bound(int i) 
{//计算上界，贪心算法
	Typew cleft = c - cw;//剩余容量
	Typep b = cp;
	while (i <= n && w[i] <= cleft) {
		cleft -= w[i];
		b += p[i];
		i++;
	}
	if (i <= n)
		b += p[i] * cleft / w[i];
	return b;
}
