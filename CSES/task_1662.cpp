// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[i];
    pre[i + 1] %= n;
    if (pre[i + 1] < 0) pre[i + 1] += n;
  }
  map<long long, int> mp;
  long long ans = 0;
  for (auto x: pre) {
    ans += mp[x];
    mp[x] += 1;
    // cout << x << ' ' << ans << '\n';
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
