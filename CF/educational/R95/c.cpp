#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) {
	  cout << a[0] << '\n';
	  continue;
	}
	vector<vector<int>> dp(n, vector<int>(2, INF));
	// dp[id][player] the min skip play until id at player (0:friend 1:me)
	dp[0][0] = a[0];
	dp[0][1] = INF;
	dp[1][0] = a[0] + a[1];
	dp[1][1] = a[0];
	for (int i = 2; i < n; ++i) {
	  dp[i][0] = min(dp[i-1][1] + a[i], dp[i-2][1] + a[i] + a[i-1]);
	  dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
	}
	cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
  }
  return 0;
}
