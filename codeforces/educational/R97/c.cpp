#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p;
  cin >> p;
  while (p--) {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
	  cin >> t[i];
	  --t[i];
	}
	sort(t.begin(), t.end());
	vector<vector<int>> dp(n+1, vector<int>(2*n, INF));
	dp[0][0] = 0;
	for (int i = 0; i < n+1; i++) {
	  for (int j = 0; j < 2*n - 1; j++) {
		if (dp[i][j] < INF) {
		  if (i < n) {
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(t[i] - j));
		  }
		  dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
		}
	  }
	}
	cout << dp[n][2*n - 1] << '\n';
  }
  return 0;
}
