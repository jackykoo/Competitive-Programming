#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define REP(i, n) for(int i = 0; i < (n); i++)

struct Matrix {
  vector<vector<double>> a;
  Matrix() {
    a.resize(2, vector<double>(2));
  }
  Matrix operator*(const Matrix& other) {
    Matrix product;
    REP(i, 2)
      REP(j,2)
       REP(k,2){
        product.a[i][k] += a[i][j] * other.a[j][k];
       }
    return product;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  double p;
  cin >> n >> p;
  vector<vector<double>> dp(2, vector<double>(2));
  dp[0][0] = 1 - p;
  dp[0][1] = p;
  dp[1][0] = p;
  dp[1][1] = 1 - p;
  
  Matrix answer;
  for (int i = 0; i < 2; i++) {
    answer.a[i][i] = 1;
  }
  Matrix m;
  m.a = dp;
  while(n) {
    if (n % 2) answer = answer * m;
    m = m * m;
    n >>= 1;
  }
  cout << fixed << setprecision(9) << answer.a[0][0] << '\n';
  return 0;
}
