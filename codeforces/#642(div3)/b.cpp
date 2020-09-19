#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int a[N], b[N];

void solve() {
  int n, k;
  int sum = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  int suma = sum;
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  sort(a, a+n);
  sort(b, b+n, greater<int>());
  for (int i = 0; i < k; i++) {
    if (b[i] > a[i]) sum = sum - a[i] + b[i];
    else continue;
  }
  if (suma > sum) printf("%d\n", suma);
  else printf("%d\n", sum);
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
