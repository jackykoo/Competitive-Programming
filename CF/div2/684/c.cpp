#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      for (int j = 0; j < m; j++) {
        G[i][j] = s[j] - '0';
      }
    }

    vector<array<int, 6>> ops; ops.reserve(3*n*m);

    for (int i = n - 1; i >= 2; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (G[i][j]) {
          ops.push_back({i,j,i-1,j,i-1,j?j-1:j+1});
          G[i][j] ^= 1;
          G[i-1][j] ^=1;
          G[i-1][j?j-1:j+1] ^=1;
        }
      }
    }
    
    for (int j = m - 1; j >= 2; j--) {
      if (G[0][j] && G[1][j]) {
        ops.push_back({0,j,1,j,0,j-1});
        G[0][j] ^= 1;
        G[1][j] ^= 1;
        G[0][j-1] ^= 1;
      } else if (G[0][j]) {
        ops.push_back({0,j,0,j-1,1,j-1});
        G[0][j] ^= 1;
        G[0][j-1] ^= 1;
        G[1][j-1] ^= 1;
      } else if (G[1][j]) {
        ops.push_back({1,j,1,j-1,0,j-1});
        G[1][j] ^= 1;
        G[0][j-1] ^= 1;
        G[1][j-1] ^= 1;
      }
    }

    if (G[0][0] ^ G[0][1] ^ G[1][0]) {
      ops.push_back({0,0,0,1,1,0});
    }
    if (G[0][0] ^ G[0][1] ^ G[1][1]) {
      ops.push_back({0,0,0,1,1,1});
    }
    if (G[0][0] ^ G[1][0] ^ G[1][1]) {
      ops.push_back({0,0,1,0,1,1});
    }
    if (G[0][1] ^ G[1][0] ^ G[1][1]) {
      ops.push_back({0,1,1,0,1,1});
    }

    cout << ops.size() << '\n';
    for (auto o : ops) {
      for (int z = 0; z < 6; z++) {
        cout << o[z]+1 << " "; 
      }
      cout << '\n';
    }
  }
  return 0;
}
