#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << 1 << '\n';
      cout << 2 << '\n';
      continue;
    } else {
      cout << n << '\n';
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
