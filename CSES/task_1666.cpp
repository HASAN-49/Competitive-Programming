// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int n; cin >> n;
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> head;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      head.push_back(i);
      dfs(i);
    }
  }
  int k = head.size();
  cout << k - 1 << '\n';
  for (int i = 1; i < k; i++) {
    cout << head[i - 1] << ' ' << head[i] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
