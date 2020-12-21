#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<array<int, 2>> A(N);
    vector<int> L;
    vector<int> R;
    for (int i = 0; i < N; i++) {
        cin >> A[i][0] >> A[i][1];
        L.push_back(A[i][0]);
        R.push_back(A[i][1]);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int best = INT_MAX;
    for (int i = 0; i < N; i++) {
        int current = lower_bound(R.begin(), R.end(), A[i][0]) - R.begin();
        current += L.end() - upper_bound(L.begin(), L.end(), A[i][1]);
        best = min(best, current);
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
