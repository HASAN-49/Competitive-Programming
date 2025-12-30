// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, m; cin >> n >> m;
  vector<int> g[n + 1];
  int in[n + 1] = {0};
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    in[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (auto v: g[u]) {
      in[v]--;
      if (in[v] == 0) q.push(v);
    }
  }
  if (ans.size() == n) {
    for (auto x: ans) {
      cout << x << ' ';
    }
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
