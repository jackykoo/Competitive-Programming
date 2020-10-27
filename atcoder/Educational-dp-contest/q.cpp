#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
using ll = long long;
const ll sz = 1e6 + 3;

int a[sz];
int h[sz];
ll tree[4 * sz];

void update(int s, int e, int i, ll val, int idx) {
  if (s > i || e < i) {
    return;
  }
  if (s == e) {
    tree[idx] = val;
    return;
  }
  int m = s + (e - s)/2;
  update(s, m, i, val, 2 * idx);
  update(m+1, e, i, val, 2 * idx + 1);
  tree[idx] = max(tree[2*idx + 1], tree[2*idx]);
}

ll query(int s, int e, int qs, int qe, int idx) {
  if (qs > e || qe < s) return 0;
  if (s >= qs && e <= qe) return tree[idx];
  int m = s + (e - s)/2;
  ll a = query(s, m, qs, qe, idx * 2);
  ll b = query(m+1, e, qs, qe, 2 * idx + 1);
  return max(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; ll x;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> h[i];
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; i++) {
    x = query(0, n, 0, h[i] - 1, 1);
    update(0, n, h[i], x + a[i], 1);
    //cout << "x value from " << 0 << " to " << h[i] - 1 << " : " << x << '\n';
    //for (int i = 0; i < 20; i++) cout << tree[i] << " ";
    //cout << '\n';
  }
  cout << tree[1] << '\n';
  return 0;
}
