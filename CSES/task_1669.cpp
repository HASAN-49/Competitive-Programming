// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N], ok = false;
vector<int> ans;
int par[N];

void dfs(int u, int pre) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (ok) return;
    if (!vis[v]) {
      par[v] = u;
      dfs(v, u);
    }
    else if (v != pre) {
      ok = true;
      ans.push_back(v);
      int x = u;
      while (x != v) {
        ans.push_back(x);
        x = par[x];
      }
      ans.push_back(x);
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
    if (!vis[i] && !ok) {
      dfs(i, 0);
    }
  }
  if (ok) {
    cout << ans.size() << '\n';
    for (auto x: ans) 
      cout << x << ' ';
    cout << '\n';
  }
  else {
    cout << "IMPOSSIBLE\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
