#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class EdgeNode {
public:
	int weight;
	int u, v;
};
EdgeNode node[1000];

vector<int> parent;

//并查集
int cmp(const void* a, const void* b)
{
	return ((EdgeNode*)a)->weight - ((EdgeNode*)b)->weight;
}

int find(int x) 
{
	//找根节点
	int root = x;
	while (root != parent[root]) 
		root = parent[root];
	return root;
}

void unite(int x, int y) 
{
	//按秩合并
	x = find(x);
	y = find(y);
	parent[y] = x;		
}

int Kruscal(int numEdge, int numPoint)
{
	int res = 0,nEdge=0;
	qsort(node, numEdge, sizeof(node[0]), cmp);
	for (int i = 0;i<numEdge&&nEdge<numPoint; i++) {
		if (find(node[i].u)!= find(node[i].v)) {
			unite(node[i].u,node[i].v);
			res += node[i].weight;
			nEdge++;
		}
	}
	if (nEdge < numPoint - 1)
		res = -1;
	return res;
}
bool range(int n,int num) 
{
	return num >= 1 && num <= n;
}
int main()
{
	int numEdge,numPoint;
	while (1) {
		cout << "please input number of edge" << endl;
		cin >> numEdge;
		if (!cin.fail())
			break;
		else {
			cin.clear();
			cin.ignore(65535,'\n');
		}
	}
	while (1) {
		cout << "please input number of point" << endl;
		cin >> numPoint;
		if (!cin.fail())
			break;
		else {
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}
	//初始化
	for (int i = 0; i < numPoint; i++) {
		parent.push_back(i);//初始时每个元素的初始父亲是自己
	}

	for (int i = 0; i < numEdge; i++) {
		cout << "please input No."<<i+1<<" :two point(1--n) of the edge & weight"<<endl;
		while (1) {
			cin >> node[i].u >> node[i].v >> node[i].weight;
			if (!cin.fail() && range(numPoint, node[i].u) && range(numPoint, node[i].v)) {
				node[i].u--;
				node[i].v--;
				break;
			}	
			else if(cin.fail()){
				cin.clear();
				cin.ignore(65535, '\n');
			}
		}
	}

	int ans = -1;
	ans = Kruscal(numEdge, numPoint);
	if (ans == -1)
		cout << "No solution" << endl;
	else
		cout << "number of min tree : " << ans;
	return 0;

}
