// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 2e5 + 9;
vector<int> g[N];
bool vis[N]; int dis[N];
int dp[N][2];

void dfs(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = 0;
  int id = 0;
  for (auto v: g[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0], dp[v][1]);
  }
  int mx = 0;
  for (auto v: g[u]) {
    if (v == p) continue;
    mx += max(dp[v][0], dp[v][1]);
  }
  int pre = mx;
  for (auto v: g[u]) {
    if (v == p) continue;
    mx = max(mx, pre - max(dp[v][0], dp[v][1]) + (1 + dp[v][0]));
  }
  dp[u][1] = mx;
}

void solve() {
  int n; cin >> n;;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << max(dp[1][0], dp[1][1]) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
