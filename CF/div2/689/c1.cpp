#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    double ans = 1.0;
    for (int i = 0; i < M ; i++) {
        int r; double p;
        cin >> r >> p;
        bool count = true;
        int n = N;
        for (int j = N - 1; j >= r; j--) {
            if (A[j] != n) {
                count = false;
                break;
            }
            n--;
        }
        if (count) {
            ans = ans * (1 - p);
        }

    }
    if (is_sorted(A.begin(), A.end())) {
        cout << 1.0 << '\n';
    } else {
        cout << 1 - ans << '\n';
    }
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
