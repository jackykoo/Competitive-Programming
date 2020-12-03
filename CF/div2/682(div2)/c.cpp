#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> a(n, vector<long long>(m));
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < m; j++) {
		cin >> a[i][j];
	  }
	}
	bool even = true;
	bool toggle = true;
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < m; j++) {
		if (even) {
		  if (a[i][j] % 2 == 1) {
			a[i][j] += 1;
		  }
		} else {
		  if (a[i][j] % 2 == 0) {
			a[i][j] += 1;
		  }
		}
		even = !even;
	  }
	  toggle = !toggle;
	  even = toggle;
	}
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < m; j++) {
		cout << a[i][j] << " ";
	  }
	  cout << '\n';
	}
  }
  cout << '\n';
  return 0;
}
