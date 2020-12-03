#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int mod = 998244353;
int fact[300005];
int n, k;
vector<pair<int, int>> pts;

int multi(ll a, ll b) {
  a *= b;
  a %= mod;
  return a;
}

ll pow(ll a, ll b, int mod) {
  ll res = 1;
  a = a % mod;
  while (b > 0) {
	if (b & 1) {
	  res = (res * a) % mod;
	}
	a = (a * a) % mod;
	b >>= 1;
  }
  return res;
}

ll modInverse(ll n, int mod){
  return pow(n, mod - 2, mod);
}

ll ncr(ll n, int r, int mod) {
  if ( r == 0) {
	return 1;
  }
  return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) %mod;
}

int solve() {
  int on = 0;
  ll ans = 0;
  for (int i = 0; i < (int)pts.size(); i++) {
	if (pts[i].second == 0) {
	  if (on >= k - 1) {
		ans += ncr(on, k - 1, mod);
		ans %= mod;
	  }
	  on++;
	} else {
	  on--;
	}
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  fact[0] = fact[1] = 1;
  for (int i = 1; i < 300001; i++) {
	fact[i] = multi(i, fact[i-1]);
  }
  for (int i = 0; i < n; i++) {
	int a, b;
	cin >> a >> b;
	pts.push_back({a, 0});
	pts.push_back({b, 1});
  }
  sort(pts.begin(), pts.end());
  cout << solve() << '\n';
  return 0;
}
