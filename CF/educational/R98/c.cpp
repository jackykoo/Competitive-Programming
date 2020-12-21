#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int ans = 0;
    for (int t = 0; t < 2; t++) {
      stack<char> st;
      if (t == 0) {
        for (int i = 0; i < (int)s.length(); i++) {
          if (s[i] == '[') {
            st.push(s[i]);
          }
          if (s[i] == ']' && !st.empty()) {
            st.pop();
            ans++;
          }
        }
        while (!st.empty()) st.pop();
      } else if (t == 1) {
        for (int i = 0; i < (int)s.length(); i++) {
          if (s[i] == '(') {
            st.push(s[i]);
          }
          if (s[i] == ')' && !st.empty()) {
            st.pop();
            ans++;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
