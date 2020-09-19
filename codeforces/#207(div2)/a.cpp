#include <bits/stdc++.h>

using namespace std;

int main(){
  int m, x, y, v;
  scanf("%d", &m);
  vector<int> pre(m+1, 0);
  for(int i = 1; i <= m; i++){
    scanf("%d", &v);
    pre[i] = pre[i-1] + v;
  }
  scanf("%d%d", &x, &y);
  for(int i = 1; i <= m; i++){
    if(pre[i] >= x && pre[i] <= y && pre[m] - pre[i] >= x && pre[m] - pre[i] <= y){
      printf("%d\n", i + 1);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
