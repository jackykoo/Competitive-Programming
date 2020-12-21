#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    long long count = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i+=2) {
      ans += ((i * 4 - 4) * count);
      count++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
