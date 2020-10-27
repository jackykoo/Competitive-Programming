#include <bits/stdc++.h>

using namespace std;

double dp[305][305][305];
int st[4];
int N;

double dfs(int a, int b, int c) {
  if (a+b+c == 0) return 0.0;
  if (dp[a][b][c] > -0.5)return dp[a][b][c];
  double ks = (double) N /(a+b+c);
  double ret = 0;
  if (a) {
    ret += (dfs(a-1, b, c)+ks) * a/(a+b+c);
  }
  if (b) {
    ret += (dfs(a+1, b-1, c)+ks) * b/(a+b+c);
  } 
  if (c) {
    ret += (dfs(a, b+1, c-1)+ks) * c/(a+b+c);
  }
  return dp[a][b][c] = ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a;
  cin >> a;
  N = a;
  for (int i = 0; i < a; i++) {
    int t;
    cin >> t;
    st[t]++;
  }
  memset(dp, -1, sizeof(dp));
  double ret = dfs(st[1], st[2], st[3]);
  printf("%.12f\n", ret);
  return 0;
}
