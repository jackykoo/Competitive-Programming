#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int N; cin >> N;
        vector<int> A(N);
        int sum = 0;
        for (int& a : A) {
            cin >> a;
            sum += a;
        }

        for (int len = N; len >= 0; len--) {
            if (sum % len == 0) {
                bool ok = true;
                int target = sum / len;
                int cur_sum = 0;
                for (int i = 0; i < N; i++) {
                    cur_sum += A[i];
                    if (cur_sum == target) {
                        cur_sum = 0;
                    } else if (cur_sum > target){
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << N - len << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}

