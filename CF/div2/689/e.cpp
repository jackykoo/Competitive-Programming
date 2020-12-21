#include <iostream>
#include <cassert>
 
using namespace std;
 
bool solve() {
    int64_t k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if (k + y <= r) {
        k += y;
    }
    if (y < x) {
        k -= x;
        
        if (k < l) return false;
        return t <= (k - l) / (x - y) + 1;
    }
    assert(y >= x);
    for (int64_t i = 0; i <= x; i++) {
        int64_t take = (k - l) / x;
        if (t <= take) return true;
        if (take == 0) return false;
        t -= take;
        k -= take * x;
        k += y;
        if (k > r) {
            return false;
        }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (solve()) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
