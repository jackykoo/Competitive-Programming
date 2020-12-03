#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	int n;
	string s;
	cin >> n >> s;
	int cn1 = 0, cn0 = 0;
	for (int i = 1; i < n; i++) {
	  if (s[i] == s[i-1] && s[i] == '1') cn1++;
	  if (s[i] == s[i-1] && s[i] == '0') cn0++;
	}
	cout << max(cn1, cn0) << '\n';
  }
  return 0;
}
