#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define REP(i, n) for(int i = 0; i < (n); i++)
void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b) {
  return (ll) a * b % mod;
}
int n;
struct Matrix {
  vector<vector<int>> a;
  Matrix() {
    a.resize(n, vector<int>(n));
  }
  Matrix operator*(const Matrix& other) const {
    Matrix product;
    REP(i, n)
      REP(j,n)
       REP(k,n){
       add_self(product.a[i][k], mul(a[i][j],other.a[j][k]));
       }
    return product;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k;
  cin >> n >> k;
  vector<vector<int>> can(n, vector<int>(n));
  REP(i, n)
    REP(j, n)
     cin >> can[i][j];
  Matrix answer;
  REP(i, n)
    answer.a[i][i] = 1;
  Matrix m;
  m.a = can;
  while (k) {
    if(k%2) {
      answer = answer * m;
    }
    k >>= 1;
    m = m * m;
  }
  int total = 0;
  REP(i, n)
    REP(j, n)
      add_self(total, answer.a[i][j]);
  cout << total << '\n';
  return 0;
}
