// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1, 0);
  int ans = 1;
  vector<bool> vis(n + 2, 0);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[i] = x;
    mp[x] = i;
    if (vis[x + 1]) ans++;
    vis[x] = true;
  }
  mp[n + 1] = n + 1;
  // cout << ans << '\n';
  while (m--) {
    int x, y; cin >> x >> y;
    if (x == y) {
      cout << ans << '\n';
      continue;
    }
    if (x > y) swap(x, y);
    if (abs(a[x] - a[y]) == 1) {
      if (a[x] < a[y]) {
        ans++;
        if (mp[a[x] - 1] > x && mp[a[x] - 1] < y) ans--;
        if (mp[a[y] + 1] > x && mp[a[y] + 1] < y) ans--;
      }
      else {
        ans--;
        if (mp[a[x] + 1] > x && mp[a[x] + 1] < y) ans++;
        if (mp[a[y] - 1] > x && mp[a[y] - 1] < y) ans++;
      }
    }
    else {
      if (mp[a[x] - 1] > x && mp[a[x] - 1] < y) ans--;
      if (mp[a[x] + 1] > x && mp[a[x] + 1] < y) ans++;
      if (mp[a[y] - 1] > x && mp[a[y] - 1] < y) ans++;
      if (mp[a[y] + 1] > x && mp[a[y] + 1] < y) ans--;
    }
    swap(a[x], a[y]);
    mp[a[x]] = x, mp[a[y]] = y;
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
