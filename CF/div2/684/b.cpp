#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n * k);
	for (auto& x : a) cin >> x;
	int64_t ans = 0;
	for (int i = 1; i <= k; i++) {
	  ans += a[n*k - i*(n/2+1)];
	}
	cout << ans << '\n';
  }
  return 0;
}
