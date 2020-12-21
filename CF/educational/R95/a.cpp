#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	int x, y, k;
	cin >> x >> y >> k;
	long long need = (long long) k * (y + 1) - 1;
	long long ans = (need + (x - 2)) / (x - 1) + k;
	cout << ans << '\n';
  }
  return 0;
}
