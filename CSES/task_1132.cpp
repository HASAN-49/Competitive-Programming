// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int ans[N];

void dfs(int u, int p, int cnt, int &mx, int &s) {
  ans[u] = max(ans[u], cnt);
  if (cnt > mx) {
    mx = cnt;
    s = u;
  }
  for (auto v: g[u]) {
    if (v != p) {
      dfs(v, u, cnt + 1, mx, s);
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int mx = 0, s = 0, e = 0;
  dfs(1, 0, 0, mx = 0, s);
  dfs(s, 0, 0, mx = 0, e);
  dfs(e, 0, 0, mx = 0, s);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
