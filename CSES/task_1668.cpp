// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N], ok = true;
int col[N];

void dfs(int u, int c) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (col[v] == col[u]) ok = false;
    if (!vis[v]) {
      if (col[u] == 1) {
        col[v] = 2;
        dfs(v, 2);
      }
      else {
        col[v] = 1;
        dfs(v, 1);
      }
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      col[i] = 1;
      dfs(i, 1);
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    cout << col[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
