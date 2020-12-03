#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	vector<long long> mx(n+1);
	vector<long long> mn(n+1);
	for (int i = n - 1; i >= 0; i--) {
	  mx[i] = max(mx[i + 1], a[i] - mn[i + 1]);
	  mn[i] = min(mn[i + 1], a[i] - mx[i + 1]);
	} 
	cout << mx[0] << '\n';
  }
  return 0;
}
