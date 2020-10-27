#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (n); i++)
using namespace std;
const int A = 65;


int n;
struct Matrix {
  vector<vector<unsigned int>> a  = vector<vector<unsigned int>>(A, vector<unsigned int>(A)); 
  Matrix operator *(const Matrix& other) {
    Matrix product;
    REP(i, A)
      REP(j,A)
       REP(k,A){
        product.a[i][k] += a[i][j] * other.a[j][k];
       }
    return product;
  }
};

Matrix expo_power(Matrix a, int k) {
  Matrix res;
  for (int i = 0; i < A; i++) res.a[i][i] = 1;
  while (k) {
    if (k % 2){
      res = res * a;
    }
    a = a * a;
    k /= 2;
  }
  return res;
}

bool inside(int row, int col) {
  return 0 <= min(row, col) && max(row, col) < 8;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  k++;

  Matrix single;
  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
      for (int dr : {-2, -1, 1, 2}) {
        for (int dc: {-2, -1, 1, 2}) {
          if (abs(dr) != abs(dc)) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (inside(new_row, new_col)) {
              single.a[8*row+ col][8*new_row + new_col] = 1;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i <= 64; i++) {
    single.a[i][64] = 1;
  }
  Matrix total = expo_power(single, k);
  cout << total.a[0][64] << '\n';
  return 0;
}