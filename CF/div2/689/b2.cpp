#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 7;

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
        vector<vector<int>> width(N, vector<int>(M, INF));

        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (A[i][j] == '*') {
                    cnt++;
                    width[i][j] = min(width[i][j], cnt);
                } else {
                    cnt = 0;
                    width[i][j] = min(width[i][j], cnt);
                }
            }
            cnt = 0;
            for (int j = M - 1; j >= 0; j--) {
                if (A[i][j] == '*') {
                    cnt++;
                    width[i][j] = min(width[i][j], cnt);
                } else {
                    cnt = 0;
                    width[i][j] = min(width[i][j], cnt);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                for (int h = i; h < N; h++) {
                    if(width[h][j] <= h - i)
                        break;
                    ans++;
                }
        
        cout << ans << '\n';
    }
    return 0;
}
