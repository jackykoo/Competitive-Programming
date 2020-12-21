#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> p;
  multiset<int> d;
  auto Add = [&](int x) {
	auto ret = p.insert(x);
	assert(ret.second);
	auto it = ret.first;
	if (next(it) != p.end() && it != p.begin()) {
	  d.erase(d.find(*next(it) - *prev(it)));
	}
	if (next(it) != p.end()) {
	  d.insert(*next(it) - *it);
	}
	if (it != p.begin()) {
	  d.insert(*it - *prev(it));
	}
  };
  
  auto Remove = [&](int x) {
	auto it = p.find(x);
	assert(it != p.end());
	if (next(it) != p.end()) {
	  d.erase(d.find(*next(it) - *it));
	}
	if (it != p.begin()) {
	  d.erase(d.find(*it - *prev(it)));
	}
	if (next(it) != p.end() && it != p.begin()) {
	  d.insert(*next(it) - *prev(it));
	}
	p.erase(it);
  };

  for (int i = 0; i < n; i++) {
	int x;
	cin >> x;
	Add(x);
  }

  for (int qq = 0; qq <= q; qq++) {
	if (d.empty()) {
	  cout << 0 << '\n';
	} else {
	  int max_p = *prev(p.end());
	  int min_p = *p.begin();
	  int max_d = *prev(d.end());
	  cout << max_p - min_p - max_d << '\n';
	}
	if (qq == q) break;
	int t, x;
	cin >> t >> x;
	if (t == 0) {
	  Remove(x);
	} else {
	  Add(x);
	}
  }
  return 0;
}
