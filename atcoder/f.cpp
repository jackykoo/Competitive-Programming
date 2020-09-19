#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }
  int sum_val = 0;
  for (int& v : value) sum_val += v;
  vector<ll> dp(sum_val + 1, INF); // dp[i] the minimum weight at value i
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int value_already = sum_val - value[i]; value_already >= 0; value_already--){
      dp[value_already + value[i]] = min(dp[value_already + value[i]], dp[value_already] + weight[i]);
    }
  }
  ll ans = 0;
  for (ll i = 0; i <= sum_val; i++) {
    if (dp[i] <= W) {
      ans = max(ans, i);
    }
  }
  cout << ans << '\n';
  return 0;
}
