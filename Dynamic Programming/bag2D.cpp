#include<iostream>
#include<vector>
using namespace std;

int m[100][100][100] = { 0 };
int main()
{
	int n;
	int c, d;
	while (1) {
		cout << "请输入背包的容量" << endl;
		cin >> c;
		if (!cin.fail()) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(9999999, '\n');
		}
	}
	while (1) {
		cout << "请输入背包的容积" << endl;
		cin >> d;
		if (!cin.fail()) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(9999999, '\n');
		}
	}
	while (1) {
		cout << "请输入待装入的物品总数" << endl;
		cin >> n;
		if (n < 100 && !cin.fail()) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(9999999, '\n');
		}
	}
	vector<int> w(n + 1, 0);
	vector<int> b(n + 1, 0);
	vector<int> v(n + 1, 0);
	
	cout << "请依次输入" << n << "个物品的重量" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	cout << "请依次输入" << n << "个物品的体积" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	cout << "请依次输入" << n << "个物品的价值" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = n; i >= 1; i--) {
		if (i == n) {
			for (int p = 1; p <= c; p++) {
				for (int k = 1; k <= d; k++) {
					if (w[i] <= p && b[i] <= k)
						m[i][p][k] = v[i];
					else {
						m[i][p][k] = 0;
					}
				}
			}
			
		}
		else {
			for (int p = 1; p <= c; p++) {
				for (int k = 1; k <= d; k++) {
					if (w[i] <= p && b[i] <= k)
						m[i][p][k] = max(m[i + 1][p][k], m[i][p-w[i]][k-b[i]]+v[i]);
					else {
						m[i][p][k] = m[i+1][p][k];
					}
				}
			}
		}
	}
	cout << "能装进的最大价值数是";
	cout << m[1][c][d];
	return 0;
}
