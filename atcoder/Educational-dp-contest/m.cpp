#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int>> dp(n+1, vector<int>(k+1));
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) dp[0][i] = 0;
  for (int i = 1 ; i <= n; i++){
    int sum[k+1];
    sum[0] = dp[i-1][0];
    for (int j = 1; j <= k; j++) {
      sum[j] = (sum[j-1] + dp[i-1][j]) % mod;
    }
    for (int j = 0; j <= k; j++) {
      if (j <= a[i]) {
        dp[i][j] = sum[j];
      } else {
        int non_exist = j - a[i] - 1;
        dp[i][j] = (sum[j] - sum[non_exist] + mod) % mod;
      }
    }
  }
  cout << dp[n][k] << '\n';
  return 0;
}
