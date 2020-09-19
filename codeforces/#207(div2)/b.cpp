#include <bits/stdc++.h>

using namespace std;

int a, b, c, ans[100005];
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++){
    scanf("%d%d%d", &a, &b, &c);
    if(ans[a]){
      if(ans[a] == 3){
        ans[b] = 1, ans[c] = 2;
      }else if(ans[a] == 2){
        ans[b] = 1, ans[c] = 3;
      }else{
        ans[b] = 2, ans[c] = 3;
      }
    }else if(ans[b]){
      if(ans[b] == 3){
        ans[a] = 1, ans[c] = 2;
      }else if(ans[b] == 2){
        ans[a] = 1, ans[c] = 3;
      }else{
        ans[a] = 2, ans[c] = 3;
      }
    }else if(ans[c]){
      if(ans[c] == 3){
        ans[a] = 1, ans[b] = 2;
      }else if(ans[c] == 2){
        ans[a] = 1, ans[b] = 3;
      }else{
        ans[a] = 2, ans[b] = 3;
      }
    }else{
        ans[a] = 1, ans[b] = 2, ans[c] = 3;
    }
  }
  for(int i = 1; i <= n ; i++){
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
