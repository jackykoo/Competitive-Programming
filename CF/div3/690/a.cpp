#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(auto& a : A) cin >> a;
        if (n == 1) {
            cout << A[0] << '\n';
            continue;
        }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            cout << A[l++] << " " << A[r] << " ";
            if (r - l == 1) {
                cout << A[l];
                break;
            } else {
                r--;
            } 
        }
        cout << '\n';
    }
    return 0;
}
