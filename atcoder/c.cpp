#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int a[MAX][3];
int dp[MAX][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++){
      scanf("%d", &a[i][j]);
    }
  }
  dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];
  for (int i = 1; i < n; i++) {
    dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = a[i][2] + max(dp[i-1][1], dp[i-1][0]);
  }
  printf("%d\n", max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
  return 0;
}
