// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> mp;
  pair<int, int> ans = {-1, -1};
  for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    if (mp[x - val]) ans.first = mp[x - val], ans.second = i;
    mp[val] = i;
  }
  if (ans.first == -1) cout << "IMPOSSIBLE\n";
  else cout << ans.first << ' ' << ans.second << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
