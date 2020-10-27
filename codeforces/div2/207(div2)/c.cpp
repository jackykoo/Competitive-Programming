#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int ans[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  set<int> alive;
  for (int i = 1; i <= n; i++)
      alive.insert(i);
      
  for (int i = 0; i < m; i++) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);       
      set<int>::iterator it = alive.lower_bound(l);
      vector<int> toErase;        
      while(it != alive.end()){
          int cur = *it;            
          if(cur > r)
              break;                
          if(cur != x){    
              toErase.push_back(cur); ans[cur] = x;
          }
          it++;
      }

      for (size_t j = 0; j < toErase.size(); j++)
          alive.erase(toErase[j]);
  }
  for(int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
