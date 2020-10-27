#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<bool> dp(k+1);
  for (int stone = 0; stone <= k; stone++) {
    for (int &x : a) {  
      if (stone - x  >= 0 && !dp[stone-x]) {
        dp[stone] = true;
      }
    }
  }
  puts(dp[k] ? "First" : "Second");
  return 0;
}
