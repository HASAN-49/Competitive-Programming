// https://cses.fi/problemset/task/1672/

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 505;
long long inf = 1e18;
long long d[N][N];

void solve() {
  int n, m, q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        d[i][j] = inf;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c; cin >> a >> b >> c;
    d[a][b] = min(d[a][b], 1LL * c);
    d[b][a] = min(d[b][a], 1LL * c);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    int a, b; cin >> a >> b;
    if (d[a][b] == inf) cout << "-1\n";
    else cout << d[a][b] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
