#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;
int a[INF];
int dp[INF];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
  }
  dp[1] = 0;
  dp[2] = abs(a[1] - a[2]);
  for (int i = 3; i <= N; i++) {
    dp[i] = min(abs(a[i] - a[i-2]) + dp[i-2], abs(a[i] - a[i-1]) + dp[i-1]);
  }
  printf("%d\n", dp[N]);
  return 0;
}
