#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, m;    
vector<pair<int, int>> g[N];

vector<long long> dijkstra(int s, vector<int> &cnt) {
  const long long inf = 1e18;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  vector<long long> d(n + 1, inf);
  vector<bool> vis(n + 1, 0);
  q.push({0, s});
  d[s] = 0;
  cnt.resize(n + 1, 0); // number of shortest paths
  cnt[s] = 1;
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    int u = x.second;
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto y: g[u]) {
      int v = y.first;
      long long w = y.second;
      if(d[u] + w < d[v]) {
        d[v] = d[u] + w;
        q.push({d[v], v});
        cnt[v] = cnt[u];
      } 
      else if(d[u] + w == d[v]) {
        cnt[v] = (cnt[v] + cnt[u]);
      }
    }
  }
  return d;
}

int u[N], v[N], w[N];
int32_t main() {
  cin >> n >> m;
  int s = 1;
  for(int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    g[u[i]].push_back({v[i], w[i]});
  }
  vector<int> cnt;
  auto d = dijkstra(s, cnt);
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << ' ';
    cout << d[i];
  }
  cout << '\n';
  return 0;
}
