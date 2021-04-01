
#include<iostream>
#include<vector>
using namespace std;

void MinMSum(vector<vector<int>>&dp, vector<int> &b,int n,int m)
{
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + b[i];
	}
	
	for (int j = 2; j <= m; j++) {
		for (int i = j; i <= n; i++) {
			int min = INT_MAX; 
			int smax;
			for (int k =  1; k < i; k++) {
				smax = max(dp[k][j - 1], dp[i][1]-dp[k][1]);
				if (min > smax)
					min = smax;
			}
			dp[i][j]=min;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	vector<int> b(n + 1);
	
	if (n < m || n <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	MinMSum(dp,b,n,m);
	cout << dp[n][m];
	return 0;
}
