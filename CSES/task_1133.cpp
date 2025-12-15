// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 2e5 + 9;
vector<int> g[N];
int cnt[N];
long long ans[N];

void dfs1(int u, int p, int c) {
  ans[1] += c;
  cnt[u] = 1;
  for (auto v: g[u]) {
    if (v != p) {
      dfs1(v, u, c + 1);
      cnt[u] += cnt[v];
    }
  }
}

void dfs2(int u, int p, int n) {
  for (auto v: g[u]) {
    if (v != p) {
      ans[v] += ans[u] - cnt[v] + (n - cnt[v]); // one side will be decreased by one, another side will be increased by one
      dfs2(v, u, n);
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
  dfs1(1, 0, 0);
  dfs2(1, 0, n);
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
