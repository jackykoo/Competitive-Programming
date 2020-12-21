#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 int t;
 scanf("%d", &t);
 while (t--) {
   int n, m;
   scanf("%d%d", &n, &m);
   printf("%d\n", min(2, n-1) * m);
 }
 return 0;
}

