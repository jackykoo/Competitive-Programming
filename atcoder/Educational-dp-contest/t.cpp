#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int nax = 3005;
char cmp[nax];
int dp[nax][nax], pref[nax][nax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  scanf("%d", &n);
  scanf("%s", cmp);
  dp[1][1] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i <= len - 1; ++i) {
      pref[len-1][i] = (pref[len-1][i-1] + dp[len-1][i]) % mod;
    }
    for (int b = 1; b <= len; ++b) {
      int L, R;
      if (cmp[len-2] == '<') {
        L = 1, R = b - 1;
      } else {
        L = b, R = len - 1;
      }
      if (L <= R) {
        add_self(dp[len][b], (pref[len-1][R] - pref[len-1][L-1] + mod) % mod);
      }
      //for (int i = L; i <= R; ++i) {
      //  add_self(dp[len][b], dp[len-1][i]);
      //}
      //for(int a = 1; a <= len - 1; ++a) {
      //  int real_a = a;
      //  if (a >= b) {
      //    ++real_a;
      //  }
      //  if ((real_a < b) != (cmp[len-2] == '<')) {
      //    continue;
      //  }
      //  add_self(dp[len][b], dp[len-1][a]);
      //}
    }
  }
  int answer = 0;
  for (int b = 1; b <= n; ++b) {
    add_self(answer, dp[n][b]);
  }
  cout << answer << '\n';
  return 0;
}
