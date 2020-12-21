#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N, M;
  cin >> N >> M;
  string A, B;
  cin >> A >> B;
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] - 1);
      dp[i][j+1] = max(dp[i][j+1], dp[i][j] - 1);
      if (A[i] == B[j]) {
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 2);
        ans = max(ans, dp[i][j] + 2);
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
