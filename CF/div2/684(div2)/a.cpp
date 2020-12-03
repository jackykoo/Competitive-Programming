#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
	int n, c0, c1, h;
	cin >> n >> c0 >> c1 >> h;
	string s;
	cin >> s;
	int num0 = count(s.begin(), s.end(), '0');
	int num1 = count(s.begin(), s.end(), '1');
	int ans1 = num0 * c0 + num1 * c1;
	int ans2 = num0 * h + n * c1;
	int ans3 = num1 * h + n * c0;
	cout << min({ans1, ans2, ans3}) << '\n';
  }
  return 0;
}
