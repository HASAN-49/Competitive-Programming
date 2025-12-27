// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, sum; cin >> n >> sum;
  vector<int> a(n);
  for (auto &x: a) {
    cin >> x;
  }
  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[i];
  }
  map<long long, int> mp;
  long long ans = 0;
  for (auto x: pre) {
    long long k = x - sum;
    ans += mp[k];
    mp[x] += 1;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
