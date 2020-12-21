#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  using ll = long long;
  int tt;
  cin >> tt;
  while (tt--) {
	  int n; cin >> n;
	  ll W; cin >> W;
	  vector<ll> A(n); for (auto& a : A) cin >> a;
	  [&]() {
		  for (int i = 0; i < n; i++) {
			  if (A[i] * 2 >= W && A[i] <= W) {
				  cout << 1 << '\n';
				  cout << i + 1 << '\n';
				  return;
			  }
		  }

		  ll tot = 0;
		  vector<int> id;
		  for (int i = 0; i < n; i++) {
			  tot += A[i];
			  if (tot > W) {
				  tot -= A[i];
				  continue;
			  }
			  id.push_back(i);
			  if (tot * 2 >= W && tot <= W) {
				  cout << id.size() << '\n';
				  for (int z = 0; z < (int)id.size(); z++) {
					  cout << id[z] + 1 << " \n"[z+1 == (int)id.size()];
				  }
				  return;
			  }
		  }
		  cout << -1 << '\n';
	  }();
  }
  return 0;
}
