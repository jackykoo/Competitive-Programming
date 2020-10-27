#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 7;
vector<int> g[MAX];
int in_deg[MAX];
int dist[MAX];
bool visited[MAX];

void dfs(int u) {
  visited[u] = true;
  for (int v : g[u]) {
    dist[v] = max(dist[v], dist[u] + 1);
    --in_deg[v];
    if (in_deg[v] == 0) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    ++in_deg[y];
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i] && in_deg[i] == 0) {
      dfs(i);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dist[i]);
  }
  cout << ans << '\n';
  return 0;
}
