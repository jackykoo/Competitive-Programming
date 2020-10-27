#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<double> p(N+1);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  vector<vector<double>> dp(N + 1, vector<double>(N+1));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (j == 0) dp[i][j] = dp[i-1][j] * (1-p[i-1]);
      else dp[i][j] = dp[i-1][j] * (1-p[i-1]) + dp[i-1][j-1] * p[i-1];
    }
  }
  double ans = 0;
  for (int i = N; i > N /2; i--) {
    ans += dp[N][i];
  }
  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}
