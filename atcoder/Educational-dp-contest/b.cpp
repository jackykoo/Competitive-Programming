#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector<int> h(N);
  for(int &x: h){
    scanf("%d", &x);
  }
  vector<int> dp(N, INF);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for ( int j = 1; j <= K; j++) {
      if (i + j < N) {
        dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }
  printf("%d\n", dp[N-1]);
  return 0;
}
