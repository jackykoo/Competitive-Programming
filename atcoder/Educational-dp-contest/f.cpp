#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX = 3000+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(MAX, vector<int>(MAX, 0));
  const int n = s.length();
  const int m = t.length();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1]  + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  string ans;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i-1][j]) {
      i--;
      cout << dp[i][j] << " ";
    }else if (dp[i][j] == dp[i][j-1]) {
      j--;
      cout << dp[i][j];
    }else {
      ans = s[i-1] + ans;
      i--, j--;
    }
    cout << '\n';
  }
  cout << ans << '\n';
  return 0;
}
