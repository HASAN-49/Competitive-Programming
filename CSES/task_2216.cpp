// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int ans = 1;
  vector<bool> vis(n + 2, 0);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (vis[x + 1]) ans++;
    vis[x] = true;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
