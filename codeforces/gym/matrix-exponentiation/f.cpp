#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (n); i++)
using namespace std;
const long long INF = 3e18L + 5;

int n;
struct Matrix {
	vector<vector<long long>> a = vector<vector<long long>>(n, vector<long long>(n, INF));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,n)REP(j,n)REP(k,n) {
			product.a[i][k] = min(product.a[i][k], a[i][j] + other.a[j][k]);
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,n) product.a[i][i] = 0;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, k;
  cin >> n >> m >> k;
  Matrix single;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      single.a[i][j] = INF;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    single.a[u][v] = c;
  }
  Matrix total = expo_power(single, k);
  long long answer = INF;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      answer = min(answer, total.a[i][j]);
  if (answer >= INF / 2) cout << "IMPOSSIBLE" << '\n';
  else cout << answer << '\n';
  return 0;
}
