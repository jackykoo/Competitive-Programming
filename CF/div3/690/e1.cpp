#include <bits/stdc++.h>

using namespace std;
const int N = 300007;

uint64_t fact[N];

long long nCr(int n, int m) {
	long long res = 1;
	for (int i = 0; i < m; ++i) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}
void run_case() {
    int n, m = 3, k = 2;
    cin >> n;
    vector<int64_t> A(n);
    for(auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(A.begin(), A.end(), A[i] + k) - A.begin();
        ans = (ans + nCr(r - l, m - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        run_case();
    }
    return 0;
}

