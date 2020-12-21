#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    int ans = max(x, y) * 2 - 1;
    if (x == y) ans++;
    cout << ans << '\n';
  }
  return 0;
}
