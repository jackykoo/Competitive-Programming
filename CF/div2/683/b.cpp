#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
	  int N, M;
	  cin >> N >> M;
	  int mn = INT_MAX;
	  int sum = 0;
	  int num_neg = 0;
	  int num_zero = 0;
	  for (int i = 0; i < N * M; i++) {
		  int x;
		  cin >> x;
		  sum += abs(x);
		  mn = min(mn, abs(x));  
		  if (x < 0) {
			  num_neg++;
		  } else if (x == 0) {
			  num_zero++;
		  }
	  }
	  if (num_neg % 2 == 0 || num_zero == 1) {
		  cout << sum << '\n';
	  } else {
		  cout << sum - mn*2 << '\n';
	  }
  } 
  return 0;
}
