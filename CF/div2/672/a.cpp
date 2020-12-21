#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
	int n;
	cin >> n;
	vector<int> a(n);
	bool good = false;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	  if (i > 0 && !good) {
		good = a[i] >= a[i-1] ? true : false;
	  }
	}
	if (good || n == 1) cout << "YES\n";
	else cout << "NO\n";

  }
}
