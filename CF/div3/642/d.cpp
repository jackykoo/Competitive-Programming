#include <bits/stdc++.h>

using namespace std;

auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb) return a.first < b.first;
    return lena > lenb;
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<pair<int,int>, decltype(cmp)> s(cmp);
    int a[n];
    memset(a, 0, sizeof(a));
    s.insert({1,n});
    int op = 0;
    for (int i = 0; i < n; i++) {
      op++;
      auto bg = *s.begin();
      s.erase(bg);
      int len = bg.second - bg.first + 1;
      if (len&1) {
        int pos = (bg.first + bg.second)/ 2;
        a[pos] = op;
        s.insert({bg.first, pos - 1});
        s.insert({pos + 1, bg.second});
      } else {
        int pos = (bg.first + bg.second - 1) / 2;
        a[pos] = op;
        s.insert({bg.first, pos - 1});
        s.insert({pos + 1, bg.second});
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  return 0;
}
