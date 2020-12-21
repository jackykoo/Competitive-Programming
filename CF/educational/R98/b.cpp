#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> A(n);
    for (auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    long long original = sum;

    if (sum / (n - 1) < A.back()) {
      sum = A.back() * (n - 1);
    }
    while (sum % (n - 1) != 0) sum++;
    cout << sum - original << '\n';
  }
  return 0;
}
