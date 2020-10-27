#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void add_self (int &a, int &b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W;
  cin >> H >> W;
  vector<vector<char>> sq(H+1, vector<char>(W+1));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> sq[i][j];
    }
  }
  vector<vector<int>> dp(H+1, vector<int>(W+1));
  dp[1][1] = 1;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      for ( int r : { i, i + 1}) {
        int c = j;
        if (r == i) {
          c = j + 1;
        }
        if ( r <= H && c <= W && sq[r][c] == '.') {
          add_self(dp[r][c], dp[i][j]);
        }
      }
    }
  }
  cout << dp[H][W] << '\n';
  return 0;
}
