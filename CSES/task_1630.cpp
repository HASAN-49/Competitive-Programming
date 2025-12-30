// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;
 
void solve() {
  int n; cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto &x: vp) {
    cin >> x.first >> x.second;
  }
  sort(vp.begin(), vp.end());
  long long ans = 0, cur = 0;
  for (auto x: vp) {
    cur += x.first;
    ans += x.second - cur;
  }
  cout << ans << '\n';
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
