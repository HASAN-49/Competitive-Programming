// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 2e5 + 5;
vector<int> g[N];
bool vis[N];
int ans[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
      ans[u] += ans[v] + 1;
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int v = 2; v <= n; v++) {
    int u; cin >> u;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
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
