#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<ll> dp(W+1); // dp[i] the maximum value at wieght i
  for (int i = 0; i < n; i++) {
    int weight, value;
    cin >> weight >> value;
    for (int weight_already = W - weight; weight_already >= 0; weight_already--){
      dp[weight_already + weight] = max(dp[weight_already + weight], dp[weight_already] + value);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= W; i++){
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
