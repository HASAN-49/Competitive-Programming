// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
int dis[N], par[N];

void solve() {
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(dis, -1, sizeof dis);
  queue<int> q;
  q.push(1); vis[1] = true; dis[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      if (!vis[v]) {
        q.push(v);
        par[v] = u;
        dis[v] = dis[u] + 1;
        vis[v] = true;
      }
    }
  }
  if (dis[n] == -1) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  ans.push_back(n);
  int cur = n;
  while (cur != 1) {
    cur = par[cur];
    ans.push_back(cur);
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
