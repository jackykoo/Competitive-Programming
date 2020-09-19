#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000006;
char s[MAX];
vector<int> pre(MAX);
vector<vector<int>> dp(MAX, vector<int>(2));

int  main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
   int n, k;
   cin >> n >> k >> s+1;
   for (int i = 1; i <= n; i++) {
     pre[i] = pre[i-1] + (s[i] - '0');
   }
   /*
    * dp[i][0] = min move require in i - 1 pos with 0 at i pos;
    * dp[i][1] = min move require in i - 1 pos with 1 at i pos;
    */
   for (int i = 1; i <= n; i++) {
     int p = max(0, i - k);
     dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + (s[i] == '1');
     dp[i][1] = min(dp[p][1] + pre[i-1] - pre[p], pre[i-1]) + (s[i] == '0');
   }
   cout << min(dp[n][0], dp[n][1]) << '\n';
   for (int i = 0; i <= n; i++) dp[i][0] = dp[i][0] = pre[i] = 0;
  }
  return 0;
}
