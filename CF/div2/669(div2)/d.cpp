#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
	cin >> h[i];
  }
  vector<vector<int>> g(n);
  auto Add = [&](int x, int y) {
	g[x].push_back(y);
  };
  for (int rot = 0; rot < 2; rot++) {
	vector<int> st;
	for (int i = 0; i < n; ++i) {
	  while (!st.empty() && h[st.back()] < h[i]) {
		Add(st.back(), i);
		st.pop_back();
	  }
	  if (!st.empty()) {
		Add(st.back(), i);
		if (h[st.back()] == h[i]) {
		  st.pop_back();
		}
	  }
	  st.push_back(i);
	}
	for (int i = 0; i < n; i++) {
	  h[i] = -h[i];
	}
  }
  vector<int> dist(n, -1);
  vector<int> que(1, 0);
  dist[0] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
	for (int j : g[que[b]]) {
	  if (dist[j] == -1) {
		que.push_back(j);
		dist[j] = dist[que[b]] + 1;;
	  }
	}
  }
  cout << dist[n - 1] << '\n';
  return 0;
}
