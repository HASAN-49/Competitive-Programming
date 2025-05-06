// Problem Link --> https://www.codechef.com/problems/PATHETIC

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 100 + 9;
vector<int> g[N];
bool vis[N];
long long ans[N], n;
const long long x = 1269027849171992910, y = 1816798556036292277;

void dfs(int u, bool flg) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      if (flg) ans[v] = y;
      else ans[v] = x;
      dfs(v, (flg ^ 1));
    }
  }
}

void solve(int tc) {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int id = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) {
      id = i;
      break;
    }
  }
  ans[1] = x;
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    ans[i] = 0;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
