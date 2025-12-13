// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 2e5 + 9;
vector<int> g[N];
bool vis[N];

void dfs(int u, int p, int cnt, int &mx, int &s) {
  if (cnt > mx) mx = cnt, s = u;
  for (auto v: g[u]) {
    if (v == p) continue;
    dfs(v, u, cnt + 1, mx, s);
  }
}

void solve() {
  int n; cin >> n;;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s = 0, e = 0, mx = 0;
  dfs(1, 0, 0, mx = 0, s);
  dfs(s, 0, 0, mx = 0, e);

  // cout << s << ' ' << e << '\n';
  cout << mx << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
