#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define REP(i, n) for(int i = 0; i < (n); i++)

int n;
struct Matrix {
  vector<vector<ll>> a = vector<vector<ll>>(n, vector<ll>(n));
  Matrix operator*(const Matrix& other) {
    Matrix product;
    REP(i, n)
      REP(j,n)
       REP(k,n){
        product.a[i][k] += a[i][j] * other.a[j][k];
        product.a[i][k] %= mod;
       }
    return product;
  }
};

Matrix expo_power(Matrix a, ll k) {
  Matrix res;
  for (int i = 0; i < n; i++) res.a[i][i] = 1;
  while (k) {
    if (k % 2){
      res = res * a;
    }
    a = a * a;
    k /= 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m;
  ll k;
  cin >> n >> m >> k;
  Matrix single;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    single.a[x][y] = 1;
  }
  Matrix total = expo_power(single, k);
  ll ans = 0;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      ans = (ans + total.a[i][j]) % mod;
  cout << ans << '\n';
  return 0;
}
