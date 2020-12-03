#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b;
  vector<int> c(1, 0);
  vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    int best = -1;
    int id = -1;
    for (int j = 0; j < n; ++j) {
      if (!used[j] && __gcd(c.back(), a[j]) > best) {
        best = __gcd(c.back(), a[j]);
        id = j;
      }
    }
    b.push_back(a[id]);
    c.push_back(best);
    used[id] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << " ";
    cout << b[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
