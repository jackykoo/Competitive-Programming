#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x; cin >> x;
        if (x > 45) {
            cout << -1 << '\n';
            continue;
        }
        int current = 9;
        string str;
        while (x > current) {
            str = char('0' + current) + str;
            x -= current;
            current--;
        }
        if (x > 0) {
            str = char('0' + x) + str;
        }
        cout << str << '\n';
    }
    return 0;
}
