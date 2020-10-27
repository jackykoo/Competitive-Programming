#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 7;
vector<int> edges[N];
long long dp[N][2];

void dfs(int a, int p) {
  dp[a][0] = dp[a][1] = 1;
  for (int v : edges[a]) {
    if (v != p) {
      dfs(v, a);
      dp[a][0] = dp[a][0] * ((dp[v][0] + dp[v][1]) % mod) % mod;
      dp[a][1] = dp[a][1] * dp[v][0] % mod;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1,0);
  cout << (dp[1][0] + dp[1][1]) % mod << '\n';
  return 0;
}
