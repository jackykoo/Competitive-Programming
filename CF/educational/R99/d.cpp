#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    auto first_val = [&]() {
      for (int i = 0; i < N; i++) {
        if (A[i] > X) {
          return i;
        }
      }
      return -1;
    };


    int ops = 0;
    while (!is_sorted(A.begin(), A.end())) {
      int i = first_val();
      if (i == -1) {
        break;
      }
      swap(A[i], X);
      ops++;
    }
    cout << (is_sorted(A.begin(), A.end()) ? ops : -1) << '\n';
  }
  return 0;
}
