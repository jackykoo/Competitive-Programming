#include <bits/stdc++.h>

using namespace std;


long long nCr(int a, int b) {
    long long res = 1;
    for (int i = 0; i < b; i++) {
        res = res * (a - i) / (i + 1);
    }
    return res;
}

void run_case() {
    int N; cin >> N;
    int m = 3, k = 2;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && A[j] <= k + A[i]) j++;
        int pos = j - i - 1;
        ans += nCr(pos, m - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        run_case();

    }
    return 0;
}
