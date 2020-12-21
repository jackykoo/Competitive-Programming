#include <bits/stdc++.h>

using namespace std;

vector<int64_t> A;
unordered_set<int64_t> possible;

void run(int l, int r) {
    int64_t sum = 0;
    for (int i = l; i <= r; i++) {
        sum += A[i];
    }
    possible.insert(sum);
    int64_t mid = A[l] + (A[r] - A[l]) / 2;
    int pos = -1;
    for (int i = l; i <= r; i++) {
        if (A[i] <= mid) pos = i;
        else break;
    }
    if (pos == - 1 || pos == r) return;
    run(l, pos);
    run(pos + 1, r);
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    A.clear();
    A.resize(N);
    possible.clear();
    for (auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    run(0, N - 1);
    while (Q--) {
        int64_t x;
        cin >> x;
        if (possible.find(x) != possible.end()) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
