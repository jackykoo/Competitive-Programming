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
	set<int> b;
	for (int i = 0; i < n; i++) {
	  int x;
	  cin >> x;
	  b.insert(x);
	}
	cout << (b.size() == n ? "NO" : "YES") << '\n';
  }
  return 0;
}
