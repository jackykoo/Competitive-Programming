#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int add(int x, int y) {
  x += y;
  while(x >= MOD) x-= MOD;
  while(x < 0) x += MOD;
  return x;
}

int mul(int x, int y){
  return (x * 1LL * y) % MOD;
}

int binpow(int x, int y) {
  int ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    y >>= 1;
    x = mul(x, x);
  }
  return ans;
}

int divide(int x, int y) {
  return mul(x, binpow(y, MOD - 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 0;
  cin >> n;
  vector<int> fib(n+1);
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = add(fib[i-1], fib[i-2]);
  }
  cout << divide(fib[n], binpow(2, n)) << '\n';
  return 0;
}
