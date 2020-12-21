#include <bits/stdc++.h>

using namespace std;
unordered_set<int64_t> possible;

void dfs(const vector<int64_t>& A, const vector<int64_t>::iterator& l, const vector<int64_t>::iterator& r){

    int64_t sum = 0;
    cout << *l << " " << *r;
    return;
    //for (auto it = l; it-- != r; ++it) {
    //    cout << *it << " ";
     //   sum += *it;
    //}
    possible.insert(sum);
//    if (*l == *r) return;
    int64_t left = *l;
    int64_t right = *r;
    if (left == right) return;
    int64_t val = (left + right) / 2;
    vector<int64_t>::iterator it = upper_bound(l, r, val);
    dfs(A, l, it--);
    dfs(A, it, r);
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N);
    for (auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    dfs(A, A.begin(), A.end()--);
    while (Q--) {
        int64_t x;
        cin >> x;
        if (possible.find(x) != possible.end()) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
