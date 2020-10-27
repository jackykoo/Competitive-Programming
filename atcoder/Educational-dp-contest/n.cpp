#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18L + 5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto sum = [&](int L, int R) {
    long long s = 0;
    for (int i = L; i <= R; i++) {
      s += a[i];
    }
    return s;
  };
  vector<vector<long long>> dp(405, vector<long long>(405, INF));
  for (int L = n - 1; L >= 0; L--) {
    for (int R = L; R < n; R++) {
      if (L == R) dp[L][R] = 0;
      else {
        long long s = sum(L,R);
        for (int i = L; i <= R - 1; i++) {
          dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + s);
        }
      }
    }
  }
  cout << dp[0][n-1] << '\n';
  return 0;
}
