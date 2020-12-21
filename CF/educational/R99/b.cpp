#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    int s = 0;
    while (s * (s + 1) / 2 < x) s++;
    if  (s * (s + 1) / 2 == x + 1) s++;
    cout << s << '\n';
  }
  return 0;
}
