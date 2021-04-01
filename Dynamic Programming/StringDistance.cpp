
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int min(int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return a;
	return c;
}
int dst(char a, char b,int k)
{
	if (a == ' ' && b == ' ') {
		return 0;
	}
	if (a == ' ' && b == ' ') {
		return k;
	}
	return abs(a - b);
}
int StringDistance(string a, string b,int k) 
{
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1));
	dp[0][0]=0;
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			if (i && j) {
				dp[i][j] = min(dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + dst(a[i], b[j], k));
			}
			else if (i) {
				dp[i][j] =dp[i - 1][j] + k;
			}
			else if (j) {
				dp[i][j] = dp[i][j-1] + k;
			}
		}
	}
	return dp[a.length()][b.length()];
}
int main()
{
	string a, b;
	cin >> a >> b;
	int k;
	cin >> k;
	cout << StringDistance(a, b, k);
}
//cmc
//snmn
//2
