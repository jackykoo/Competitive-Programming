#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 300007;
ll fact[N];
ll invFact[N];


ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

ll nCr(int n, int k) {
    if (k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void run_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    for(auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(A.begin(), A.end(), A[i] + k) - A.begin();
        ans = (ans + nCr(r - l, m - 1)) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = fast_pow(fact[i], MOD - 2);
    }
    int tt; cin >> tt;
    while (tt--) {
        run_case();
    }
    return 0;
}

