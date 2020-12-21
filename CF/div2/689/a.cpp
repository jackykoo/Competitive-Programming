#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int N, K;
        cin >> N >> K;
        string s;
        int cnt = K;
        while(cnt--) {
            s += 'a';
        }
        int n = N - K;
        char a[3] = {'a', 'b', 'c'};
        for (int i = 1; i <= n; i++) {
            s += a[i % 3];
        }
        cout << s << '\n';
    }
    return 0;
}
