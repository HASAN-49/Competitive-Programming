// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  multiset<int> se;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    auto it = se.upper_bound(x);
    if (it == se.end()) {
      ans++;
      se.insert(x);
    }
    else {
      se.erase(it);
      se.insert(x);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
