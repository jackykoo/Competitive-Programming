#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int N, M;
        cin >> N >> M;
        vector<string> A(N);
        for (auto& row : A) cin >> row;
        vector<vector<int>> dp(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] == '*') dp[i][j]++;
            }
        }
        for (int k = 1; k < 501; k++) {
            for (int i = 1; i < N; i++) {
                for (int j = 1; j < M - 1; j++) {
                    if (dp[i-1][j] >= k && dp[i][j-1] >= k && dp[i][j+1] >= k && dp[i][j] == k) dp[i][j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans += dp[i][j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
