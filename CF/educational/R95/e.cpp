#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long power(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
	if (b&1) res = res * a % mod;
	a = a * a % mod;
	b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (b==0) return a;
  else return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (int i = 0; i < n; i++) { 
	cin >> d[i];
  }
  sort(d.begin(), d.end());
  vector<int> pre(n+1);
  for (int i = 0; i < n; i++) {
	pre[i+1] = (pre[i] + d[i]) % mod;
  }
  while (m--) {
	int a, b;
	cin >> a >> b;
	int k = lower_bound(d.begin(), d.end(), b) - d.begin();
	int g = max(0, n - k - a);
	int l = max(0, n - k - a + 1);
	int ans = (1ll * g * power(n - k, mod - 2) % mod * (pre[n] - pre[k] + mod) + 1ll * l * power(n - k + 1, mod - 2) % mod * pre[k]) % mod;
	cout << ans << '\n';
  }
  return 0;
}
