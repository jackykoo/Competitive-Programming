#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    int need = N;
    while (need > 0 && A[need - 1] == need) {
        need--;
    }
    double ans = (need > 0 ? 1 : 0);
    for (int i = 0; i < M; i++) {
        int r; double p;
        cin >> r >> p;
        if  (r >= need) {
            ans *= (1 - p);
        }
    }
    cout << 1 - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    cout << setprecision(12) << fixed;
    while (tt--) {
        solve();
    }
    return 0;
}
