#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] != '2') {
            string tmp = s.substr(n - 4, 4);
            cout << (tmp == "2020" ? "YES" : "NO") << '\n';
            continue;
        } 
        if (s[n - 1] != '0') {
            string tmp = s.substr(0, 4);
            cout << (tmp == "2020" ? "YES" : "NO") << '\n';
            continue;
        }
        string case1 = s.substr(0, 2) + s.substr(n-2, 2);
        string case2 = s.substr(0, 3) + s[n-1];
        string case3 = s.substr(0, 1) + s.substr(n-3, 3);
        if (case1 == "2020" || case2 == "2020" || case3 == "2020") {
            cout << "YES" << '\n';
        }else {
            cout << "NO" << '\n';
        }
        
    }
    return 0;
}
