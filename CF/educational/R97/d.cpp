#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9;
int n;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> h(n, INF);
	h[0] = 0;
	int lst = 0;
	for (int i = 1; i < n; i++) {
	  if (i - 1 > 0 && a[i - 1] > a[i]) {
		lst++;
	  }
	  h[i] = h[lst] + 1;
	}
	cout << h[n-1] << '\n';
  }
  return 0;
}
